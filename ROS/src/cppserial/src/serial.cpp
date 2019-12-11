// Linux headers
#include <fcntl.h>   // Contains file controls like O_RDWR
#include <errno.h>   // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h>  // write(), read(), close()

//Ros headers
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <std_msgs/Int32.h>
#include <sstream>

#include <iostream>
#include <string>
#include <cstdlib>

std::string convertToString(char *a, int size)
{
    int i;
    std::string s = "";
    for (i = 0; i < size; i++)
    {
        s = s + a[i];
    }
    return s;
}

int main(int argc, char **argv)
{
    int serial_port = open("/dev/ttyACM0", O_RDWR);

    // Check for errors
    if (serial_port < 0)
    {
        printf("Error %i from open: %s\n", errno, strerror(errno));
    }

    // Create new termios struc, we call it 'tty' for convention
    struct termios tty;
    memset(&tty, 0, sizeof tty);

    // Read in existing settings, and handle any error
    if (tcgetattr(serial_port, &tty) != 0)
    {
        printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
    }

    tty.c_cflag &= ~PARENB; // Clear parity bit, disabling parity (most common)
    //tty.c_cflag |= PARENB;  // Set parity bit, enabling parity

    tty.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in communication (most common)
                            //tty.c_cflag |= CSTOPB;  // Set stop field, two stop bits used in communication

    /*    tty.c_cflag |= CS5; // 5 bits per byte
    tty.c_cflag |= CS6; // 6 bits per byte
    tty.c_cflag |= CS7; // 7 bits per byte*/
    tty.c_cflag |= CS8; // 8 bits per byte (most common)

    tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control (most common)
    //tty.c_cflag |= CRTSCTS;  // Enable RTS/CTS hardware flow control

    tty.c_cc[VTIME] = 1; // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
    tty.c_cc[VMIN] = 0;

    // Set in/out baud rate to be 9600
    cfsetispeed(&tty, B115200);
    cfsetospeed(&tty, B115200);

    // Save tty settings, also checking for error
    if (tcsetattr(serial_port, TCSANOW, &tty) != 0)
    {
        printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
    }

    // Allocate memory for read buffer, set size according to your needs
    char read_buf[4];
    memset(&read_buf, '\0', sizeof(read_buf));

    // Read bytes. The behaviour of read() (e.g. does it block?,
    // how long does it block for?) depends on the configuration
    // settings above, specifically VMIN and VTIME

    int num_bytes = read(serial_port, &read_buf, sizeof(read_buf));
    // n is the number of bytes read. n may be 0 if no bytes were received, and can also be -1 to signal an error.
    if (num_bytes < 0)
    {
        printf("Error reading: %s", strerror(errno));
    }

    // Here we assume we received ASCII data, but you might be sending raw bytes (in that case, don't try and
    // print it to the screen like this!)
    /*for (;;)
    {
        num_bytes = read(serial_port, &read_buf, sizeof(read_buf));
        printf("Received message: %s\n", read_buf);
    }*/

    ros::init(argc, argv, "talker");
    ros::NodeHandle n;

    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

    ros::Rate loop_rate(10);

    while (ros::ok())
    {
        num_bytes = read(serial_port, &read_buf, sizeof(read_buf));
        std::string rowdata = convertToString(read_buf, 4);

        std_msgs::String msg;
        std::stringstream ss;
        ss << " " << rowdata;
        msg.data = ss.str();
        ROS_INFO("%s", msg.data.c_str());
        chatter_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
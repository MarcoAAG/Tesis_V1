#include "ros/ros.h"
#include "serial/serial.h"
#include <sstream>
#include <iostream>
#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"
#include "std_msgs/Int32MultiArray.h"
#include <vector>
#include <string>

std::string data = "";

serial::Serial my_serial("/dev/ttyACM0", 115200);

class mg996
{
private:
    /* data */
    ros::Subscriber sub;
    serial::Serial *pMyserial = &my_serial;

public:
    uint16_t CENTROID[2];

    mg996(ros::NodeHandle *n);
    ~mg996();
    void arrayCallback(const std_msgs::Int32MultiArray::ConstPtr &array);
    void serialInit(serial::Serial *pSerial);
    void check_for_string(serial::Serial *pSerial, std::string expected_string);
    void sendData(serial::Serial *pSerial, uint16_t _x, uint16_t _y);
};

mg996::mg996(ros::NodeHandle *n)
{
    sub = n->subscribe("coordinates", 100, &mg996::arrayCallback, this);
    serialInit(&my_serial);
}

mg996::~mg996()
{
    my_serial.close();
}
void mg996::arrayCallback(const std_msgs::Int32MultiArray::ConstPtr &array)
{
    try
    {
        /**
     * ********************************************************************************
     * COORDINATES RECEIVED
     * ********************************************************************************
    **/
        int i = 0;
        for (std::vector<int>::const_iterator it = array->data.begin(); it != array->data.end(); ++it)
        {
            CENTROID[i] = *it;
            i++;
        }
        sendData(&my_serial,CENTROID[0],CENTROID[1]);
    }
    catch (const std::exception &e)
    {
        // ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg_->encoding.c_str());
        std::cerr << e.what() << '\n';
    }
}
void mg996::serialInit(serial::Serial *pSerial)
{
    pSerial->close();
    pSerial->open();
    ROS_INFO("Conectado\n");
    pSerial->flushInput();
    pSerial->flushOutput();
    pSerial->write("@");
    check_for_string(pSerial, "OK\n");
}

void mg996::check_for_string(serial::Serial *pSerial, std::string expected_string)
{
    std::string received_line = "";
    received_line = pSerial->readline();

    // std::cout << "esperando" << std::endl;
    while (received_line != expected_string)
    {
        if (pSerial->waitReadable())
        {
            received_line = pSerial->readline();
        }
    }
    ROS_INFO("%s \n", received_line.c_str());

    // std::cout << received_line << std::endl;
}

void mg996::sendData(serial::Serial *pSerial, uint16_t _x, uint16_t _y)
{
    uint16_t n = 640;
    uint8_t a;
    uint8_t b;
    std::string received_line = "";

    if (pSerial->waitReadable())
    {
        received_line = pSerial->readline();
    }
    while (received_line != "a\n")
    {
        pSerial->write("1");

        if (pSerial->waitReadable())
        {
            received_line = pSerial->readline();
        }
    }
    pSerial->write("0");
    ROS_INFO("%s \n", received_line.c_str());

    a = (uint8_t)(_y & 0x00FF);
    b = (uint8_t)(_y >> 8 & 0x00FF);
    pSerial->write((uint8_t *)&a, 1);
    // pSerial->close();
    // pSerial->open();
    pSerial->flush();
    pSerial->write((uint8_t *)&b, 1);
    pSerial->flush();
    // pSerial->close();
    // pSerial->open();
}
int main(int argc, char **argv)
{
    /**
     * ********************************************************************************
     * ROS INIT AND SUBSCRIBER
     * ********************************************************************************
    **/
    ros::init(argc, argv, "tms570lc43_serial");
    ros::NodeHandle n;
    ros::Rate loop_rate(1);
    mg996 mg = mg996(&n);
    ros::spin();

    return 0;
}
// ROS stuff
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/MultiArrayLayout.h>
#include <std_msgs/MultiArrayDimension.h>
#include <std_msgs/Int32MultiArray.h>
#include <std_msgs/Int32.h>

//Arduino stuff
#include <Servo.h>

//init Node
ros::NodeHandle nh;

//Init Servo
Servo myServo1;
Servo myServo2;

//define reference
#define referenceX 320
#define referenceY 240

//Init variables
int16_t error[2] = {0.0};
int16_t lasterror[2] = {0.0};
int16_t sumerror[2] = {0.0};

//Init gains
float Kp[2] = {0.0, 0.0};
float Ki[2] = {0.0, 0.0};
float Kd[2] = {0.0, 0.0};

//Init PID
int16_t PID[2] = {0, 0};

void callBack(const std_msgs::Int32MultiArray &array);
void control(uint16_t _X, uint16_t _Y);
bool getTurn(int16_t in);
void sendPWM(bool dir, int16_t PID, bool ID);

ros::Subscriber<std_msgs::Int32MultiArray> sub("coordinates", callBack);
std_msgs::Int32 Error;
ros::Publisher pub("PID/error", &Error);
std_msgs::Int32 u;
ros::Publisher pub_u("PID/u", &u);

void setup()
{
    nh.initNode();
    nh.subscribe(sub);
    nh.advertise(pub);
    nh.advertise(pub_u);

    //setting Servo
    /*
  *MOTOR 1 PIN 9
  *MOTOR 2 PIN 10
  */
    myServo1.attach(9);
    myServo2.attach(10);
    myServo1.writeMicroseconds(1450);
    myServo2.writeMicroseconds(1450);
}

void loop()
{
    nh.spinOnce();
    delay(1);
}

void callBack(const std_msgs::Int32MultiArray &array)
{
    nh.loginfo("recibiendo datos");
    uint16_t X;
    uint16_t Y;
    X = array.data[0];
    Y = array.data[1];
    control(X, Y);
}

void control(uint16_t _X, uint16_t _Y)
{
    bool sign1;
    bool sign2;
    //save last error
    lasterror[0] = error[0];
    lasterror[1] = error[1];

    //get new error
    error[0] = referenceX - _X;
    error[1] = referenceY - _Y;

    Error.data = error[1];
    pub.publish(&Error);

    //sum all errors
    sumerror[0] += error[0];
    sumerror[1] += error[1];

    sign1 = getTurn(error[0]);
    sign2 = getTurn(error[1]);

    Kp[0] = 1.0;
    // Kp[1] = 1.0;
    Ki[0] = 0.0;
    // Ki[1] = 0.0;
    Kd[0] = 0.0;
    // Kd[1] = 0.0;

    Kp[1] = (float)(analogRead(A0) * 3 / 1023);
    Ki[1] = (float)(analogRead(A1) * 2  / 1023);
    Kd[1] = (float)(analogRead(A2) * 50 / 1023);

    PID[0] = Kp[0] * error[0] + Kd[0] * (error[0] - lasterror[0]) + Ki[0] * sumerror[0];
    PID[1] = Kp[1] * error[1] + Kd[1] * (error[1] - lasterror[1]) + Ki[1] * sumerror[1];

    sendPWM(sign2, PID[1], 0);
}

bool getTurn(int16_t in)
{
    bool ret;
    ret = (in > 0) ? 1 : 0;
    return ret;
}
void sendPWM(bool dir, int16_t PID, bool ID)
{
    /*
    *ID 0 -> MOTOR 1
    *ID 1 -> MOTOR 2
    *dir 0 -> TURN LEFT -> NEGATIVE ERROR
    *dir 1 -> TURN  RIGHT -> POSITIVE ERROR
    */

    //u.data = dir;

    if (ID == 0)
    {
        if (dir == 0)
        {
            PID = (PID * -1) + 1542;
            PID = (PID > 1575) ? 1575 : PID;
            PID = (PID < 1542) ? 1540 : PID;
        }
        else
        {
            PID -= 1432;
            PID = (PID > 1432) ? 1433 : PID;
            PID = (PID < 1400) ? 1400 : PID;
        }

        u.data = PID;
        pub_u.publish(&u);
        myServo1.writeMicroseconds((uint32_t)PID);
    }
}

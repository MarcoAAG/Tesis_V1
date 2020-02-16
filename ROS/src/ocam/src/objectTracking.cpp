//ROS stuff
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include "std_msgs/Int32.h"
#include "std_msgs/Int32MultiArray.h"
#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"

//C++ stuff
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <math.h>

//OpenCV stuff
#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video.hpp>

using namespace cv;
using namespace std;

#define Azul 0
#define Amarillo 0
#define Rojo 1
#define Verde 0

#if Azul
int low_H = 95;
int low_S = 55;
int low_V = 55;
int high_H = 130;
int high_S = 255;
int high_V = 255;
#endif

#if Amarillo
int low_H = 25;
int low_S = 50;
int low_V = 50;
int high_H = 35;
int high_S = 255;
int high_V = 255;
#endif

#if Rojo
int low_H = 0; //165
int low_S = 70;
int low_V = 70;
int high_H = 10; //185
int high_S = 255;
int high_V = 255;
#endif

#if Verde
int low_H = 35;
int low_S = 50;
int low_V = 50;
int high_H = 90;
int high_S = 255;
int high_V = 255;
#endif

#define width 640
#define height 480

class objectTracking
{
private:
    image_transport::Subscriber sub; //Crear el suscriptor
    ros::Publisher coordinates_pub;  //Crear el publicador
    string nameOriginal = "Imagen Original";
    string nameHSV = "HSV";
    Mat ImgHSV;

public:
    Mat Img;
    int imageX = width / 2;
    int imageY = height / 2;
    objectTracking(image_transport::ImageTransport *it);
    ~objectTracking();
    void callBack(const sensor_msgs::ImageConstPtr &msg_);
    void imageViewer(Mat &Image, string _windowName);
    void rgb2hsv(Mat &_Image, Mat &Image_);
    void publishCoordinates(int _x, int _y);
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Object_tracking");
    ros::NodeHandle nh;
    image_transport::ImageTransport it(nh);
    objectTracking ot = objectTracking(&it);
    ros::spin();

    return 0;
}

objectTracking::objectTracking(image_transport::ImageTransport *it)
{
    sub = it->subscribe("ocam/Image", 1, &objectTracking::callBack, this);
}

objectTracking::~objectTracking()
{
}
void objectTracking::callBack(const sensor_msgs::ImageConstPtr &msg_)
{
    try
    {
        cv_bridge::CvImagePtr cvImg = cv_bridge::toCvCopy(msg_, "bgr8");
        Img = cvImg->image;
        rgb2hsv(Img, ImgHSV);
        imageViewer(Img, nameOriginal);
        imageViewer(ImgHSV, nameHSV);
    }
    catch (const std::exception &e)
    {
        ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg_->encoding.c_str());
    }
}
void objectTracking::imageViewer(Mat &Image, string _windowName)
{
    imshow(_windowName, Image);
    waitKey(10);
}
void objectTracking::rgb2hsv(Mat &_Image, Mat &Image_)
{
    cvtColor(_Image, Image_, COLOR_BGR2HSV);
    inRange(Image_, Scalar(low_H, low_S, low_V), Scalar(high_H, high_S, high_V), Image_);
}
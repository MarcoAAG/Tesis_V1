#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sstream>
#include <iostream>
#include <sensor_msgs/CameraInfo.h>

using namespace std;
using namespace cv;

image_transport::Publisher pub;
ros::Publisher infocam;
VideoCapture VC;
int CAMCOM;
int SAMPLETIME;
void publisher();

int main(int argc, char **argv)
{
    ros::init(argc, argv, "image_publish");
    publisher();

    return 0;
}

void publisher()
{
    ros::NodeHandle nh;
    image_transport::ImageTransport imgt(nh);

    sensor_msgs::CameraInfo camera_info_;

    camera_info_.height = 640;
    camera_info_.width = 400;
    // camera_info_.distortion_model = "plumb_bob";

    camera_info_.K[0] = 653.418544;
    camera_info_.K[1] = 0.000000;
    camera_info_.K[2] = 358.857783;
    camera_info_.K[3] = 0.000000;
    camera_info_.K[4] = 652.863595;
    camera_info_.K[5] = 235.538805;
    camera_info_.K[6] = 0.000000;
    camera_info_.K[7] = 0.000000;
    camera_info_.K[8] = 1.000000;

    // camera_info_.D[0] = -0.451566;
    // camera_info_.D[1] = 0.238355;
    // camera_info_.D[2] = -0.000850;
    // camera_info_.D[3] = -0.002483;
    // camera_info_.D[4] = 0.000000;

    // camera_info_.R[0] = 1.000000;
    // camera_info_.R[1] = 0.000000;
    // camera_info_.R[2] = 0.000000;
    // camera_info_.R[3] = 0.000000;
    // camera_info_.R[4] = 1.000000;
    // camera_info_.R[5] = 0.000000;
    // camera_info_.R[6] = 0.000000;
    // camera_info_.R[7] = 0.000000;
    // camera_info_.R[8] = 1.000000;

    camera_info_.P[0] = 575.133606;
    camera_info_.P[1] = 0.000000;
    camera_info_.P[2] = 367.129653;
    camera_info_.P[3] = 0.000000;
    camera_info_.P[4] = 0.000000;
    camera_info_.P[5] = 610.114441;
    camera_info_.P[6] = 234.605856;
    camera_info_.P[7] = 0.000000;
    camera_info_.P[8] = 0.000000;
    camera_info_.P[9] = 0.000000;
    camera_info_.P[10] = 1.000000;
    camera_info_.P[11] = 0.000000;

    nh.getParam("/com", CAMCOM);
    nh.getParam("/sampletime", SAMPLETIME);
    pub = imgt.advertise("camera/Image", 1);
    // infocam = nh.advertise<sensor_msgs::CameraInfo>("camera/Image", 1);
    VC.open(CAMCOM);
    if (!VC.isOpened())
    {
        ROS_INFO("Camara no conectada");
    }
    else
    {
        ROS_INFO("Camara conectada en el COM %d", CAMCOM);
        cv::Mat FRAME;
        sensor_msgs::ImagePtr MSG;

        ros::Rate loop_rate(SAMPLETIME); /*HZ*/

        while (nh.ok())
        {
            VC >> FRAME;
            if (!FRAME.empty())
            {
                MSG = cv_bridge::CvImage(std_msgs::Header(), "bgr8", FRAME).toImageMsg();
                pub.publish(MSG);
                cv::waitKey(30);
            }
            ros::spinOnce();
            loop_rate.sleep();
        }
    }
}
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sstream>
#include <iostream>

using namespace std;
using namespace cv;

image_transport::Publisher pub;
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
    nh.getParam("/com",CAMCOM);
    nh.getParam("/sampletime",SAMPLETIME);
    pub = imgt.advertise("camera/Image", 1);
    VC.open(CAMCOM); 
    if (!VC.isOpened())
    {
        ROS_INFO("Camara no conectada");
        //return 1;
    }
    else
    {
        ROS_INFO("Camara conectada en el COM %d",CAMCOM);
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
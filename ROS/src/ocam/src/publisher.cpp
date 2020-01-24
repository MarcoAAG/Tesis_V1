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

void publisher(int COM, int Sample_Time)
{
    ros::NodeHandle nh;
    image_transport::ImageTransport imgt(nh);
    pub = imgt.advertise("camera/Image", 1);
    VC.open(COM); 
    if (!VC.isOpened())
    {
        ROS_INFO("Camara no conectada");
        //return 1;
    }
    else
    {
        ROS_INFO("Camara conectada en el COM %d",COM);
        cv::Mat FRAME;
        sensor_msgs::ImagePtr MSG;

        ros::Rate loop_rate(Sample_Time); /*HZ*/

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

int main(int argc, char **argv)
{
    ros::init(argc, argv, "image_publish");
    publisher(2, 1000);

    return 0;
}
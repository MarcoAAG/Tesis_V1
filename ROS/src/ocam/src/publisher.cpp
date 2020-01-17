#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sstream>
#include <iostream>
//#include <vector>
#include <stdio.h>

using namespace std;
using namespace cv;

class publisher
{
private:
    /* data */
public:
    publisher(/* args */);
    publisher(int COM, int Sample_Time);
    ~publisher();
};

publisher::publisher(/* args */)
{
}

publisher::~publisher()
{
}
publisher::publisher(int COM, int Sample_time)
{
    int COMCAM;
    ros::NodeHandle NH;
    image_transport::ImageTransport IT(NH);
    image_transport::Publisher PUB = IT.advertise("camera/Image", 1);
    

    VideoCapture VC;
    NH.param("camara", COMCAM, 0);
    VC.open(COMCAM); /* OCAM device  */
    if (!VC.isOpened())
    {
        cout << "ERROR: Camara no conectada" << endl;
        //return 1;
    }
    else
    {
        cout << "Camara conectada en el COM " << COMCAM << endl;
        cv::Mat FRAME;
        sensor_msgs::ImagePtr MSG;

        ros::Rate loop_rate(Sample_time); /*HZ*/

        while (NH.ok())
        {
            VC >> FRAME;
            if (!FRAME.empty())
            {
                MSG = cv_bridge::CvImage(std_msgs::Header(), "bgr8", FRAME).toImageMsg();
                PUB.publish(MSG);
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
    publisher PUBCAM(2, 1000);

    return 0;
}
//ROS stuff
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include "std_msgs/Int32.h"
#include "std_msgs/Int32MultiArray.h"
#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"

//OpenCV stuff
#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video.hpp>

using namespace cv;
using namespace std;

image_transport::Subscriber sub; //Crear el suscriptor
image_transport::Subscriber sub2; //Crear el suscriptor
string topicName;

void imageCallback(const sensor_msgs::ImageConstPtr &msg_)
{

    /* code */
    cv_bridge::CvImagePtr cvimg = cv_bridge::toCvCopy(msg_, "bgr8");
    Mat img;
    img = cvimg->image;
    imshow("Original", img); //show the original image
    cv::waitKey(10);
}
void imageCallback2(const sensor_msgs::ImageConstPtr &msg_)
{

    /* code */
    cv_bridge::CvImagePtr cvimg = cv_bridge::toCvCopy(msg_, "bgr8");
    Mat img;
    img = cvimg->image;
    imshow("Calibrada", img); //show the original image
    cv::waitKey(10);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "image_listener");
    ros::NodeHandle nh;
    image_transport::ImageTransport it(nh);
    nh.getParam("topicName", topicName);
    sub = it.subscribe(topicName, 1, imageCallback2);
    sub2 = it.subscribe("/my_camera/image_raw", 1, imageCallback);
    ros::spin();
    return 0;
}
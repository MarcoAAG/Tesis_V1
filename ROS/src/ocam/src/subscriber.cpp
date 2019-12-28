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

image_transport::Subscriber sub;
const string windowName = "View";

void imageCallback(const sensor_msgs::ImageConstPtr &msg_)
{
    cv_bridge::CvImagePtr cvimg = cv_bridge::toCvCopy(msg_, "bgr8");
    try
    {
        cv::imshow(windowName, cvimg->image);
        cv::waitKey(10);
    }
    catch (cv_bridge::Exception &e)
    {
        ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg_->encoding.c_str());
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "image_listener");
    ros::NodeHandle nh;
    image_transport::ImageTransport it(nh);
    sub = it.subscribe("camera/Image", 1, imageCallback);
    ros::spin();
    return 0;
}
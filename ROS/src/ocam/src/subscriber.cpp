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

#define HSV_valores 0

//Capture a temporary image from the camera
cv::Mat imgOriginal;
cv::Mat imgHSV;
cv::Mat imgthreshold;

cv::Mat imgErosion;
cv::Mat imgDilation;

const String window_capture_name = "Video Capture";
const String window_detection_name = "Object Detection";

image_transport::Subscriber sub;
/*----------------------------------------      HSV     ----------------------------------------*/

#if HSV_valores
/* code */
const int max_value_H = 360 / 2;
const int max_value = 255;
int low_H = 0, low_S = 0, low_V = 0;
int high_H = max_value_H, high_S = max_value, high_V = max_value;
#else
int low_H = 110;
int low_S = 55;
int low_V = 55;
int high_H = 130;
int high_S = 255;
int high_V = 255;
#endif

/*----------------------------------------      Morphological operation     ----------------------------------------*/
/// Global variables
cv::Mat dst_opening;

int morph_elem = 0;
int morph_size = 0;
int morph_operator_opening = 0;
int morph_operator_closing = 1;
int const max_operator = 4;
int const max_elem = 2;
int const max_kernel_size = 21;

const String window_opening = "Morphology Transformations Opening";

/** Function Headers */
void Morphology_Operations_Opening(int, void *);

#if HSV_valores
static void on_low_H_thresh_trackbar(int, void *)
{
    low_H = min(high_H - 1, low_H);
    setTrackbarPos("Low H", window_detection_name, low_H);
}
static void on_high_H_thresh_trackbar(int, void *)
{
    high_H = max(high_H, low_H + 1);
    setTrackbarPos("High H", window_detection_name, high_H);
}
static void on_low_S_thresh_trackbar(int, void *)
{
    low_S = min(high_S - 1, low_S);
    setTrackbarPos("Low S", window_detection_name, low_S);
}
static void on_high_S_thresh_trackbar(int, void *)
{
    high_S = max(high_S, low_S + 1);
    setTrackbarPos("High S", window_detection_name, high_S);
}
static void on_low_V_thresh_trackbar(int, void *)
{
    low_V = min(high_V - 1, low_V);
    setTrackbarPos("Low V", window_detection_name, low_V);
}
static void on_high_V_thresh_trackbar(int, void *)
{
    high_V = max(high_V, low_V + 1);
    setTrackbarPos("High V", window_detection_name, high_V);
}
#endif


void imageCallback(const sensor_msgs::ImageConstPtr &msg_)
{
    cv_bridge::CvImagePtr cvimg = cv_bridge::toCvCopy(msg_, "bgr8");

    try
    {
        imgOriginal = cvimg->image;
        namedWindow(window_capture_name);
        namedWindow(window_detection_name);

#if HSV_valores
        // Trackbars to set thresholds for HSV values
        //para azules : low = ([110,50,50])  high ([130,255,255])
        createTrackbar("Low H", window_detection_name, &low_H, max_value_H, on_low_H_thresh_trackbar);
        createTrackbar("High H", window_detection_name, &high_H, max_value_H, on_high_H_thresh_trackbar);
        createTrackbar("Low S", window_detection_name, &low_S, max_value, on_low_S_thresh_trackbar);
        createTrackbar("High S", window_detection_name, &high_S, max_value, on_high_S_thresh_trackbar);
        createTrackbar("Low V", window_detection_name, &low_V, max_value, on_low_V_thresh_trackbar);
        createTrackbar("High V", window_detection_name, &high_V, max_value, on_high_V_thresh_trackbar);
#endif

        cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV);

        inRange(imgHSV, Scalar(low_H, low_S, low_V), Scalar(high_H, high_S, high_V), imgthreshold);
        // Show the frames
        imshow(window_capture_name, imgOriginal);
        imshow(window_detection_name, imgthreshold);

        /// Create window
        namedWindow(window_opening, CV_WINDOW_AUTOSIZE);

        /// Create Trackbar to select kernel type
        createTrackbar("Element:\n 0: Rect - 1: Cross - 2: Ellipse", window_opening,
                       &morph_elem, max_elem,
                       Morphology_Operations_Opening);

        /// Create Trackbar to choose kernel size
        createTrackbar("Kernel size:\n 2n +1", window_opening,
                       &morph_size, max_kernel_size,
                       Morphology_Operations_Opening);

        /// Default start
        Morphology_Operations_Opening(0, 0);

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

void Morphology_Operations_Opening(int, void *)
{
    // Since MORPH_X : 2,3,4,5 and 6
    int operation = morph_operator_opening + 2;

    Mat element = getStructuringElement(morph_elem, Size(2 * morph_size + 1, 2 * morph_size + 1), Point(morph_size, morph_size));

    /// Apply the specified morphology operation
    morphologyEx(imgthreshold, dst_opening, operation, element);
    imshow(window_opening, dst_opening);
}
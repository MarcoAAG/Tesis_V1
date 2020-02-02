#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main(int argc, char **argv)
{
    Mat image;
    Mat imgHSV;
    image = imread(("../../Tesis/ROS/src/ocam/src/newplot.png"), IMREAD_COLOR);

    if (image.empty()) // Check for invalid input
    {
        cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    // PRUEBAS AMARILLO
    // int low_H = 25;
    // int low_S = 50;
    // int low_V = 50;
    // int high_H = 32;
    // int high_S = 255;
    // int high_V = 255;

    int low_H = 0;
    int low_S = 100;
    int low_V = 100;
    int high_H = 10;
    int high_S = 255;
    int high_V = 255;

    cvtColor(image, imgHSV, COLOR_BGR2HSV);
    inRange(imgHSV, Scalar(low_H, low_S, low_V), Scalar(high_H, high_S, high_V), imgHSV);

    namedWindow("Escala de colores", 0); // Create a window for display.
    resizeWindow("Escala de colores", 683, 316);
    namedWindow("HSV", 0); // Create a window for display.
    resizeWindow("HSV", 683, 316);

    imshow("Escala de colores", image); // Show our image inside it.
    imshow("HSV", imgHSV);              // Show our image inside it.
    waitKey(0);                         // Wait for a keystroke in the window
    return 0;
}
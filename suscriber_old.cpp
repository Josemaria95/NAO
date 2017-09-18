#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <iostream>

using namespace cv;
using namespace std;

Mat cap_image;
Mat gray_img;
Mat img_filter;
Mat detected_edges;

//int lowThreshold;
//int const max_lowThreshold = 100;
//int ratio = 3;
//int kernel_size = 3;
//int key = waitKey(100);

void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
  try
  {
    cap_image = cv_bridge::toCvShare(msg, "bgr8")->image;
    cvtColor ( cap_image,gray_img,CV_BGR2GRAY ); // Convert to grayscale
    blur ( gray_img, img_filter , Size(3,3) );
    //GaussianBlur( img_filter, gray_img, Size (3, 3), 2, 2);
    Canny ( img_filter,detected_edges,50,250,3);
    //Canny ( img_filter,detected_edges,lowThreshold, lowThreshold*ratio, kernel_size );  // Apply canny edges
    //if (key == 99)
    //{
    
    //imwrite ("/home/josemaria/Documents/New_image.png",detected_edges); 
    //}
    //if ( == f)
    //{
     imwrite ("/home/josemaria/Documents/New_image.png",detected_edges); 
   // }
    cv::imshow ("Edge",detected_edges);
    cv::waitKey(30);
  }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "image_suscriber");
  ros::NodeHandle nh;
  cv::namedWindow("Edge");
  cv::startWindowThread();
  image_transport::ImageTransport it(nh);
  image_transport::Subscriber sub = it.subscribe("camera/image", 1, imageCallback);
  ros::spin();
  cv::destroyWindow("Edge");

  return 0;
}
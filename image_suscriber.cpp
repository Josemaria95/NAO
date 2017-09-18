#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

Mat cap_image, src , src_gray;
Mat gray_img;
Mat detected_edges , imagen_1;
Mat new_image;

int edgeThresh = 1;
int lowThreshold = 200;
int ratio = 3;
int kernel_size = 3;
//char d == waitKey(33);


void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
  try
  {
       
    cap_image = cv_bridge::toCvShare(msg, "bgr8")->image; 
    cvtColor ( cap_image,gray_img,CV_BGR2GRAY ); // Convert to grayscale
    blur (gray_img, detected_edges, Size(3,3));  /// Reduce noise with a kernel 3x3
    Canny ( imagen_1,detected_edges,lowThreshold,lowThreshold*ratio,kernel_size); // Apply canny edges
    //imwrite ("/home/josemaria/Documents/New_image.png",detected_edges,CV_IMWRITE_PNG_COMPRESSION);
    imwrite ("/home/josemaria/Documents/New_image.png",imagen_1);
    //dst = Scalar::all(0);
    //cap_image.copyTo (dst, detected_edges);
    imshow ("Edge",imagen_1);
    waitKey(30);
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
  namedWindow("Edge");
  startWindowThread();
  image_transport::ImageTransport it(nh);
  image_transport::Subscriber sub = it.subscribe("camera/image", 1, imageCallback);
  //int key == waitKey(100);
  //if (key == 99) 
  //{
    
  //}
  ros::spin();
  destroyWindow("Edge");
  

  return 0;
}

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <cv_bridge/cv_bridge.h>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)

{
  ros::init(argc, argv, "image_publisher");
  ros::NodeHandle nh;
  image_transport::ImageTransport it(nh);
  image_transport::Publisher pub = it.advertise("camera/image", 1);

  VideoCapture capture (0);  // Capture video 0 , device id

  if ( !capture.isOpened () )
  {
    printf ( "Error to initialize camera" );
    return 1;
  }

  cv::Mat cap_image;   // Define image matrix
  ros::Rate loop_rate(5);
  sensor_msgs::ImagePtr msg;

  while (nh.ok()) {
    capture >> cap_image;
    msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", cap_image).toImageMsg();
    pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    }
}

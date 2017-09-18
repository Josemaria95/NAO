//#include "opencv2/imgproc.hpp"
//#include "opencv2/imgcodecs.hpp"
//#include "opencv2/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>


using namespace cv;

//![variables]
Mat cap_image, src_gray;
Mat dst, detected_edges;

int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;
const char* window_name = "Edge Map";
//![variables]

/**
 * @function CannyThreshold
 * @brief Trackbar callback - Canny thresholds input with a ratio 1:3
 */
static void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
    //![reduce_noise]
    /// Reduce noise with a kernel 3x3
    blur( src_gray, detected_edges, Size(3,3) );
    //![reduce_noise]

    //![canny]
    /// Canny detector
    Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );
    //![canny]

    /// Using Canny's output as a mask, we display our result
    //![fill]
    dst = Scalar::all(0);
    //![fill]

    //![copyto]
    cap_image.copyTo( dst, detected_edges);
    //![copyto]

    //![display]
   // imshow( window_name, dst );
    //![display]
}


/**
 * @function main
 */
int main( int, char** argv )
{
  //![load]
  //src = imread( argv[1], IMREAD_COLOR ); // Load an image

  //if( src.empty() )
    //{ return -1; }
  //![load]

  VideoCapture capture (0);  // Capture video 0 , device id

  if ( !capture.isOpened () )
  {
    printf ( "Error to initialize camera" );
    return 1;
  }

  cv::Mat cap_image;   // Define image matrix
  //![create_mat]
  /// Create a matrix of the same type and size as src (for dst)
  dst.create( cap_image.size(), cap_image.type() );
  //![create_mat]

  //![convert_to_gray]
  cvtColor( cap_image, src_gray, COLOR_BGR2GRAY );
  //![convert_to_gray]

  //![create_window]
  //namedWindow( window_name, WINDOW_AUTOSIZE );
  //![create_window]

  //![create_trackbar]
  /// Create a Trackbar for user to enter threshold
  //createTrackbar( "Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold );
  //![create_trackbar]

  /// Show the image
  //CannyThreshold(0, 0);

  /// Wait until user exit program by pressing a key
  //waitKey(0);
    dst = Scalar::all(0);
    cap_image.copyTo (dst, detected_edges);
    imshow ("Edge",detected_edges);
    waitKey(30);
  return 0;
}
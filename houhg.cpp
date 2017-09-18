//#include <ros/ros.h>
//#include <image_transport/image_transport.h>
//#include "opencv2/imgproc/imgproc.hpp"
//#include <opencv2/highgui/highgui.hpp>
//#include <cv_bridge/cv_bridge.h>
//#include <iostream>

//using namespace cv;

//Mat image, detected_edges;
//Mat image_gray, filter_image;
//Mat dst;

//char* window_name = "Edge Map";

//void HoughLine ( int , void*)

//{
//	cvtColor (image, image_gray,CV_BGR2GRAY);
//	blur (image_gray, filter_image, Size(3,3));
//	Canny (filter_image, detected_edges,50,250,3);
//	dst = Scalar::all(0);
//	image.copyTo( dst, detected_edges);
//	imshow ("Edge Map",dst)
//}


//int main(int argc, char const *argv[])
//{
//	image = imread ("/home/josemaria/Pictures/Webcam/triangulo.jpg",0);

//	if( !image.data )

//  	{ 
//  		return -1; 
//  	}

//  	dst.create( image.size(), image.type() );
//  	HoughLine (0 , 0);
//  	namedWindow( "Edge Map", CV_WINDOW_AUTOSIZE );

//  	waitKey (0);

//	return 0;
//}
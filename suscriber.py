#!/usr/bin/env python
import rospy
import roslib
import sys
import cv2
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
import numpy as np


threshold1 = 50;
threshold2 = 70;
kernel_e = np.ones((3,3),np.uint8)
kernel_d = np.ones((11,11),np.uint8)
kernel = np.ones((9,9),np.uint8)
def hough_Transform(img):
#def hough_Transform():

    #img = cv2.imread("/home/josemaria/Documents/nueva_imagen.jpg",0)

    #minLineLength = 100
    #maxLineGap = 50

    #lines = cv2.HoughLinesP (img,1,np.pi/180,100,minLineLength,maxLineGap)

    #for x1,y1,x2,y2 in lines[0]:
     #   cv2.line(img,(x1,y1),(x2,y2),(0,255,0),2)
    #lines = cv2.HoughLines (img,1,np.pi/180,200)
    #for rho,theta in lines[0]:
    #    a = np.cos(theta)
    #    b = np.sin(theta)
    #    x0 = a*rho
    #    y0 = b*rho
    #    x1 = int(x0 + 1000*(-b))
    #    y1 = int(y0 + 1000*(a))
    #    x2 = int(x0 + 1000*(-b))
    #    y2 = int(y0 + 1000*(a))
        
    #    cv2.line(img,(x1,y1),(x2,y2),(0,0,255),2)
    minLineLength = 1000
    maxLineGap = 45
    lines = cv2.HoughLinesP (img,1.2,np.pi/180,15,minLineLength,maxLineGap)
#a,b,c = lines.shape
    for i in range (0,len(lines)):
        for x1,y1,x2,y2 in lines[i]:
            cv2.line(img, (x1,y1),(x2,y2),(0,255,0),2) 
    

    cv2.imwrite("/home/josemaria/Documents/hough_line.tif",img)
    cv2.imshow ("/home/josemaria/Documents/hough_line.tif",img)

    

def image_CallBack(msg):

    bridge = CvBridge()
    cap_image = bridge.imgmsg_to_cv2(msg,"bgr8")
    #gray_image = cv2.cvtColor (cap_image, cv2.COLOR_BGR2GRAY)
    #edge_image = cv2.Canny (gray_image,threshold1,threshold2,3)
    #
    #dilate = cv2.dilate(edge_image,kernel_d)
    #erosion = cv2.erode(dilate,kernel_e)
    #erosion = cv2.erode(erosion,kernel)
    cv2.imshow ("Edge",cap_image)
    k = cv2.waitKey(30)
    
    if (k == 99):    # c key to stop
       print "Screenshot"
       cv2.imwrite ("/home/josemaria/Documents/imagen_original.jpg",cap_image)
       #hough_Transform(edge_image)
    
def listener():

    rospy.init_node('listener', anonymous=True)
    rospy.Subscriber("camera/image", Image , image_CallBack)
    rospy.spin()

if __name__ == '__main__':
    listener()
 #hough_Transform()
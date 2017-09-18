#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import String
import roslib
import sys
import cv2
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

def __init__(self):

	self.bridge = CvBridge()
	
def talker():

	image_pub = rospy.Publisher ("camera/image",0)
	rospy.init_node('talker', anonymous = True)
	rate = rospy.Rate(10) # 10hz
	cap_image = cv2.VideoCapture(0)

	while not rospy.is_shutdown():
		show_image = self.bridge.cv2_to_imgmsg (cap_image,"bgr8")
		pub.publish(show_image)
		rate.sleep()

if __name__ == '__main__':
	
	talker()

	
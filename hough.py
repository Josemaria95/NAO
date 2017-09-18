import cv2
import numpy as np

img = cv2.imread("/home/josemaria/Documents/imagen.tif",0)
#lines = cv2.HoughLines(img,1,np.pi/180,200)
#for rho,theta in lines[0]:
#	a = np.cos(theta)
#	b = np.sin(theta)
#	x0 = a*rho
#	y0 = b*rho
#	x1 = int(x0 + 1000*(-b))
#	y1 = int(y0 + 1000*(a))
#	x2 = int(x0 - 1000*(-b))
#	y2 = int(y0 - 1000*(a))

#	cv2.line(img,(x1,y1),(x2,y2),(0,0,255),2)
minLineLength = 1000
maxLineGap = 45
lines = cv2.HoughLinesP (img,1.2,np.pi/180,15,minLineLength,maxLineGap)
#a,b,c = lines.shape
for i in range (0,len(lines)):
	for x1,y1,x2,y2 in lines[i]:
		cv2.line(img, (x1,y1),(x2,y2),(0,255,0),2) 
	
#for x1,y1,x2,y2 in lines[0]:
#   cv2.line(img,(x1,y1),(x2,y2),(0,255,0),2)

cv2.imwrite ("/home/josemaria/Documents/hough_image.jpg",img)
cv2.imshow  ("/home/josemaria/Documents/hough_image.jpg",img)
#cv2.imshow('hough',img)
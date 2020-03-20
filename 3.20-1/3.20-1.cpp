// 3.20-1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<opencv.hpp>
#include<iostream>

using namespace cv;


int main()
{
	cv::Mat a = imread("D:\\coin.png", 0); 
	cv::Mat b;
	cv::Mat c,d,e,f;
	cv::threshold(a, b, 0, 255, THRESH_OTSU);
	cv::Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3));
	dilate(b,c,kernel);
	erode(b, d, kernel);
	namedWindow("膨胀", CV_WINDOW_AUTOSIZE);
	imshow("膨胀", c);
	waitKey(0);
	namedWindow("腐蚀", CV_WINDOW_AUTOSIZE);
	imshow("腐蚀", d);
	waitKey(0);
	namedWindow("开运算", CV_WINDOW_AUTOSIZE);
	dilate(d, e, kernel);
	imshow("开运算",e);
	waitKey(0);
	namedWindow("闭运算", CV_WINDOW_AUTOSIZE);
	erode(c, f, kernel);
	imshow("闭运算",f);
	waitKey(0);
    return 0;
}


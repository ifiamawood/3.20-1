// 3.20-1.cpp : �������̨Ӧ�ó������ڵ㡣
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
	namedWindow("����", CV_WINDOW_AUTOSIZE);
	imshow("����", c);
	waitKey(0);
	namedWindow("��ʴ", CV_WINDOW_AUTOSIZE);
	imshow("��ʴ", d);
	waitKey(0);
	namedWindow("������", CV_WINDOW_AUTOSIZE);
	dilate(d, e, kernel);
	imshow("������",e);
	waitKey(0);
	namedWindow("������", CV_WINDOW_AUTOSIZE);
	erode(c, f, kernel);
	imshow("������",f);
	waitKey(0);
    return 0;
}


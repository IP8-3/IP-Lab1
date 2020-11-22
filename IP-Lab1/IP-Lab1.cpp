// IP-Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "ColorTransformer.h"
#include "Converter.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	//some implement here

	//if (argc < 2)
	//{
	//	cout << "Not enought paremeter";

	//	return;
	//}
	//
	//else
	//{

	//}

	Mat img = imread("test.jpg", IMREAD_COLOR);

	//vector<Mat> imageRGB;
	//split(img, imageRGB);

	//Mat imageRed, imageGreen, imageBlue;

	//int width = 250, height = 250;
	//int sizeHistogram = 256;
	//float range[] = { 0, 256 };
	//const float* histogramRange = { range };

	//// Tính toán cho từng kênh màu và vẽ biểu đồ Histogram
	//calcHist(&imageRGB[0], 1, 0, Mat(), imageRed, 1, &sizeHistogram, &histogramRange, true, false);
	//calcHist(&imageRGB[1], 1, 0, Mat(), imageGreen, 1, &sizeHistogram, &histogramRange, true, false);
	//calcHist(&imageRGB[2], 1, 0, Mat(), imageBlue, 1, &sizeHistogram, &histogramRange, true, false);

	//int gg = 0;
	//for (int i = 0; i < 256; i++)
	//{
	//	gg += imageBlue.at<float>(i);
	//	//cout << imageBlue.at<float>(i) << endl;
	//}

	//cout << "size " << gg;



	Mat hist;

	Mat i;

	ColorTransformer tr;
	tr.CalcHistogram(img, hist);
	tr.DrawHistogram(hist, i);


	namedWindow("BHD");

	imshow("BHD", i);

	waitKey(0);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

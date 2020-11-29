#include "Converter.h"

int Converter::RGB2GrayScale(const Mat& sourceImage, cv::Mat& destinationImage)
{
	//Lay chieu dai va chieu rong cua anh
	int width = sourceImage.cols, height = sourceImage.rows;

	//Lay channel cua anh
	int rgbChannels = sourceImage.channels();
	int grayChannels = sourceImage.channels();
	
	//Khoi tao anh gray
	destinationImage = Mat(height, width, CV_8UC1);
	
	//Dung vong lap lap và lay con tro dau dong
	for (int y = 0; y < height; y++)
	{
		uchar* pRGBRow = (uchar*)sourceImage.ptr<uchar>(y);
		uchar* pGrayRow = (uchar*)sourceImage.ptr<uchar>(y);
		//Xet tren tung pixel va lay 3 kenh mau cua anh
		for (int x = 0; x < width; x++, pRGBRow += rgbChannels, pGrayRow += grayChannels)
		{
			uchar B = pRGBRow[0];
			uchar G = pRGBRow[1];
			uchar R = pRGBRow[2];
			//Tinh gia tri gray
			uchar gray_val = (uchar)((B + G + R) / 3);
			pGrayRow[0] = gray_val;
		}

	}
	return 1;
}

int Converter::GrayScale2RGB(const Mat& sourceImage, Mat& destinationImage)
{
	return 0;
}

int Converter::RGB2HSV(const Mat& sourceImage, Mat& destinationImage)
{
	return 0;
}

int Converter::HSV2RGB(const Mat& sourceImage, Mat& destinationImage)
{
	return 0;
}

int Converter::Convert(Mat& sourceImage, Mat& destinationImage, int type)
{
	return 0;
}

Converter::Converter()
{
}

Converter::~Converter()
{
}

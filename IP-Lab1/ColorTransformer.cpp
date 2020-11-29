#include "ColorTransformer.h"

using namespace std;

int ColorTransformer::ChangeBrighness(const Mat& sourceImage, Mat& destinationImage, short b)
{
	return 0;
}

int ColorTransformer::ChangeContrast(const Mat& sourceImage, Mat& destinationImage, float c)
{
	return 0;
}

int ColorTransformer::CalcHistogram(const Mat& sourceImage, Mat& histMatrix)
{
	cv::Mat process_image = sourceImage.clone(); // copy matrix
	int nchanel = sourceImage.channels();
	int nl = sourceImage.rows; // number of lines
	int ncol = sourceImage.cols;

	switch (nchanel) // initialize histogram matrix
	{
	case 1: histMatrix = Mat::zeros(1, 256, CV_32FC1); break;
	case 3: histMatrix = Mat::zeros(3, 256, CV_32FC1); break;
	default: return 0;
	}
	int hh = 0;

	for (int j = 0; j < nl; j++)
	{
		// get pointer to line j
		uchar* data = process_image.ptr<uchar>(j);
		int step = 0;
		for (int i = 0; i < ncol; i++, data+=nchanel)
		{
			float* his_data_i = histMatrix.ptr<float>(0);
			int index = data[0];
			his_data_i[index] += 1;

			his_data_i = histMatrix.ptr<float>(1);
			index = data[1];
			his_data_i[index] += 1;

			his_data_i = histMatrix.ptr<float>(2);
			index = data[2];
			his_data_i[index] += 1;
			hh++;
		} // end of line
	}
	int l = 0;
	for (int i = 0; i < 256; i++)
	{
		l += (int)histMatrix.ptr<uchar>(0)[i];
	}

	return 1;
}

int ColorTransformer::HistogramEqualization(const Mat& sourceImage, Mat& destinationImage)
{
	return 0;
}

int ColorTransformer::DrawHistogram(const Mat& histMatrix, Mat& histImage)
{
	int width = histMatrix.cols;
	int height = histMatrix.rows;
	int srcChannels = histMatrix.channels();

	int BArr[256], GArr[256], RArr[256];
	int BTotal = 0, GTotal = 0, RTotal = 0;

	bool isInit = false;

	histImage = Mat(700, 1275, CV_8UC3, Scalar(0,0,0));
	int max = 0;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			float v = histMatrix.at<float>(y, x);
			if (v > max)
			{
				max = v;
			}
			if (y == 0)
			{
				BTotal += v;
				BArr[x] = v;
			}

			if (y == 1)
			{
				GTotal += v;
				GArr[x] = v;
			}

			if (y == 2)
			{
				RTotal += v;
				RArr[x] = v;
			}
		}
	}

	int hisWidth = 1275;
	int histHeight = 700;
	float scale = histHeight * 1.0 / (max + 10);

	int eleWidth = 1275 / 255;

	for (int i = 0; i < 256 - 1; i++)
	{
		line(
			histImage,
			Point(i * eleWidth, -BArr[i] * scale  + histHeight),
			Point((i + 1) * eleWidth, -BArr[i + 1] * scale + histHeight),
			Scalar(255, 0, 0),
			2, 8, 0);

		line(
			histImage,
			Point(i * eleWidth, -GArr[i] * scale + histHeight),
			Point((i + 1) * eleWidth, -GArr[i + 1] * scale + histHeight),
			Scalar(0, 255, 0),
			2, 8, 0);

		line(
			histImage,
			Point(i * eleWidth, -RArr[i] * scale + histHeight),
			Point((i + 1) * eleWidth, -RArr[i + 1] * scale + histHeight),
			Scalar(0, 0, 255),
			2, 8, 0);
	}

	return 1;
}

float ColorTransformer::CompareImage(const Mat& image1, Mat& image2)
{
	Mat hsv_image1, hsv_image2;
	//Chuyen doi he mau RGB sang he mau HSV
	cvtColor(image1, hsv_image1, COLOR_BGR2HSV);
	cvtColor(image2, hsv_image2, COLOR_BGR2HSV);

	//Khoi tao thong so de tinh toan histogram 2 hinh
	int h = 50, s = 60;
	int histSize[] = { h, s };
	float h_ranges[] = { 0, 180 };
	float s_ranges[] = { 0, 256 };
	const float* ranges[] = { h_ranges, s_ranges };
	int channels[] = { 0, 1 };
	Mat hist_base, hist_test1;

	//Tinh histogram cua 2 hinh anh
	calcHist(&hsv_image1, 1, channels, Mat(), hist_base, 2, histSize, ranges, true, false);
	normalize(hist_base, hist_base, 0, 1, NORM_MINMAX, -1, Mat());
	calcHist(&hsv_image2, 1, channels, Mat(), hist_test1, 2, histSize, ranges, true, false);
	normalize(hist_test1, hist_test1, 0, 1, NORM_MINMAX, -1, Mat());

	double base_test1 = compareHist(hist_base, hist_test1, 0);

	return base_test1;
}

ColorTransformer::ColorTransformer()
{
}

ColorTransformer::~ColorTransformer()
{
}

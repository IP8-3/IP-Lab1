#include "ColorTransformer.h"

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
	return 0;
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

	uchar BArr[256], GArr[256], RArr[256];
	int BTotal = 0, GTotal = 0, RTotal = 0;

	bool isInit = false;

	histImage = Mat(500, 500, CV_8UC1);

	for (int y = 0; y < height; y++)
	{
		uchar* pSrcRow = (uchar*)histMatrix.ptr<uchar>(y);

		for (int x = 0; x < width; x++, pSrcRow += srcChannels)
		{
			uchar B = pSrcRow[0];
			uchar G = pSrcRow[1];
			uchar R = pSrcRow[2];

			BTotal += B;
			GTotal += G;
			RTotal += R;

			BArr[x] = B;
			GArr[x] = G;
			RArr[x] = R;
		}
	}

	int hisWidth = 600;
	int histHeight = 600;

	int eleWidth = 600 / 300;

	for (int i = 0; i < 256 - 1; i++)
	{
		line(
			histImage,
			Point(i * eleWidth, -BArr[i] * 1.0 * histHeight / BTotal + histHeight),
			Point((i + 1) * eleWidth, -BArr[i + 1] * histHeight / BTotal + histHeight),
			Scalar(255, 0, 0),
			2, 8, 0);

		line(
			histImage,
			Point(i * eleWidth, -BArr[i] * histHeight / BTotal + histHeight),
			Point((i + 1) * eleWidth, -BArr[i + 1] * histHeight / BTotal + histHeight),
			Scalar(0, 255, 0),
			2);

		line(
			histImage,
			Point(i * eleWidth, -BArr[i] * histHeight / BTotal + histHeight),
			Point((i + 1) * eleWidth, -BArr[i + 1] * histHeight / BTotal + histHeight),
			Scalar(0, 0, 255),
			2);
	}

	return 0;
}

float ColorTransformer::CompareImage(const Mat& image1, Mat& image2)
{
	return 0.0f;
}

ColorTransformer::ColorTransformer()
{
}

ColorTransformer::~ColorTransformer()
{
}

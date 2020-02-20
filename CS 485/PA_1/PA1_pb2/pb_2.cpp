#include <iostream>
#include <cmath>
#include <opencv2/imgcodecs.hpp>

using namespace std;
using namespace cv;

int yGradient(Mat image, int x, int y);
int xGradient(Mat image, int x, int y);
void thresholdSobel(Mat src, float threshold);

int main()
{
	Mat src = imread("lenna.pgm", IMREAD_GRAYSCALE);
	Mat sf_src = imread("sf.pgm", IMREAD_GRAYSCALE);
	Mat dst = src.clone();
	Mat sf_dst = sf_src.clone();
	int gx, gy, sum;

	//(a) gradient in x direction

	//gradient in x direction, lenna
	for (int y = 1; y < src.rows - 1; y++) {
		for (int x = 1; x < src.cols - 1; x++) {
			gx = xGradient(src, x, y);
			sum = abs(gx);
			sum = sum > 255 ? 255 : sum;
			sum = sum < 0 ? 0 : sum;
			dst.at<uchar>(y, x) = sum;
		}
	}
	imwrite("lenna_x_sobel.pgm", dst);
	dst = src.clone();

	//gradient in x direction, sf
	for (int y = 1; y < sf_src.rows - 1; y++) {
		for (int x = 1; x < sf_src.cols - 1; x++) {
			gx = xGradient(sf_src, x, y);
			sum = abs(gx);
			sum = sum > 255 ? 255 : sum;
			sum = sum < 0 ? 0 : sum;
			sf_dst.at<uchar>(y, x) = sum;
		}
	}
	imwrite("sf_x_sobel.pgm", sf_dst);
	sf_dst = sf_src.clone();

	//(b) gradient in y direction

	//gradient in y direction, lenna
	for (int y = 1; y < src.rows - 1; y++) {
		for (int x = 1; x < src.cols - 1; x++) {
			gy = yGradient(src, x, y);
			sum = abs(gy);
			sum = sum > 255 ? 255 : sum;
			sum = sum < 0 ? 0 : sum;
			dst.at<uchar>(y, x) = sum;
		}
	}
	imwrite("lenna_y_sobel.pgm", dst);
	dst = src.clone();

	//gradient in y direction, sf
	for (int y = 1; y < sf_src.rows - 1; y++) {
		for (int x = 1; x < sf_src.cols - 1; x++) {
			gy = yGradient(sf_src, x, y);
			sum = abs(gy);
			sum = sum > 255 ? 255 : sum;
			sum = sum < 0 ? 0 : sum;
			sf_dst.at<uchar>(y, x) = sum;
		}
	}
	imwrite("sf_y_sobel.pgm", sf_dst);
	sf_dst = sf_src.clone();

	//(c) gradient magnitude 

	//gradient magnitude, lenna
	for (int y = 1; y < src.rows - 1; y++) {
		for (int x = 1; x < src.cols - 1; x++) {
			gx = xGradient(src, x, y);
			gy = yGradient(src, x, y);
			sum = abs(gx) + abs(gy);
			sum = sum > 255 ? 255 : sum;
			sum = sum < 0 ? 0 : sum;
			dst.at<uchar>(y, x) = sum;
		}
	}
	imwrite("lenna_magnitude_sobel.pgm", dst);
	dst = src.clone();

	//gradient magnitude, sf
	for (int y = 1; y < sf_src.rows - 1; y++) {
		for (int x = 1; x < sf_src.cols - 1; x++) {
			gx = xGradient(sf_src, x, y);
			gy = yGradient(sf_src, x, y);
			sum = abs(gx) + abs(gy);
			sum = sum > 255 ? 255 : sum;
			sum = sum < 0 ? 0 : sum;
			sf_dst.at<uchar>(y, x) = sum;
		}
	}
	imwrite("sf_magnitude_sobel.pgm", sf_dst);
	sf_dst = sf_src.clone();

	//(d) threshold sobel

	//takes in user threshold
	float threshold = 0.0;
	cout << "Enter threshold for sobel: ";
	cin >> threshold;

	thresholdSobel(dst, threshold);
	imwrite("lenna_threshold_sobel.pgm", dst);
	thresholdSobel(sf_dst, threshold);
	imwrite("sf_threshold_sobel.pgm", sf_dst);

	return 0;
}

int xGradient(Mat image, int x, int y)
{
	return ((2 * image.at<uchar>(y + 2, x + 1) + image.at<uchar>(y + 2, x) + image.at<uchar>(y + 2, x + 2))
		- (2 * image.at<uchar>(y, x + 1) + image.at<uchar>(y, x) + image.at<uchar>(y, x + 2)));
}

int yGradient(Mat image, int x, int y)
{
	return ((2 * image.at<uchar>(y + 1, x + 2) + image.at<uchar>(y, x + 2) + image.at<uchar>(y + 2, x + 2))
		- (2 * image.at<uchar>(y + 1, x) + image.at<uchar>(y, x) + image.at<uchar>(y + 2, x)));
}

void thresholdSobel(Mat src, float threshold)
{
	Mat temp = src.clone();

	int kernelX[3][3] = { { -1, 0, 1 },{ -2, 0, 2 },{ -1, 0, 1 } };
	int kernelY[3][3] = { { 1, 2, 1 },{ 0, 0, 0 },{ -1, -2, -1 } };

	for (int row = 1; row < src.rows - 1; row++)
		for (int column = 1; column < src.cols - 1; column++)
		{

			double sum = 0;
			int Gx = 0;
			int Gy = 0;

			for (int x = -1; x <= 1; x++)
				for (int y = -1; y <= 1; y++)
				{
					Gx += src.at<uchar>(row + y, column + x) * kernelX[y + 1][x + 1];
					Gy += src.at<uchar>(row + y, column + x) * kernelY[y + 1][x + 1];

				}

			sum = sqrt(double(Gx * Gx + Gy * Gy));

			if (sum >= threshold)
				temp.at<uchar>(row, column) = 255;

			else
				temp.at<uchar>(row, column) = 0;

		}

	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			src.at<uchar>(i, j) = temp.at<uchar>(i, j);
		}
	}
}
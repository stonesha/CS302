#include <iostream>
#include <cmath>
#include <vector>
#include <opencv2/imgcodecs.hpp>
#include <string>

using namespace std;
using namespace cv;

#define pi 3.14159

typedef vector<vector<float>> Vec2D;

void Gauss2D(float s, int kernelSize, Vec2D& H);
Mat conv2D(Mat src, Vec2D masks);
int circular(int M, int x);
Mat downsampleByTwo(Mat src);
Mat loadPreviousLevel(int i, int s);
void saveLevel(int i, int j, Mat image);
Mat loadPreviousFinal(int i);
void createPyramid(Mat src, float sigma, int levels, int s, int kernelSize);

int main()
{
	//initializations
	Mat src = imread("lenna.pgm", IMREAD_GRAYSCALE);

	//default values
	float sigma = 1.0;
	int levels = 0;
	int s = 0;
	int kernelSize = 5;

	//user defined parameters
	cout << "Define initial scale (sigma): ";
	cin >> sigma;

	cout << "Define number of octaves (levels): ";
	cin >> levels;

	cout << "Define number of intermediate levels (s): ";
	cin >> s;

	//kernel size is set to 5
	//Feel free to define your own kernel size
	/*
	cout << "Define kernel size (kernelSize): ";
	cin >> kernelSize;
	*/
	
	//create gaussian pyramid
	createPyramid(src, sigma, levels, s, kernelSize);

	return 0;
}

void createPyramid(Mat src, float sigma, int levels, int s, int kernelSize)
{
	Vec2D masks;
	bool flag = false;
	float k = 0.0;

	//first level doesn't have k
	Gauss2D(sigma, kernelSize, masks);
	Mat interm = conv2D(src, masks);
	saveLevel(1, 5, interm);

	//octave loop
	for (int i = 1; i < levels + 1; i++)
	{
		//intermediate level loop
		for (int j = s; j > 1; j--)
		{
			//first intermediate level, no k
			if (flag)
			{
				//load previous final octave
				Gauss2D(sigma, kernelSize, masks);
				Mat interm = conv2D(loadPreviousFinal(i - 1), masks);
				saveLevel(i, j, interm);
				flag = false;
			}

			//flag = false, no final layer created yet
			k = pow(2, (1.0 / j));
			Gauss2D((sigma * k), kernelSize, masks);
			Mat interm = conv2D(loadPreviousLevel(i, j), masks);
			saveLevel(i, j - 1, interm);

		}
		//load final interm layer
		Mat finalOctave = downsampleByTwo(loadPreviousLevel(i, 1));
		imwrite("lenna_octave" + to_string(i) + "final.pgm", finalOctave);
		flag = true;
	}
}

//save image
void saveLevel(int i, int j, Mat image)
{
	imwrite("lenna_octave" + to_string(i) + "_interm" + to_string(j) + ".pgm", image);
}

//loads previous image level
Mat loadPreviousLevel(int i, int j)
{
	return imread("lenna_octave" + to_string(i) + "_interm" + to_string(j) + ".pgm", IMREAD_GRAYSCALE);
}

//loads previous octave final image
Mat loadPreviousFinal(int i)
{
	return imread("lenna_octave" + to_string(i) + "final.pgm", IMREAD_GRAYSCALE);
}

//downsamples image by two
Mat downsampleByTwo(Mat src)
{
	int dstWidth = src.cols / 2;
	int dstHeight = src.rows / 2;
	Mat dst(dstWidth, dstHeight, src.type());

	for (int y = 0; y < dst.rows; y++)
	{
		for (int x = 0; x < dst.cols; x++)
		{
			dst.at<uchar>(y, x) = src.at<uchar>(y * (src.rows / dstHeight), x * (src.cols / dstWidth));
		}
	}

	return dst;
}

//boundary kernel checking
int circular(int M, int x)
{
	if (x < 0)
		return x + M;
	if (x >= M)
		return x - M;
	return x;
}

//convolution 2D images
Mat conv2D(Mat src, Vec2D masks)
{
	Mat dst = src.clone();
	float sum = 0.0, x1, y1;
	int half = masks.size() / 2;

	for (int y = 1; y < src.rows - 1; y++) {
		for (int x = 1; x < src.cols - 1; x++) {
			sum = 0.0;
			for (int k = -half; k <= half; k++) {
				for (int j = -half; j <= half; j++) {
					x1 = circular(src.cols, x - j);
					y1 = circular(src.rows, y - k);
					sum = sum + masks[j + half][k + half] * src.at<uchar>(y1, x1);
				}
			}
			dst.at<uchar>(y, x) = sum;
		}
	}

	return dst;
}

//generating gaussian masks for 2D
void Gauss2D(float s, int kernelSize, Vec2D& H)
{
	H.clear();
	H.resize(kernelSize, vector<float>(kernelSize, 0));

	int i, j;
	int mean = kernelSize / 2;
	float sum;

	for (i = 0; i < kernelSize; i++)
	{
		for (j = 0; j < kernelSize; j++)
		{
			H[i][j] = exp(-0.5 * (pow((i - mean) / s, 2.0) + pow((j - mean) / s, 2.0)))
				/ (2 * pi * s * s);
		}
	}


	sum = 0.0;

	for (i = 0; i < kernelSize; i++)
		for (j = 0; j < kernelSize; j++)
			sum += H[i][j];

	for (i = 0; i < kernelSize; i++)
		for (j = 0; j < kernelSize; j++)
			H[i][j] /= sum;

}
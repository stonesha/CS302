#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

#define pi 3.14159

using namespace std;
using namespace cv;

typedef vector<float> VecF;
typedef vector<vector<float>> Vec2D;

void Gauss (float s, int Hsize, VecF& H);
void Gauss2D(float s, int kernelY, int kernelX, Vec2D& H);
VecF conv1D (const VecF rect,  int kernelSize, VecF masks);
int circular(int M, int x);
void conv2D(Mat src, Mat dst, Vec2D masks);
void conv2DSep(Mat src, Mat dst, VecF masks);
void vecToFile(const VecF vec, const string fileName);

int main(int argc, char* argv[]) {

	//variables for 1D Gaussian
	ifstream fp("Rect_128.txt");

	VecF rect128;
	VecF result;
	VecF sigma1(5, 0);
	VecF sigma5(25, 0);
	VecF sigma11(55, 0);

	for (string line; getline(fp, line);)
	{
		rect128.push_back(stod(line));
	}

	//(a) 1D convolution
	//sigma = 1
	Gauss(1.0, 5, sigma1);	
	//vector subscript out of range
	result = conv1D(rect128, 5, sigma1);
	vecToFile(result, "sigma1.txt");	

	//sigma = 5
	Gauss(5.0, 25, sigma5);	
	result = conv1D(rect128, 25, sigma5);
	vecToFile(result, "sigma5.txt");	

	//sigma = 11
	Gauss(11.0, 55, sigma11);	
	result = conv1D(rect128, 55, sigma11);
	vecToFile(result, "sigma11.txt");	

	fp.close();
		
	//(b) 2D convolution on images
	Mat src = imread("lenna.pgm", IMREAD_GRAYSCALE);
	Mat dst = src.clone();
	Vec2D sigma2D;

	//sigma = 1
	Gauss2D(1, 5, 5, sigma2D);
	conv2D(src, dst, sigma2D);
	imwrite("lenna_sigma1.pgm", dst);
	dst = src.clone();

	//sigma = 5
	Gauss2D(5, 25, 25, sigma2D);
	conv2D(src, dst, sigma2D);
	imwrite("lenna_sigma5.pgm", dst);
	dst = src.clone();

	//sigma = 11
	Gauss2D(11, 55, 55, sigma2D);
	conv2D(src, dst, sigma2D);
	imwrite("lenna_sigma11.pgm", dst);
	dst = src.clone();

	//(c) 2D Gaussian smoothing with 1D masks
	conv2DSep(src, dst, sigma1);
	imwrite("lenna_sigma1_1D.pgm", dst);
	dst = src.clone();

	conv2DSep(src, dst, sigma5);
	imwrite("lenna_sigma5_1D.pgm", dst);
	dst = src.clone();

	conv2DSep(src, dst, sigma11);
	imwrite("lenna_sigma11_1D.pgm", dst);
	dst = src.clone();

	return 0;
}

//for plotting purposes
void vecToFile(VecF vec, const string fileName)
{
	ofstream ofp(fileName);
	for(const auto &i : vec)
		ofp << i * 255.0 << endl;
	
	ofp.close();	
}

//1D convolution
VecF conv1D(const VecF rect, int kernelSize, const VecF masks)
{
	VecF result(128, 0);

	for (int i = 0; i <= 128 - kernelSize; i++)
	{
		result[i] = 0.0;
		for (int j = 0; j < kernelSize; j++)
		{
			result[i] += rect[i + j] * masks[kernelSize - j - 1];
		}
	}

	return result;
}

int circular(int M, int x)
{
	if (x < 0)
		return x + M;
	if (x >= M)
		return x - M;
	return x;
}

void conv2D(Mat src, Mat dst, Vec2D masks)
{
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

	
}

void conv2DSep(Mat src, Mat dst, VecF masks)
{
	float sum, x1, y1;
	int half = masks.size() / 2;
	Mat temp = src.clone();

	for (int y = 0; y < src.rows; y++)
	{
		for (int x = 0; x < src.cols; x++)
		{
			sum = 0.0;
			for (int i = -half; i <= half; i++)
			{
				y1 = circular(src.rows, y - i);
				sum += masks[i + half] * src.at<uchar>(y1, x);
			}
			temp.at<uchar>(y, x) = sum;
		}
	}

	for (int y = 0; y < src.rows; y++)
	{
		for (int x = 0; x < src.cols; x++)
		{
			sum = 0.0;
			for (int i = -half; i <= half; i++)
			{
				x1 = circular(src.rows, x - i);
				sum += masks[i + half] * temp.at<uchar>(y, x1);
			}
			dst.at < uchar>(y, x) = sum;
		}
	}
}

//to generate masks
//s = sigma, Hsize = mask size, H = array
void Gauss (float s, int Hsize, VecF& H)

{
  
	int     i;
	float  cst,tssq,x,sum;
 
	cst=1./(s*sqrt(2.0*pi));
	tssq=1./(2*s*s);
 
  
	for (i=0; i<Hsize; i++) 
	{
    
		x=(float)(i-Hsize/2);
    
		H[i]=(cst*exp(-(x*x*tssq)));
  
	}
 
  	
	sum=0.0;
  
	for (i=0;i<Hsize;i++)
    
		sum += H[i];
  
	for(i=0;i<Hsize;i++)
    
	H[i] /= sum;

}

void Gauss2D(float s, int kernelY, int kernelX, Vec2D& H)

{
	H.clear();
	H.resize(kernelY, VecF(kernelX, 0));

	int i, j;
	int mean = kernelX / 2;
	float sum;

	for (i = 0; i < kernelY; i++)
	{
		for (j = 0; j < kernelX; j++)
		{
			H[i][j] = exp(-0.5 * (pow((i - mean) / s, 2.0) + pow((j - mean) / s, 2.0)))
				/ (2 * pi * s * s);
		}
	}


	sum = 0.0;

	for (i = 0; i < kernelY; i++)
		for(j = 0;j < kernelX; j++)
			sum += H[i][j];

	for (i = 0; i < kernelY; i++)
		for(j = 0; j < kernelX; j++)
			H[i][j] /= sum;

}

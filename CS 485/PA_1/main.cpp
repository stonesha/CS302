

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

#define pi 3.14159

using namespace std;
using namespace cv;

typedef vector<double> VecD;

void vecToFile(const string fileName, const VecD vec);

int main(int argc, char* argv[]) {

	//variables for 1D Gaussian
	ifstream fp("Rect_128.txt");
	Mat src = imread("lenna.pgm");
	Mat dst;	

	VecD rect128;
	VecD sigma1;
	VecD sigma5;
	VecD sigma11;

	for (string line; getline(fp, line);)
	{
		rect128.push_back(stod(line));
	}

	//Problem 1	
	//(a)1D Gaussian smoothing
	//Mask size = 5 * sigma
	GaussianBlur(rect128, sigma1, Size(5, 0), 1, 0);
	GaussianBlur(rect128, sigma5, Size(25, 0), 5, 0);
	GaussianBlur(rect128, sigma11, Size(55, 0), 11, 0);

	//For plotting purposes
	vecToFile("sigma1.txt", sigma1);
	vecToFile("sigma5.txt", sigma5);
	vecToFile("sigma11.txt", sigma11);

	//(b) 2D Gaussian 
	GaussianBlur(src, dst, Size(5, 5), 1, 1);
	imwrite("lenna_sigma1_2D.jpg", dst);

	GaussianBlur(src, dst, Size(25, 25), 5, 5);
	imwrite("lenna_sigma5_2D.jpg", dst);

	GaussianBlur(src, dst, Size(55, 55), 11, 11);
	imwrite("lenna_sigma11_2D.jpg", dst);

	//(c) 1D Gaussian on 2D Image
	GaussianBlur(src, dst, Size(5, 0), 1, 0);
	imwrite("lenna_sigma1_1D.jpg", dst);

	GaussianBlur(src, dst, Size(25, 0), 5, 0);
	imwrite("lenna_sigma5_1D.jpg", dst);

	GaussianBlur(src, dst, Size(55, 0), 11, 0);
	imwrite("lenna_sigma11_1D.jpg", dst);

	
	fp.close();
	return 0;
}

void vecToFile(const string fileName, const VecD vec)
{
	ofstream fp(fileName);
	for (const auto& i : vec) 
		fp << i << endl;
}

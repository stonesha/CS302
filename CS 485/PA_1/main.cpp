/*
To do: add matplotlib functionality, perhaps in a separate file?
*/

#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <cmath>
#include <opencv2/opencv.hpp>
#include <vector>
#include <algorithm>
#include <iterator>


using namespace std;
using namespace cv;

inline void normalize(Mat &img);
inline double gauss1D(double x, double sigma);

int main(int argc, char* argv[]){
	ifstream fp("Rect_128.txt");
	vector<double> fileNums;

	for(string line; getline(fp, line);)
	{
		fileNums.push_back(stod(line));
	}

	vector<double> sigma1;
	vector<double> sigma5;
	vector<double> sigma11;

	for(double i : fileNums)
	{
		sigma1.push_back(gauss1D(i, 1));
		sigma5.push_back(gauss1D(i, 5));
		sigma11.push_back(gauss1D(i, 11));
	}

	ofstream outFile;
	outFile.open("sigma-1.txt");
	ostream_iterator<double> output_it(outFile, "\n");
	copy(sigma1.begin(), sigma1.end(), output_it);
	outFile.close();
	
	outFile.open("sigma-5.txt");
	ostream_iterator<double> output_it2(outFile, "\n");
	copy(sigma5.begin(), sigma5.end(), output_it2);
	outFile.close();

	outFile.open("sigma-11.txt");
	ostream_iterator<double> output_it3(outFile, "\n");
	copy(sigma11.begin(), sigma11.end(), output_it3);
	outFile.close();

	return 0;
}

inline void normalize(Mat &img)
{
	img.convertTo(img, CV_32F, 1.0 / 255.0, 0);
}

inline double gauss1D(double x, double sigma)
{
	double expVal = -1 * (pow(x, 2) / (2 * pow(sigma, 2)));
    double divider = sqrt(2 * M_PI * pow(sigma, 2));
	return (1 / divider) * exp(expVal);
}

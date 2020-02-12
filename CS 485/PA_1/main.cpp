

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

	VecD rect128;
	VecD sigma1;
	VecD sigma5;
	VecD sigma11;

	for (string line; getline(fp, line);)
	{
		rect128.push_back(stod(line));
	}

	//Mask size = 5 * sigma
	GaussianBlur(rect128, sigma1, Size(5, 0), 1, 0);
	GaussianBlur(rect128, sigma5, Size(25, 0), 5, 0);
	GaussianBlur(rect128, sigma11, Size(55, 0), 11, 0);

	//For plotting purposes
	vecToFile("sigma1.txt", sigma1);
	vecToFile("sigma5.txt", sigma5);
	vecToFile("sigma11.txt", sigma11);




	return 0;
}

void vecToFile(const string fileName, const VecD vec)
{
	ofstream fp(fileName);
	for (const auto& i : vec) 
		fp << i << endl;
}

/*
To do: add matplotlib functionality, perhaps in a separate file?
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <opencv2/opencv.hpp>
#include <vector>
#include <iterator>

using namespace std;
using namespace cv;

constexpr double pi() { return atan(1)*4; }
typedef vector<double> VecD;

inline void normalize(Mat &img);
void gauss1D(float s, int Hsize, VecD H);

int main(int argc, char* argv[]){

	//variables for 1D Gaussian
	ifstream fp("Rect_128.txt");

	VecD rect128;
	VecD sigma1(5, 0);
	VecD sigma5(25, 0);
	VecD sigma11(55, 0);

	for(string line; getline(fp, line);)
	{
		rect128.push_back(stod(line));
	}

	

	/*vector<double> fileNums;

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
	outFile.close();*/

	return 0;
}

inline void normalize(Mat &img)
{
	img.convertTo(img, CV_32F, 1.0 / 255.0, 0);
}

void gauss1D(float s, int Hsize, VecD H)
{
	int     i;
	float  cst,tssq,x,sum;
 
	cst=1./(s*sqrt(2.0*pi()));
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
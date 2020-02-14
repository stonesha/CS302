

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

#define pi 3.14159

using namespace std;

typedef vector<float> VecF;

void ReadImage(char fname[], int ***fimage, int& M, int& N, int& Q);
void WriteImage(char fname[], int **fimage, int M, int N, int Q);
//s = sigma, Hsize = mask size, H = array
void Gauss (float s, int Hsize, VecF& H);
VecF conv1D (const VecF rect,  int kernelSize, VecF masks);
//for plotting purposes
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

	//sigma = 1
	Gauss(1.0, 5, sigma1);	
	result = conv1D(rect128, 5, sigma1);
	vecToFile(result, "sigma1.txt");	
	result.clear();
		
	fp.close();
	return 0;
}

//for plotting purposes
void vecToFile(const VecF vec, const string fileName)
{
	ofstream fp(fileName);
	for( const auto& i : vec)
		fp << i << endl;
	fp.close();	
}

//1D convolution
VecF conv1D(const VecF rect, int kernelSize, const VecF masks)
{
	VecF result(128, 0);

	for(int i = 0; i < 128; i++)
	{
		result[i] = 0;
		for(int j = 0; j < kernelSize; j++)
		{
			result[i] += rect[i - j] * masks[j]; 
		}
	}

	return result;
}

//to generate masks
void Gauss (float s, int Hsize, vector<float>& H)

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

//to write to images
void WriteImage(char fname[], int **fimage, int M, int N, int Q)
{
 int i, j;
 unsigned char *image;
 ofstream ofp;

 image = (unsigned char *) new unsigned char [M*N];

 // convert the integer values to unsigned char

 for(i=0; i<N; i++)
   for(j=0; j<M; j++)
     image[i*M+j]=(unsigned char)fimage[i][j];

 ofp.open(fname, ios::out);

 if (!ofp) {
   cout << "Can't open file: " << fname << endl;
   exit(1);
 }

 ofp << "P5" << endl;
 ofp << M << " " << N << endl;
 ofp << Q << endl;

 ofp.write( reinterpret_cast<char *>(image), (M*N)*sizeof(unsigned char));

 if (ofp.fail()) {
   cout << "Can't write image " << fname << endl;
   exit(0);
 }

 ofp.close();

}

//read from images
void ReadImage(char fname[], int ***fimage, int& M, int& N, int& Q)
{
 int i, j;
 unsigned char *image;
 char header [100], *ptr;
 ifstream ifp;

 ifp.open(fname, ios::in); 

 if (!ifp) {
   cout << "Can't read image: " << fname << endl;
   exit(1);
 }

 // read header

 ifp.getline(header,100,'\n');
 if ( (header[0]!=80) ||    /* 'P' */
      (header[1]!=53) ) {   /* '5' */
      cout << "Image " << fname << " is not PGM" << endl;
      exit(1);
 }

 ifp.getline(header,100,'\n');
 while(header[0]=='#')
   ifp.getline(header,100,'\n');

 M=strtol(header,&ptr,0);
 N=atoi(ptr);

 ifp.getline(header,100,'\n');

 Q=strtol(header,&ptr,0);

 image = (unsigned char *) new unsigned char [M*N];

 *fimage = new int* [N];
 for(i=0; i<N; i++)
   (*fimage)[i] = new int[M];

 ifp.read( reinterpret_cast<char *>(image), (M*N)*sizeof(unsigned char));

 if (ifp.fail()) {
   cout << "Image " << fname << " has wrong size" << endl;
   exit(1);
 }

 ifp.close();

 //
 // Convert the unsigned characters to integers
 //

 for(i=0; i<N; i++)
   for(j=0; j<M; j++)
     (*fimage)[i][j]=(int)image[i*M+j];
}

#include "TSP.h"
#include <iostream>
#include <fstream>


int main()
{

	TSP t;
	std::ofstream fp("paths.txt", std::ios::out, std::ios::trunc);

	t.printSolution(fp);

	t.printAllPaths(fp);

	fp.close();

	std::cout << "Paths were written to paths.txt." << std::endl;

	return 0;
}


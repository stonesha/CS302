#include <iostream>
#include <vector>

#define V 6

typedef std::vector<std::vector<int>> Graph;

//mess function for printing the adjacency matrix
void printGraph(Graph g)
{
	int n = 1;

	std::cout << "    ";

	for (int i = 0; i < V; i++)
		std::cout << i + 1<< " ";

	std::cout << "\n  - - - - - - - - \n";

	for (const std::vector<int>& v : g)
	{
		std::cout << n++ << " | ";

		for (int i : v)
			std::cout << i << " ";

		std::cout << "|" << std::endl;
	}
	std::cout << "  - - - - - - - - \n";
}

int main()
{
	Graph g =
	{// 1  2  3  4  5  6
/*1*/ { 0, 2, 3, 0, 0, 0},
/*2*/ { 2, 0, 3, 0, 0, 0},
/*3*/ { 3, 3, 0, 5, 4, 0},
/*4*/ { 0, 0, 5, 0, 6, 1},
/*5*/ { 0, 0, 4, 6, 0, 2},
/*6*/ { 0, 0, 0, 1, 2, 0},
	};

	printGraph(g);

	return 0;
}
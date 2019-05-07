/**
 * @brief  CS-302 Homework 8
 * @Author Stone Sha (stones@nevada.unr.edu)
 * @date   May 2019
 *
 * Main driver program to test Prim's algorithm using an adjacency matrix to find the MST
 * Explanation included in "[CS 302] HW8.docx"
 */

#include <iostream>
#include <vector>
#include <climits>

//no. of vertices
#define V 6

//ease of typing for personal use
typedef std::vector<int> VecInt;
typedef std::vector<bool> VecBool;
typedef std::vector<std::string> VecString;
typedef std::vector<VecInt> Graph;

//messy function for printing the adjacency matrix
void printGraph(Graph g)
{
	int n = 1;

	std::cout << "    ";

	for (int i = 0; i < V; i++)
		std::cout << i + 1<< " ";

	std::cout << "\n  - - - - - - - - \n";

	for (const VecInt &v : g)
	{
		std::cout << n++ << " | ";

		for (int i : v)
			std::cout << i << " ";

		std::cout << "|" << std::endl;
	}
	std::cout << "  - - - - - - - - \n";
}

//prints mst from prim's algorithm
void printMST(VecInt v, Graph g)
{
	std::cout << "Edge\t\tWeight\n";

	for (int i = 1; i < V; i++)
		std::cout << v[i] + 1 << " -> " << i + 1 << "\t\t"
		<< g[i][v[i]] << std::endl;
}

//to find the smallest neightbor vertex value for not visited vertices
int firstMin(VecInt v, VecBool visited)
{
	int min = INT_MAX, min_index;

	for (int i = 0; i < V; i++)
	{
		if (visited[i] == false && v[i] < min)
			min = v[i], min_index = i;
	}

	return min_index;
}

//takes in a graph and constructs the mst and weights for each edge
void prim(Graph g)
{
	VecInt cheap(V, INT_MAX); //cheapest edge weights
	VecBool visited(V, false); //if vertex is visted
	VecInt MST(V); //mst stored in vector
	int x;

	cheap[0] = 0;
	MST[0] = -1;

	for (int i = 0; i < V - 1; i++)
	{
		x = firstMin(cheap, visited);
		visited[x] = true;

		for (int j = 0; j < V; j++)
		{
			if (g[x][j] && visited[j] == false && g[x][j] < cheap[j])
				MST[j] = x, cheap[j] = g[x][j];
		}
	}

	printMST(MST, g);
}

int main()
{
	//2D vector, typedef as Graph
	Graph g =
	{// 1  2  3  4  5  6
/*1*/ { 0, 2, 3, 0, 0, 0},
/*2*/ { 2, 0, 3, 0, 0, 0},
/*3*/ { 3, 3, 0, 5, 4, 0},
/*4*/ { 0, 0, 5, 0, 6, 1},
/*5*/ { 0, 0, 4, 6, 0, 2},
/*6*/ { 0, 0, 0, 1, 2, 0},
	};

	//prints adjacency matrix
	printGraph(g);

	//uses prims algorithm to print the mst and the edge's weights
	prim(g);

	return 0;
}
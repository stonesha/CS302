#include <iostream>
#include <vector>
#include <climits>

#define V 6

typedef std::vector<int> VecInt;
typedef std::vector<bool> VecBool;
typedef std::vector<std::string> VecString;
typedef std::vector<VecInt> Graph;

//mess function for printing the adjacency matrix
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


void printMST(VecInt v, Graph g)
{
	std::cout << "Edge\t\tWeight\n";

	for (int i = 0; i < V - 1; i++)
		std::cout << v[i] << " -> " << i << "\t\t" << std::endl;
		//<< g[i][v[i]] << std::endl;;
}

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
	//https://i.imgur.com/xpSJn1g.png << graph created
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

	prim(g);

	return 0;
}
#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <climits>

#define V 5

typedef std::vector<int> VecInt;
typedef std::vector<bool> VecBool;
typedef std::vector<std::string> VecString;
typedef std::vector<VecInt> Graph;


class TSP {
public:

	TSP();

	void printSolution(std::ofstream& os);
	void printAllPaths(std::ofstream& os);

protected:
	int firstMin(int i);

	int secondMin(int i);

	void TSPUtil();
	void TSPRec(int curr_bound, int curr_weight,
		int level, VecInt curr_path);

	
private:
	Graph adj =
	{	/*R   SF  SLC   SE   LV*/
/*R*/	{ 0, 218, 518, 705, 439 },
/*SF*/	{ 218,  0,  0, 806, 570 },
/*SLC*/	{ 518,  0,  0, 840, 421 },
/*SE*/	{ 705, 806, 832, 0, 1116 },
/*LV*/	{ 438, 569, 421, 1125, 0},
	};

	VecString index =
	{ "Reno", "San Francisco", "Salt Lake City",
	"Seattle", "Las Vegas" };

	int final_weight = INT_MAX;
	VecInt final_path;
	VecBool visited;
};

TSP::TSP()
{
}

int TSP::firstMin(int i)
{
	int min = INT_MAX;
	for (int j = 0; j < V; j++)
		if (adj[i][j] < min && i != j)
			min = adj[i][j];

	return min;
}


int TSP::secondMin(int i)
{
	int first = INT_MAX, second = INT_MAX;

	for (int j = 0; j < V; j++)
	{
		if (i == j)
			continue;

		if (adj[i][j] <= first)
		{
			second = first;
			first = adj[i][j];
		}
		else if (adj[i][j] <= second && adj[i][j] != first)
		{
			second = adj[i][j];
		}
	}

	return second;
}


void TSP::TSPRec(int curr_bound, int curr_weight,
	int level, VecInt curr_path)
{
	if (level == V)
	{
		if (adj[curr_path[level - 1]][curr_path[0]] != 0)
		{
			int curr_res = curr_weight + adj[curr_path[level - 1]][curr_path[0]];

			if (curr_res < final_weight)
			{
				final_weight = curr_res;
				final_path = curr_path;
			}
		}
	}

	for (int i = 0; i < V; i++)
	{
		if (adj[curr_path[level - 1]][i] != 0 &&
			visited[i] == false)
		{
			int temp = curr_bound;
			curr_weight += adj[curr_path[level - 1]][i];

			if (level == 1)
				curr_bound -= ((firstMin(curr_path[level - 1]) +
					firstMin(i)) / 2);
			else
				curr_bound -= ((secondMin(curr_path[level - 1]) +
					firstMin(i)) / 2);

			if (curr_bound + curr_weight < final_weight)
			{
				curr_path[level] = i;
				visited[i] = true;

				TSPRec(curr_bound, curr_weight, level + 1,
					curr_path);
			}

			curr_weight -= adj[curr_path[level - 1]][i];
			curr_bound = temp;

			visited.assign(visited.size(), false);
			for (int j = 0; j <= level - 1; j++)
				visited[curr_path[j]] = true;
		}
	}
}

void TSP::TSPUtil()
{
	VecInt curr_path;
	int curr_bound = 0;

	curr_path.resize(V + 1);
	visited.resize(curr_path.size());

	curr_path.assign(curr_path.size(), -1);
	visited.assign(curr_path.size(), false);

	for (int i = 0; i < V; i++)
		curr_bound += (firstMin(i) + secondMin(i));

	curr_bound /= 2;

	visited[0] = true;
	curr_path[0] = 0;

	TSPRec(curr_bound, 0, 1, curr_path);
}

void TSP::printSolution(std::ofstream &os)
{
	TSPUtil();

	os << "Minimun cost: " << final_weight
		<< "\nPath by Vertex: ";
	for (unsigned int i = 0; i < V; i++)
	{
		os << final_path.at(i);
		if (i != final_path.size() - 1)
			os << " -> ";
	}
	os << final_path.at(0) << std::endl;

	os << "Path by City: ";
	for (unsigned int i = 0; i < V; i++)
	{
		os << index[final_path.at(i)];
		os << " -> ";
	}
	os << index[0] << std::endl;
}

void TSP::printAllPaths(std::ofstream& os)
{

	os << std::endl << "All Possible Paths" << std::endl
		<< "Assuming direct connections between all vertexes" << std::endl;

	std::sort(index.begin() + 1, index.end());

	while (std::next_permutation(index.begin() + 1, index.end()))
	{

		for (int i = 0; i < V; i++)
		{
			os << index[i];
			if (i != index.size() - 1)
			{
				os << " -> ";
			}
		}
		os << std::endl;
	}

}
#pragma once
#include <vector>
#include <string>

#define V 5

typedef std::vector<int> VecInt;
typedef std::vector<bool> VecBool;
typedef std::vector<VecInt> Graph;


class TSP {
public:

	TSP();

	void printSolution();

protected:
	int firstMin(int i);

	int secondMin(int i);

	void TSPRec(int curr_weight,
		int level);

private:
	Graph adj =
	{	/*R   SF  SLC   SE   LV*/
		/*R*/	{ 0, 218, 518, 705, 439 },
		/*SF*/	{ 218, 0, 0, 807, 569 },
		/*SLC*/	{ 518, 0, 0, 840, 421 },
		/*SE*/	{ 705, 807, 840, 0, 1116 },
		/*LV*/	{ 439, 569, 421, 1116, 0},
	};

	std::string index[V] =
	{ "Reno", "San Francisco", "Salt Lake City",
	"Seattle", "Las Vegas" };

	int final_weight = INT_MAX;

	VecInt curr_path;
	VecBool visited;

	int curr_bound = 0;
};

TSP::TSP()
{
	curr_path.resize(V + 1);
	visited.resize(curr_path.size());

	curr_path.assign(curr_path.size(), -1);
	visited.assign(curr_path.size(), false);

	for (int i = 0; i < V; i++)
		curr_bound += (firstMin(i) + secondMin(i));

	curr_bound /= 2;

	visited[0] = true;
	curr_path[0] = 0;
}

int TSP::firstMin(int i)
{

}


int TSP::secondMin(int i)
{

}


void TSP::TSPRec(int curr_weight,
	int level)
{

}

void TSP::printSolution()
{

	TSPRec(0, 1);
}

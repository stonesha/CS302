#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

#define VERTICES 5

class Graph
{
public:
	Graph();
	~Graph();

	void dijkstra(int src);
	int minDistance(int dist[], bool shortestPath[]);
	void printGraph(std::vector<int> dist, std::string index[]);

	void printAllPaths(std::vector<int> path);
	void allPaths();
	bool notVisited(int v, std::vector<int> path);

private:

	/*
	Distances were obtained using Google Maps
	1 = Reno (R), 2 = San Francisco (SF), 3 = Salt Lake City(SLC),
	4 = Seattle(SE), 5 = Las Vegas(LV)
	*/
	
	std::vector<std::vector<int>> weightedGraph =
	{	/*R   SF  SLC   SE   LV*/
/*R*/	{ 0, 218, 518, 705, 439 },
/*SF*/	{ 218, 0, 0, 807, 569 },
/*SLC*/	{ 518, 0, 0, 840, 421 },
/*SE*/	{ 705, 807, 840, 0, 1116 },
/*LV*/	{ 439, 569, 421, 1116, INT_MAX },
	}; 	

	std::string indexGraph[VERTICES] =
	{"Reno", "San Francisco", "Salt Lake City",
	"Seattle", "Las Vegas"};

};

Graph::Graph()
{
}

Graph::~Graph()
{
}

/*
void Graph::dijkstra(int src)
{
	int dist[VERTICES];
	std::string index[VERTICES];
	bool shortestPath[VERTICES];

	std::fill_n(dist, VERTICES, INT_MAX);
	std::fill_n(shortestPath, VERTICES, false);
	index[0] = indexGraph[0];


	dist[src] = 0;

	for (int i = 0; i < VERTICES - 1; i++)
	{
		int u = minDistance(dist, shortestPath);

		shortestPath[u] = true;

		for (int v = 0; v < VERTICES; v++)
		{
			if (!shortestPath[v] && weightedGraph[u][v] && dist[u] != INT_MAX && dist[u] + weightedGraph[u][v] < dist[v])
			{
				dist[v] = dist[u] + weightedGraph[u][v];
				index[v] = indexGraph[v];
			}
		}
	}

	std::cout << "Best Possible Path" << std::endl
		<< "==================" << std::endl;
	printGraph(dist, index);

}
*/


int Graph::minDistance(int dist[], bool shortestPath[])
{
	int min_index, min = INT_MAX;

	for (int i = 0; i < VERTICES; i++)
		if (shortestPath[i] == false && dist[i] <= min)
			min = dist[i], min_index = i;

	return min_index;
}

void Graph::printGraph(std::vector<int> dist, std::string index[])
{
	std::cout << "Vertex\tWeight\n";

	for (int i = 0; i < VERTICES; i++)
		std::cout << i << "\t" << dist[i] << std::endl;

	std::cout << "Path: ";
	for (int i = 0; i < VERTICES; i++)
	{
		std::cout << index[i];
		if (i != VERTICES - 1)
			std::cout << " - ";
	}

	std::cout << std::endl;
		
}

void Graph::allPaths()
{
	std::vector<int> v;
	std::vector<int> dist_min_path;
	std::vector<int> dist_pathweight;
	std::string index[VERTICES];

	for (int i = 0; i < VERTICES; i++)
	{
		if (i != 0)
			v.push_back(i);
	}

	int min_path = INT_MAX, min;

	while (std::next_permutation(v.begin(), v.end()))
	{
		int current_pathweight = 0;
		int k = 0;

		for (unsigned int i = 0; i < v.size(); i++)
		{
			current_pathweight += weightedGraph[k][v[i]];
			dist_min_path.push_back(weightedGraph[k][v[i]]);
			k = v[i];
		}
		current_pathweight += weightedGraph[k][0];
		dist_min_path.push_back(weightedGraph[k][0]);

		min = std::min(min_path, current_pathweight);
	}

}



bool Graph::notVisited(int v, std::vector<int> path)
{
	for (unsigned int i = 0; i < VERTICES; i++)
	{
		if (path.at(i) == v)
			return true;
	}
	
	return false;
}

void Graph::printAllPaths(std::vector<int> path)
{
	for (auto i = 0; i < path.size(); i++)
		std::cout << path.at(i) << " ";

	std::cout << std::endl;
}
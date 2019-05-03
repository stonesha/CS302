#pragma once

#include <iostream>
#include <algorithm>
#include <string>

#define VERTICES 5

class Graph
{
public:
	Graph();
	~Graph();

	void dijkstra(int src);
	int minDistance(int dist[], bool shortestPath[]);
	void printGraph(int dist[], std::string index[]);

private:

	/*
	Distances were obtained using Google Maps
	1 = Reno (R), 2 = San Francisco (SF), 3 = Salt Lake City(SLC),
	4 = Seattle(SE), 5 = Las Vegas(LV)
	*/
	
	int weightedGraph[VERTICES][VERTICES] =
	{	/*R   SF  SLC   SE   LV*/
/*R*/	{ 0, 218, 518, 705, 439 },
/*SF*/	{ 218, 0, 0, 807, 569 },
/*SLC*/	{ 518, 0, 0, 840, 421 },
/*SE*/	{ 705, 807, 840, 0, 1116 },
/*LV*/	{ 439, 569, 421, 1116, 0 },
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
	printVerticeWeights(dist, index);

}

int Graph::minDistance(int dist[], bool shortestPath[])
{
	int min_index, min = INT_MAX;

	for (int i = 0; i < VERTICES; i++)
		if (shortestPath[i] == false && dist[i] <= min)
			min = dist[i], min_index = i;

	return min_index;
}

void Graph::printGraph(int dist[], std::string index[])
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

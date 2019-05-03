#pragma once
#include <iostream>
#include <vector>
#define VERTICES 5

class Graph {
public:
	Graph();

	void DFS(int v);

protected:
	void DFS_rec(int v, bool visited[]);

private:
	/*
		Distances were obtained using Google Maps
		1 = Reno (R), 2 = San Francisco (SF), 3 = Salt Lake City(SLC),
		4 = Seattle(SE), 5 = Las Vegas(LV)
	*/
	int adjMatrix[VERTICES][VERTICES] =
	{	//R   SF  SLC   SE   LV
/*R*/	{ 0, 218, 518, 705, 439 },
/*SF*/	{ 218, 0, 735, 807, 569 },
/*SLC*/	{ 518, 735, 0, 840, 421 },
/*SE*/	{ 705, 807, 840, 0, 1116 },
/*LV*/	{ 439, 569, 421, 1116, 0 },
	};
			
};

Graph::Graph()
{
}

void Graph::DFS_rec(int v, bool visited[])
{

}

void Graph::DFS(int v)
{

}

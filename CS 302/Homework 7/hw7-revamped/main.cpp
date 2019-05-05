#include <iostream>
#include <vector>
#include <string>


int firstMin(Graph adj, int i)
{
	int min = INT_MAX;
	for (int j = 0; j < V; j++)
		if (adj[i][j] < min && i != j)
			min = adj[i][j];

	return min;
}

int secondMin(Graph adj, int i)
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

template <class T>
const void printVec(std::vector<T> v)
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		std::cout << v.at(i) << " ";
	}
	std::cout << std::endl;
}

VecInt TSPUtil(Graph adj, int curr_bound, int curr_weight, 
	int level, VecInt curr_path, VecBool visited, int final_weight)
{
	if (level == V)
	{
		if (adj[curr_path[level - 1]][curr_path[0]] != 0)
		{
			int curr_res = curr_weight + adj[curr_path[level - 1]][curr_path[0]];

			if (curr_res < final_weight)
			{
				final_weight = curr_res;
				return curr_path;
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

			if(level == 1)
				curr_bound -= ((firstMin(adj, curr_path[level - 1]) +
					firstMin(adj, i)) / 2);
			else
				curr_bound -= ((secondMin(adj, curr_path[level - 1]) +
					firstMin(adj, i)) / 2);

			if (curr_bound + curr_weight < final_weight)
			{
				curr_path[level] = i;
				visited[i] = true;
 
				TSPUtil(adj, curr_bound, curr_weight, level + 1,
					curr_path, visited, final_weight);
			}

			curr_weight -= adj[curr_path[level - 1]][i];
			curr_bound = temp;

			visited.assign(visited.size(), false);
			for (int j = 0; j <= level - 1; j++)
				visited[curr_path[j]] = true;
		}
	}
}

VecInt TSP(Graph adj, int &final_weight)
{

	VecInt curr_path;
	curr_path.resize(V + 1);

	VecBool visited;
	visited.resize(curr_path.size());

	int curr_bound = 0;

	curr_path.assign(curr_path.size(), -1);
	visited.assign(curr_path.size(), false);
	
	for (int i = 0; i < V; i++)
		curr_bound += (firstMin(adj, i) + secondMin(adj, i));

	curr_bound /= 2;
	
	visited[0] = true;
	curr_path[0] = 0;

	return TSPUtil(adj, curr_bound, 0, 1, curr_path, visited, final_weight);
}

int main()
{
	

	return 0;
}


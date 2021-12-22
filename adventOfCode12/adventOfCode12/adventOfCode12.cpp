// adventOfCode12.cpp :

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <list>

using namespace std;


class Graph {
	int V; // No. of vertices in graph
	long long int count;//Number of paths
	list<int>* adj; // Pointer to an array containing adjacency lists
    map<int, bool> largeCave;
	int visitedASmallCave;
	// A recursive function used by printAllPaths()
	void printAllPathsUtil(int, int, bool[], long int[],long int&);

public:
	
	
	Graph(int V); // Constructor
	void addEdge(int u, int v);
	void printAllPaths(int s, int d);
	void addLargeCave(int v);
	void printCount();
};




int main()
{
  	// Driver code
	
		// Create a graph given in the above diagram
		Graph g(13);
		g.addEdge(1, 3);
		g.addEdge(3, 11);
		g.addEdge(12, 5);
		g.addEdge(12, 1);
		g.addEdge(9, 8);
		g.addEdge(9, 7);
		g.addEdge(0, 1);
		g.addEdge(8, 11);
		g.addEdge(12, 6);
		g.addEdge(6, 9);
		g.addEdge(7, 5);
		g.addEdge(8, 2);
		g.addEdge(3, 8);
		g.addEdge(0, 11);
		g.addEdge(9, 11);
		g.addEdge(7, 1);
		g.addEdge(1, 11);
		g.addEdge(11, 7);
		g.addEdge(7, 8);
		g.addEdge(7, 6);
		g.addEdge(4, 2);
		g.addEdge(2, 9);
		g.addEdge(10, 5);
		g.addEdge(3, 0);
		g.addEdge(5, 9);
		g.addLargeCave(1);
		g.addLargeCave(4);
		g.addLargeCave(5);
		g.addLargeCave(6);
		g.addLargeCave(8);

	/*Graph g(6);
	g.addEdge(0, 1);
	g.addLargeCave(1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 2);
	g.addEdge(2, 4);
	g.addEdge(1, 5);
	g.addEdge(2, 5);*/

		int s = 0, d = 12;
		cout << "Following are all different paths from " << s << " to " << d << endl;
		g.printAllPaths(s, d);
		g.printCount();

    return 0;
}



Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
	count = 0;
	visitedASmallCave = -1;
}

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v); // Add v to u’s list.
	adj[v].push_back(u);//add u to v's list.
}

void Graph::addLargeCave(int v) {
	largeCave[v] = true;
}

void Graph::printCount()
{
	cout << count << endl;
}

// Prints all paths from 's' to 'd'
void Graph::printAllPaths(int s, int d)
{
	// Mark all the vertices as not visited
	bool* visited = new bool[V];
	

	// Create an array to store paths
	long int* path = new long int[V];
	long int path_index = 0; // Initialize path[] as empty

	// Initialize all vertices as not visited
	for (int i = 0; i < V; i++)
		visited[i] = false;
   
	// Call the recursive helper function to print all paths
	printAllPathsUtil(s, d, visited, path, path_index);
}

// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void Graph::printAllPathsUtil(int u, int d, bool visited[],
	long int path[], long int& path_index)
{
	
	// Mark the current node and store it in path[]
		if (visited[u] && !largeCave[u] && visitedASmallCave == -1&&u>0) {
		visitedASmallCave = u;
		
	}
	else {
		visited[u] = true;
	}

	/*visited[u] = true;*/
 	path[path_index] = u;
	path_index++;
	
	// If current vertex is same as destination, then print
	// current path[]
	if (u == d) {

		count++;
		
		/*cout << count << ": ";
		for (int i = 0; i < path_index; i++)
			cout << path[i] << " ";
		cout << endl;*/
		
	}
	else // If current vertex is not destination
	{
		// Recur for all the vertices adjacent to current vertex
		list<int>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
			
			if (!visited[*i] || largeCave[*i])
			{
				printAllPathsUtil(*i, d, visited, path, path_index);
			}
			else if (*i != 0 && visitedASmallCave == -1) {
				printAllPathsUtil(*i, d, visited, path, path_index);
			}
			
	}

	// Remove current vertex from path[] and mark it as unvisited
	path_index--;
	if (visitedASmallCave == u ) {
		visitedASmallCave = -1;
	}
	else {
		visited[u] = false;
	}
		/*visited[u] = false;*/
	
}
/*
Problem:    Directed Graph Implementation in C++ using STL
Idea:       use the STL vector class to implement the adjacency list representation of a graph
*/

#include <iostream>
#include <vector>
using namespace std;

// An edge
struct Edge
{
    int src, dest; // Source and Destination of the Edge
};

// A class to represent a graph
class Graph
{
public:
    // a vector of vectors to represent adjacency list
    vector<vector<int>> adjList;

    // Constructor
    Graph(vector<Edge> const &edges, int n)
    {
        adjList.resize(n);

        // add edges to the directed graph
        // auto keyword: automatically detects and assigns a data type to the variable with which it is used
        for (auto &edge : edges) // range-based for loop; simply = for edge in edges
        {
            adjList[edge.src].push_back(edge.dest);
        }
    }
};

// Print adjacency list of a graph
void printGraph(Graph const &graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        // current vertex number
        cout << i << " ——> ";
        // all neighboring vertices of current vertex
        for (int v : graph.adjList[i])
            cout << v << " ";
        cout << endl;
    }
}

int main()
{
    // collection of edges
    vector<Edge> edges = {{1, 2}, {2, 4}, {5, 4}, {4, 0}, {5, 6}, {5, 0}, {5, 2}, {0, 2}, {2, 3}, {3, 1}, {7, 3}, {3, 7}};
    // total number of vertex
    int n = 8;

    // construct graph
    Graph graph(edges, n);

    // print adjacency list
    printGraph(graph, n);

    return 0;
}
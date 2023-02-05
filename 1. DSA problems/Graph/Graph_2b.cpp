/*
Problem:    Directed Weighted Graph Implementation in C++ using STL
Idea:       use the STL vector class to implement the adjacency list representation of a graph
*/

#include <iostream>
#include <vector>
using namespace std;

// An graph edge
struct Edge
{
    int src, dest, weight;
};

typedef pair<int, int> Pair;

// A class to represent a graph object
class Graph
{
public:
    // a vector of vectors of Pairs to represent an adjacency list
    vector<vector<Pair>> adjList;

    // Constructor
    Graph(vector<Edge> const &edges, int n)
    {
        adjList.resize(n);

        // add edges to the directed graph
        for (auto &edge : edges)
        {
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;

            adjList[src].push_back(make_pair(dest, weight));
        }
    }
};

// Print adjacency list of a graph
void printGraph(Graph const &graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        // Function to print all neighboring vertices of current vertex i
        for (Pair v : graph.adjList[i])
        {
            cout << "(" << i << ", " << v.first << ", " << v.second << ") ";
        }
        cout << endl;
    }
}

int main()
{
    // Collection of deges with syntax: (src, dest, weight)
    vector<Edge> edges = {{1, 2, 1}, {2, 4, 2}, {5, 4, 3}, {4, 0, 4}, {5, 6, 5}, {5, 0, 6}, {5, 2, 7}, {0, 2, 8}, {2, 3, 9}};
    // total number of vertex
    int n = 7;

    // construct graph
    Graph graph(edges, n);

    // print adjacency list
    printGraph(graph, n);

    return 0;
}
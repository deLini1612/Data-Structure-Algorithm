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
 vector<Edge> edges =
    {
        // (x, y, w) —> edge from `x` to `y` having weight `w`
        {0, 1, 6}, {1, 2, 7}, {2, 0, 5}, {2, 1, 4}, {3, 2, 10}, {5, 4, 1}, {4, 5, 3}
    };
 
    // total number of nodes in the graph (labelled from 0 to 5)
    int n = 6;
 
    // construct graph
    Graph graph(edges, n);
 
    // print adjacency list representation of a graph
    printGraph(graph, n);
 
    return 0;
}
'''Depth First Search (DFS) Implementation for undirected graph
Problem: Traverse given by DFS algorithm (explores vertices as far as possible along each branch from the source vertex before backtracking)
Input: Graph (edges of Graph, number of vertex)
Output: Print the vertex of graph (in BFS algorithm order)
'''

# Idea:
# - Using a stack, push the source vertex, then pop it
# - Check whether the last pop vertex is discovered or not
#       + Discoverd -> ignore
#       + Undiscovered
#           * Mark it as discovered then print it
#           * Check for adjacent nodes of it and push to stack if it is undiscovered

# Iterative Implementation
from collections import deque
class Graph:
    """Graph class to represent a graph"""

    def __init__(self, edges, n, discovered = None):
        """Construction of a graph with 'n' vertexs and 'edges' is list of edges"""
        self.adjList = [[] for _ in range(n)]
        """List of lists to represent adjacency list"""
        self.discovered = [False] * n
        self.n = n
 
        for (src, dest) in edges:
            self.adjList[src].append(dest)
            self.adjList[dest].append(src)
 
    def DFSIterFromV(self, v):
        """DFS algorithm iterative implement with sourse vetex is vertex 'v'"""
        s = deque()
        s.append(v)
    
        while s:
            # pop a vertex from stack
            v = s.pop()
            # ignore if the vertex is discovered
            if self.discovered[v]:
                continue

            self.discovered[v] = True
            print(v, end=' ')
    
            # for every edge (v, u)
            adjList = self.adjList[v]
            for i in reversed(range(len(adjList))):
                u = adjList[i]
                if not self.discovered[u]:
                    # push it into stack
                    s.append(u)
    
    def DFSIter(self):
        """DFS algorithm iterative implement of graph"""
        for i in range(self.n):
            if not self.discovered[i]:
                # start DFS traversal from vertex i
                self.DFSIterFromV(i)

def main():
     # List of graph edges
    edges = [(1, 2), (1, 7), (1, 8), (2, 3), (2, 6), (3, 4),    (3, 5), (8, 9), (8, 12), (9, 10), (9, 11)]
    # Number of vertexs
    n = 13

    graph = Graph(edges, n)
    graph.DFSIter()

if __name__ == '__main__':
    main()
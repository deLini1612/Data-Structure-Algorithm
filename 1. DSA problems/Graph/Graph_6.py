'''Breadth-First Search (BFS) Implementation for undirected graph
Problem: Traverse given by BFS algorithm (explores vertices in the order of their distance from the source vertex)
Input: Graph (edges of Graph, number of vertex)
Output: Print the vertex of graph (in BFS algorithm order)
'''

# Idea:
# - Using a queue, enqueue the source vertex, then print it and dequeue it
# - Check for every neighbor vertex with the last dequeue element whether it has been discovered or not
#       + If it is not discovered, print it, mark that it is discovered and enqueue it
#       + If there is not any undiscovered neighbor vertex, dequeue the first element of queue then repeat the step 2

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
 
    def BFSIterFromV(self, v):
        """BFS algorithm iterative implement with sourse vetex is vertex 'v'"""
        q = deque()
        self.discovered[v] = True
        q.append(v)
    
        while q:
            # dequeue front node and print it
            v = q.popleft()
            print(v, end=' ')
    
            # for every edge (v, u)
            for u in self.adjList[v]:
                if not self.discovered[u]:
                    # mark it as discovered and enqueue it
                    self.discovered[u] = True
                    q.append(u)
    
    def BFSIter(self):
        """BFS algorithm iterative implement of graph"""
        for i in range(self.n):
            if not self.discovered[i]:
                # start BFS traversal from vertex i
                self.BFSIterFromV(i)
        
    def BFSRecurFrom(self, q):
        """BFS algorithm recursive implement of graph"""
        if not q:
            return
    
        # dequeue front node and print it
        v = q.popleft()
        print(v, end=' ')
    
        # do for every edge (v, u)
        for u in self.adjList[v]:
            if not self.discovered[u]:
                # mark it as discovered and enqueue it
                self.discovered[u] = True
                q.append(u)

        self.BFSRecurFrom(q)

    def BFSRecur(self):
        """BFS algorithm recursive implement of graph"""
        q = deque()
        for i in range(self.n):
            if not self.discovered[i]:
                # start BFS traversal from vertex i
                self.discovered[i] = True
                q.append(i)
                self.BFSRecurFrom(q)

def main():
     # List of graph edges
    edges = [(1, 2), (1, 3), (1, 4), (2, 5), (2, 6), (5, 9), (5, 10), (4, 7), (4, 8), (7, 11), (7, 12)]
    # Number of vertexs
    n = 15

    graph1 = Graph(edges, n)
    graph1.BFSIter()
    print("\n", end = "")
    graph2 = Graph(edges, n)
    graph2.BFSRecur()

if __name__ == '__main__':
    main()
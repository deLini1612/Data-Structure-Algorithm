import networkx as nx
import matplotlib.pyplot as plt
import numpy as np
from networkx.generators import connected_watts_strogatz_graph
from networkx.algorithms.shortest_paths.generic import average_shortest_path_length


def distance(node1,node2):
    '''Function to find distan between 2 node'''
    return np.sum(np.abs(np.array(node1)-node2))

def NavigationLength(G,source,des):
    '''Function to find Navigation Length from source to des'''
    node = source
    dist = distance(node,des)
    steps = 0
    while dist>0:
        neighbors = G.neighbors(node)
        distances = []
        for node1 in neighbors:
            distances+=[distance(node1, des)]
        index = np.argmin(distances)
       
        if distances[index]<dist:
            node=neighbors[index]
            dist=distances[index]
            steps+=1
    return steps

def AverageNavigationLength(L,r,Nnetworks,Nreps):
    '''Find L of network'''
    length=0
    for net in range(Nnetworks):
        G = nx.navigable_small_world_graph(L, p=1, q=1, r=r) 
        for rep in range(Nreps):
            source=tuple(np.random.randint(0,L,2))
            des=tuple(np.random.randint(0,L,2))
            steps=NavigationLength(G,source,des)
            length+=steps/float(Nnetworks*Nreps)
    return length
    
# Calculate the average shortest path length versus the number of nodes
range_L = np.arange(5, 30, 5)
range_n = range_L**2
range_r = [0, 2, 4]
results = np.zeros((len(range_n), len(range_r)))
for ixn, n in enumerate(range_n):
    L=range_L[ixn]
    for ixr, r in enumerate(range_r):
        # Create a Kleinberg network
        
        length = AverageNavigationLength(L,r,10,100)
        
        # Calculate the average shortest path of the network
        results[ixn,ixr] = length

# Plot figures
plt.figure(figsize=(16, 4), dpi=72)
plt.subplot(1,2,1)
plt.xlabel("Number of nodes")
plt.ylabel("Average delivery time")
plt.plot(range_n, results[:,0], 'or-', label=('r='+str(range_r[0])));
plt.plot(range_n, results[:,1], 'ob-', label=('r='+str(range_r[1])));
plt.plot(range_n, results[:,2], 'og-', label=('r='+str(range_r[2])));
plt.legend(loc='upper left', shadow=True)
plt.show()


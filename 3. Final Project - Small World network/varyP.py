import networkx as nx
import matplotlib.pyplot as plt
import numpy as np
from networkx.generators import connected_watts_strogatz_graph
from networkx.algorithms.shortest_paths.generic import average_shortest_path_length

# Set range for p
range_p = np.concatenate(([0], np.logspace(-4, 0, num=10)))
results_clus = np.zeros(len(range_p)) # Results of the clustering index
results_path = np.zeros(len(range_p)) # Results of the shortest path length

for i in range(4): # Calculate many times for more accurate result
    for ip, p in enumerate(range_p):
        G = connected_watts_strogatz_graph(100, 4, p, tries=100, seed=None)
        results_clus[ip] += nx.average_clustering(G)
        results_path[ip] += nx.average_shortest_path_length(G)
        
results_clus = results_clus/np.max(results_clus)
results_path = results_path/np.max(results_path)

# Plot figures
plt.figure(figsize=(16, 3))
plt.semilogx(range_p, results_clus, 'ob-', label=r"Clustering normalize C/C_{max}");
plt.semilogx(range_p, results_path, 'or-', label=r"Average path lengtht normalize L/L_{max}");
plt.legend(loc='lower left', shadow=True)
plt.xlabel('p')
plt.show()
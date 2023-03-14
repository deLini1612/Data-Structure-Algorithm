import matplotlib.pyplot as plt
import networkx as nx
import numpy as np
from networkx.generators import connected_watts_strogatz_graph
from networkx.algorithms.shortest_paths.generic import average_shortest_path_length

plt.figure(figsize = (12, 12))

# Create SW Model Small World
G1 = nx.watts_strogatz_graph(n = 8, k = 3, p = 0.7)
# Plot Network
plt.subplot(221)
nx.draw(G1,nx.circular_layout(G1))

# Create SW Connected Model
G2 = nx.connected_watts_strogatz_graph(n=8, k=3, p=0.7, tries =20)
plt.subplot(222)
nx.draw(G2, nx.circular_layout(G2))

# Create SW model by adding but not rewiring
G3 = nx.newman_watts_strogatz_graph(n=8, k=3, p=0.7)
plt.subplot(223)
nx.draw(G2, nx.circular_layout(G3))
plt.show()

print(nx.clustering(G1), nx.average_clustering(G1), nx.average_shortest_path_length(G1), nx.omega(G1), nx.sigma(G1))
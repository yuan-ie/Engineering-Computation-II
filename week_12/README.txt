graph_v03: loads graph.txt and finds the shortest path between
nodes a and y (its a 5x5 grid of nodes a through y)

graph_v04_a: Our first attempt at solving the hill-climb problem. This
code uses the data file to create the same type of graph data structure
used in graph_v03. This is very slow because of creating the graph
data structure. We are using an all-purpose graph data structure when
in reality we can cut a lot of corners to find a data structure thats better
suited for this particular problem.

graph_v04: uses the exact same dijkstra algorithm to find a path
from S to E in the hill-climb problem. Instead of using a formal
graph, it uses a grid (list-of-lists) to hold the hill altitudes
and a pair of dictionaries to keep track of our best-case transit
times to each node (different lists for completed and not-yet-completed
nodes). It works well but the implementation of dijkstra takes a good 
three seconds, which still leaves room for improvement. A close look 
shows that most of that time is taken searching for the priority node 
during each pass of the loop.

graph_v05: (in the week_13 folder) uses a priority queue (heap queue)
to find the min (next) node during each pass. Execution time down
to less than 100ms

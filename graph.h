#ifndef GRAPH_H
#define GRAPH_H
#include <limits.h>
#define MAX_NODES 20
#define INF INT_MAX
extern int adj_list[MAX_NODES][MAX_NODES];  // Weighted adjacency matrix (for simplicity; list convertible)
extern char node_names[MAX_NODES][20];      // Node names (Uttarakhand locations)
extern double lat_lng[MAX_NODES][2];        // Lat/long per node
void init_graph(void);  // Initialize Uttarakhand graph
#endif
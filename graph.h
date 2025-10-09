#ifndef GRAPH_H
#define GRAPH_H
#include <limits.h>
#define MAX_NODES 20
#define INF INT_MAX
extern int adj_list[MAX_NODES][MAX_NODES];  
extern char node_names[MAX_NODES][20];      
extern double lat_lng[MAX_NODES][2];        
void init_graph(void); 

#endif

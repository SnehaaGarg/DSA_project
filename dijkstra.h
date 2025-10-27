#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"

#define INF 1e9

typedef struct {
    double distance;
    int previous_node;
    int visited;
} PathInfo;

void dijkstra_shortest_path(Graph *graph, int start_node, int end_node, 
                           PathInfo path_info[], int path_nodes[], int *path_length);

#endif

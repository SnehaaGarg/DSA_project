#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "graph.h"
#include "priority_queue.h"
int compute_shortest_path(int start, int end, int* distances, int* previous, int* total_time); 
int reconstruct_path(int end, int* previous, char** path, int* path_len); 

#endif

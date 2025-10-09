#ifndef HASH_MAP_H
#define HASH_MAP_H
#include "graph.h"
int get_node_index(const char* name);  // Hash lookup: name -> index
double* get_coords(int index);         // Index -> lat/long
#endif
#include "hash_map.h"
#include <string.h>
extern char node_names[MAX_NODES][20];  // From graph.h
extern double lat_lng[MAX_NODES][2];
// Simple array-based "hash map" (linear search; fine for MAX_NODES=20)
int get_node_index(const char* name) {
    for (int i = 0; i < MAX_NODES; i++) {
        if (strcmp(node_names[i], name) == 0) {
            return i;
        }
    }
    return -1;  // Not found
}
// Retrieve coords (pointer to lat_lng[index])
double* get_coords(int index) {
    if (index >= 0 && index < MAX_NODES) {
        return lat_lng[index];
    }
    return NULL;
}
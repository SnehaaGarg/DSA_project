#include "hash_map.h"
#include <string.h>
extern char node_names[MAX_NODES][20];
extern double lat_lng[MAX_NODES][2];
int get_node_index(const char* name) {
    for (int i = 0; i < MAX_NODES; i++) {
        if (strcmp(node_names[i], name) == 0) {
            return i;
        }
    }
    return -1; 
}

double* get_coords(int index) {
    if (index >= 0 && index < MAX_NODES) {
        return lat_lng[index];
    }
    return NULL;

}

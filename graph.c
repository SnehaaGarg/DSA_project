#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include "graph.h"
#include "haversine.h"

void init_graph(Graph *graph) {
    graph->node_count = 0;
    graph->edge_count = 0;
}

int add_node(Graph *graph, int node_id, double lat, double lon, const char* name) {
    if (graph->node_count >= MAX_NODES) {
        return -1;
    }
    
    graph->nodes[graph->node_count].node_id = node_id;
    graph->nodes[graph->node_count].lat = lat;
    graph->nodes[graph->node_count].lon = lon;
    strncpy(graph->nodes[graph->node_count].name, name, MAX_NAME_LENGTH - 1);
    graph->node_count++;
    
    return graph->node_count - 1;
}

int add_edge(Graph *graph, int from_node, int to_node, double distance) {
    if (graph->edge_count >= MAX_NODES * 10) {
        return -1;
    }
    
    graph->edges[graph->edge_count].from_node = from_node;
    graph->edges[graph->edge_count].to_node = to_node;
    graph->edges[graph->edge_count].distance = distance;
    graph->edge_count++;
    
    return graph->edge_count - 1;
}

int find_nearest_node(Graph *graph, double lat, double lon) {
    if (graph->node_count == 0) return -1;
    
    int nearest_node = 0;
    double min_distance = DBL_MAX;
    
    for (int i = 0; i < graph->node_count; i++) {
        double distance = haversine_distance(lat, lon, 
                                           graph->nodes[i].lat, 
                                           graph->nodes[i].lon);
        if (distance < min_distance) {
            min_distance = distance;
            nearest_node = i;
        }
    }
    
    return nearest_node;
}

void load_graph_from_file(Graph *graph, const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }
    
    char line[256];
    // Skip header if exists
    fgets(line, sizeof(line), file);
    
    while (fgets(line, sizeof(line), file)) {
        int node_id1, node_id2;
        double lat1, lon1, lat2, lon2;
        char name1[100] = "Node", name2[100] = "Node";
        
        // Try different format parsing
        if (sscanf(line, "%d,%lf,%lf,%99[^,],%d,%lf,%lf,%99[^,\n]", 
                  &node_id1, &lat1, &lon1, name1,
                  &node_id2, &lat2, &lon2, name2) == 8) {
            // Format with names
        } else if (sscanf(line, "%d,%lf,%lf,%d,%lf,%lf", 
                         &node_id1, &lat1, &lon1, &node_id2, &lat2, &lon2) == 6) {
            // Format without names
            snprintf(name1, sizeof(name1), "Node%d", node_id1);
            snprintf(name2, sizeof(name2), "Node%d", node_id2);
        } else {
            continue; // Skip invalid lines
        }
        
        // Add nodes if they don't exist
        int node1_index = -1, node2_index = -1;
        
        for (int i = 0; i < graph->node_count; i++) {
            if (graph->nodes[i].node_id == node_id1) node1_index = i;
            if (graph->nodes[i].node_id == node_id2) node2_index = i;
        }
        
        if (node1_index == -1) {
            node1_index = add_node(graph, node_id1, lat1, lon1, name1);
        }
        if (node2_index == -1) {
            node2_index = add_node(graph, node_id2, lat2, lon2, name2);
        }
        
        // Calculate distance and add edge
        double distance = haversine_distance(lat1, lon1, lat2, lon2);
        add_edge(graph, node1_index, node2_index, distance);
    }
    
    fclose(file);
}

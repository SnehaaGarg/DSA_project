#include <stdio.h>
#include <float.h>
#include "dijkstra.h"

int find_min_distance_node(PathInfo path_info[], int node_count) {
    int min_index = -1;
    double min_distance = INF; 
    
    for (int i = 0; i < node_count; i++) {
        if (!path_info[i].visited && path_info[i].distance < min_distance) {
            min_distance = path_info[i].distance;
            min_index = i;
        }
    }
    
    return min_index;
}

void dijkstra_shortest_path(Graph *graph, int start_node, int end_node,PathInfo path_info[], int path_nodes[], int *path_length) {
    // Initialize path info
    for (int i = 0; i < graph->node_count; i++) {
        path_info[i].distance = INF;
        path_info[i].previous_node = -1;
        path_info[i].visited = 0;
    }
    
    path_info[start_node].distance = 0;
    
    for (int count = 0; count < graph->node_count - 1; count++) {
        int current = find_min_distance_node(path_info, graph->node_count);
        
        if (current == -1 || current == end_node) {
            break;
        }
        
        path_info[current].visited = 1;
        
        // Update distances for all adjacent nodes
        for (int i = 0; i < graph->edge_count; i++) {
            if (graph->edges[i].from_node == current) {
                int neighbor = graph->edges[i].to_node;
                double new_distance = path_info[current].distance + graph->edges[i].distance;
                
                if (new_distance < path_info[neighbor].distance) {
                    path_info[neighbor].distance = new_distance;
                    path_info[neighbor].previous_node = current;
                }
            }
        }
    }
    
    // Reconstruct path
    *path_length = 0;
    int current = end_node;
    
    while (current != -1) {
        path_nodes[(*path_length)++] = current;
        current = path_info[current].previous_node;
    }
    
    // Reverse the path
    for (int i = 0; i < *path_length / 2; i++) {
        int temp = path_nodes[i];
        path_nodes[i] = path_nodes[*path_length - i - 1];
        path_nodes[*path_length - i - 1] = temp;
    }
}


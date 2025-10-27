#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NODES 1000
#define MAX_NAME_LENGTH 100

typedef struct {
    int node_id;
    double lat;
    double lon;
    char name[MAX_NAME_LENGTH];
} Node;

typedef struct {
    int from_node;
    int to_node;
    double distance;
} Edge;

typedef struct {
    Node nodes[MAX_NODES];
    Edge edges[MAX_NODES * 10];
    int node_count;
    int edge_count;
} Graph;

void init_graph(Graph *graph);
int add_node(Graph *graph, int node_id, double lat, double lon, const char* name);
int add_edge(Graph *graph, int from_node, int to_node, double distance);
int find_nearest_node(Graph *graph, double lat, double lon);
void load_graph_from_file(Graph *graph, const char* filename);

#endif

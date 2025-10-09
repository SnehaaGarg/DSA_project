#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
typedef struct {
    int* heap;     // Array of node indices
    int* distances; // Reference to distances array (for key comparison)
    int size;
    int capacity;
} PQ;
PQ* pq_create(int capacity, int* dist_array);  // Init with dist ref
void pq_free(PQ* pq);
void pq_insert(PQ* pq, int node);              // Insert node (key = distances[node])
int pq_extract_min(PQ* pq);                    // Extract min node
#endif
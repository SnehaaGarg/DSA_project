#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
typedef struct {
    int* heap;    
    int* distances; 
    int size;
    int capacity;
} PQ;
PQ* pq_create(int capacity, int* dist_array);  
void pq_free(PQ* pq);
void pq_insert(PQ* pq, int node);            
int pq_extract_min(PQ* pq);                 

#endif

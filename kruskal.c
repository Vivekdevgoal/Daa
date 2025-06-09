#include <stdio.h> 
#include <stdlib.h> 
#define MAX_EDGES 100 
// Structure to represent an edge with source, destination, and weight 
typedef struct { 
int src, dest, weight; 
} Edge; 
// Graph structure with vertices and edges 
typedef struct { 
int V, E; 
Edge edges[MAX_EDGES]; 
} Graph; 
// Disjoint Set (Union-Find) for cycle detection 
typedef struct { 
int parent; 
int rank; 
} Subset; 
// Function to compare edges for sorting (ascending order of weight) 
int compareEdges(const void *a, const void *b) { 
return ((Edge *)a)->weight - ((Edge *)b)->weight; 
} 
// Function to find the root of a set with path compression 
int find(Subset subsets[], int node) { 
if (subsets[node].parent != node) { 
subsets[node].parent = find(subsets, subsets[node].parent); 
} 
return subsets[node].parent; 
} 
// Function to unite two sets using union by rank 
void unionSets(Subset subsets[], int root1, int root2) { 
if (subsets[root1].rank < subsets[root2].rank) { 
subsets[root1].parent = root2; 
} else if (subsets[root1].rank > subsets[root2].rank) { 
subsets[root2].parent = root1; 
} else { 
subsets[root2].parent = root1; 
subsets[root1].rank++; 
} 
} 
// Kruskal's algorithm to find the Minimum Spanning Tree (MST) 
void kruskalMST(Graph *graph) { 
int V = graph->V; 
Edge result[V - 1]; // Store MST edges 
int edgeCount = 0;  // Number of edges added to MST 
int index = 0;      
// Index for sorted edges 
// Step 1: Sort edges by weight 
qsort(graph->edges, graph->E, sizeof(Edge), compareEdges); 
// Step 2: Initialize subsets for Union-Find 
Subset subsets[V]; 
for (int i = 0; i < V; i++) { 
subsets[i].parent = i; 
subsets[i].rank = 0; 
} 
// Step 3: Pick the smallest edges while avoiding cycles 
while (edgeCount < V - 1 && index < graph->E) { 
Edge nextEdge = graph->edges[index++]; 
int root1 = find(subsets, nextEdge.src); 
int root2 = find(subsets, nextEdge.dest); 
// If including this edge does not form a cycle, add it to MST 
if (root1 != root2) { 
result[edgeCount++] = nextEdge; 
unionSets(subsets, root1, root2); 
} 
} 
// Display the result 
printf("\nEdges in the Minimum Spanning Tree:\n"); 
int totalWeight = 0; 
for (int i = 0; i < edgeCount; i++) { 
printf("%d -- %d (Weight: %d)\n", result[i].src, result[i].dest, 
result[i].weight); 
totalWeight += result[i].weight; 
} 
printf("Total Weight of MST: %d\n", totalWeight); 
} 
// Main function to input graph details and run Kruskal's Algorithm 
int main() { 
Graph graph; 
printf("Enter number of vertices and edges: "); 
scanf("%d %d", &graph.V, &graph.E); 
printf("Enter edges (source destination weight):\n"); 
for (int i = 0; i < graph.E; i++) { 
scanf("%d %d %d", &graph.edges[i].src, &graph.edges[i].dest, 
&graph.edges[i].weight); 
} 
kruskalMST(&graph); 
return 0; 
} 


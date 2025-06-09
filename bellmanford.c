#include <stdio.h> 
#include <stdlib.h> 
#define INF 99999 
struct Edge { 
int src, dest, weight; 
}; 
void bellmanFord(struct Edge edges[], int V, int E, int src) { 
int dist[V]; 
for (int i = 0; i < V; i++) 
dist[i] = INF; 
dist[src] = 0; 
for (int i = 1; i <= V - 1; i++) { 
for (int j = 0; j < E; j++) { 
int u = edges[j].src; 
int v = edges[j].dest; 
int w = edges[j].weight; 
if (dist[u] != INF && dist[u] + w < dist[v]) 
dist[v] = dist[u] + w; 
} 
} 
// Check for negative-weight cycles 
for (int j = 0; j < E; j++) { 
int u = edges[j].src; 
int v = edges[j].dest; 
int w = edges[j].weight; 
if (dist[u] != INF && dist[u] + w < dist[v]) { 
printf("Graph contains a negative weight cycle\n"); 
return; 
} 
} 
printf("Vertex \t Distance from Source %d\n", src); 
for (int i = 0; i < V; i++) 
printf("%d \t %d\n", i, dist[i]); 
} 
int main() { 
int V, E; 
printf("Enter number of vertices and edges: "); 
scanf("%d%d", &V, &E); 
struct Edge edges[E]; 
printf("Enter each edge in format (source destination weight):\n"); 
for (int i = 0; i < E; i++) { 
scanf("%d%d%d", &edges[i].src, &edges[i].dest, &edges[i].weight); 
} 
int src; 
printf("Enter the source vertex: "); 
scanf("%d", &src); 
bellmanFord(edges, V, E, src); 
return 0; 
}

#include <stdio.h> 
#include <limits.h> 
#define V 100 
int minKey(int key[], int visited[], int n) { 
int min = INT_MAX, min_index; 
for (int v = 0; v < n; v++) 
if (!visited[v] && key[v] < min) 
min = key[v], min_index = v; 
return min_index; 
} 
void primMST(int graph[V][V], int n) { 
int parent[V]; 
int key[V]; 
int visited[V]; 
int totalWeight = 0; 
for (int i = 0; i < n; i++) { 
key[i] = INT_MAX; 
visited[i] = 0; 
} 
key[0] = 0; 
parent[0] = -1; 
for (int count = 0; count < n - 1; count++) { 
int u = minKey(key, visited, n); 
visited[u] = 1; 
for (int v = 0; v < n; v++) 
if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) { 
parent[v] = u; 
key[v] = graph[u][v]; 
} 
} 
printf("Edge \tWeight\n"); 
for (int i = 1; i < n; i++) { 
printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]); 
totalWeight += graph[i][parent[i]]; 
} 
printf("Total weight of Minimum Spanning Tree: %d\n", totalWeight); 
} 
int main() { 
int n; 
printf("Enter number of vertices: "); 
scanf("%d", &n); 
int graph[V][V]; 
printf("Enter the adjacency matrix (use 0 for no direct edge):\n"); 
for (int i = 0; i < n; i++) 
for (int j = 0; j < n; j++) 
scanf("%d", &graph[i][j]); 
primMST(graph, n); 
return 0; 
}

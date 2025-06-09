#include <stdio.h> 
#define V 100 
#define INF 99999 
void floydWarshall(int graph[V][V], int n) { 
int dist[V][V]; 
// Step 1: Initialize distance matrix 
for (int i = 0; i < n; i++) 
for (int j = 0; j < n; j++) 
dist[i][j] = graph[i][j]; 
// Step 2: Update distances using intermediate vertices 
for (int k = 0; k < n; k++) { 
for (int i = 0; i < n; i++) { 
for (int j = 0; j < n; j++) { 
if (dist[i][k] + dist[k][j] < dist[i][j]) 
dist[i][j] = dist[i][k] + dist[k][j]; 
} 
} 
} 
// Step 3: Print the result 
printf("Shortest distances between every pair of vertices:\n"); 
for (int i = 0; i < n; i++) { 
for (int j = 0; j < n; j++) { 
if (dist[i][j] == INF) 
printf("INF "); 
else 
printf("%3d ", dist[i][j]); 
} 
printf("\n"); 
} 
} 
int main() { 
int n; 
printf("Enter number of vertices: "); 
scanf("%d", &n); 
int graph[V][V]; 
printf("Enter the adjacency matrix (use %d for INF / no edge):\n", INF); 
for (int i = 0; i < n; i++) 
for (int j = 0; j < n; j++) 
scanf("%d", &graph[i][j]); 
floydWarshall(graph, n); 
return 0; 
} 

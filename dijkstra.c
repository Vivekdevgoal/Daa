#include <stdio.h> 
#include <limits.h> 
#define V 100 // Max number of vertices 
int minDistance(int dist[], int visited[], int n) { 
int min = INT_MAX, min_index; 
for (int v = 0; v < n; v++) 
if (!visited[v] && dist[v] <= min) 
min = dist[v], min_index = v; 
return min_index; 
} 
void dijkstra(int graph[V][V], int src, int n) { 
int dist[V]; // Output array 
int visited[V]; // Visited set 
for (int i = 0; i < n; i++) { 
dist[i] = INT_MAX; 
visited[i] = 0; 
} 
dist[src] = 0; 
for (int count = 0; count < n - 1; count++) { 
int u = minDistance(dist, visited, n); 
visited[u] = 1; 
for (int v = 0; v < n; v++) 
if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && 
dist[u] + graph[u][v] < dist[v]) 
dist[v] = dist[u] + graph[u][v]; 
} 
// Output 
printf("Vertex \t\t Distance from Source %d\n", src); 
for (int i = 0; i < n; i++) 
printf("%d \t\t %d\n", i, dist[i]); 
} 
int main() { 
int n; // Number of vertices 
printf("Enter number of vertices: "); 
scanf("%d", &n); 
int graph[V][V]; 
printf("Enter the adjacency matrix (use 0 for no direct edge):\n"); 
for (int i = 0; i < n; i++) 
for (int j = 0; j < n; j++) 
scanf("%d", &graph[i][j]); 
int src; 
printf("Enter the source vertex: "); 
scanf("%d", &src); 
dijkstra(graph, src, n); 
return 0; 
}

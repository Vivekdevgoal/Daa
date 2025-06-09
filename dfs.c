#include <stdio.h> 
#define MAX 100 
int graph[MAX][MAX], visited[MAX]; 
int n; // number of vertices 
void DFS(int vertex) { 
printf("%d ", vertex); 
visited[vertex] = 1; 
for (int i = 0; i < n; i++) { 
if (graph[vertex][i] && !visited[i]) { 
DFS(i); 
} 
} 
} 
int main() { 
int i, j, start; 
printf("Enter number of vertices: "); 
scanf("%d", &n); 
printf("Enter adjacency matrix (use 1 if edge exists, otherwise 0):\n"); 
for (i = 0; i < n; i++) { 
for (j = 0; j < n; j++) { 
scanf("%d", &graph[i][j]); 
} 
} 
for (i = 0; i < n; i++) { 
visited[i] = 0; 
} 
printf("Enter starting vertex for DFS: "); 
scanf("%d", &start); 
printf("DFS Traversal starting from vertex %d:\n", start); 
DFS(start); 
return 0; 
}

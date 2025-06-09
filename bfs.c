#include <stdio.h> 
#define MAX 100 
int graph[MAX][MAX], visited[MAX], queue[MAX]; 
int front = 0, rear = -1; 
int n; 
void BFS(int start) { 
visited[start] = 1; 
queue[++rear] = start; 
while (front <= rear) { 
int vertex = queue[front++]; 
printf("%d ", vertex); 
for (int i = 0; i < n; i++) { 
if (graph[vertex][i] && !visited[i]) { 
visited[i] = 1; 
queue[++rear] = i; 
} 
} 
} 
} 
int main() { 
int i, j, start; 
printf("Enter number of vertices: "); 
scanf("%d", &n); 
printf("Enter adjacency matrix:\n"); 
for (i = 0; i < n; i++) { 
for (j = 0; j < n; j++) { 
scanf("%d", &graph[i][j]); 
} 
} 
for (i = 0; i < n; i++) { 
visited[i] = 0; 
} 
printf("Enter starting vertex for BFS: "); 
scanf("%d", &start); 
printf("BFS Traversal starting from vertex %d:\n", start); 
BFS(start); 
return 0; 
} 

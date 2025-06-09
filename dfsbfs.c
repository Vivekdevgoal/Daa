#include <stdio.h>
#define MAX 100

int graph[MAX][MAX], visited[MAX], queue[MAX];
int n, front = 0, rear = -1;

// DFS Function
void DFS(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] && !visited[i]) {
            DFS(i);
        }
    }
}

// BFS Function
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

// Reset visited array
void resetVisited() {
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    front = 0;
    rear = -1;
}

int main() {
    int i, j, start, choice;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (1 for edge, 0 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("\nChoose Traversal Method:\n");
    printf("1. DFS (Depth-First Search)\n");
    printf("2. BFS (Breadth-First Search)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            resetVisited();
            printf("DFS Traversal starting from vertex %d:\n", start);
            DFS(start);
            break;
        case 2:
            resetVisited();
            printf("BFS Traversal starting from vertex %d:\n", start);
            BFS(start);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}


#include <stdio.h>

#define MAX 100

int adjacencyMatrix[MAX][MAX];
int visited[MAX];
int numVertices;

void dfs(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < numVertices; i++) {
        if (adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    printf("Depth-First Search starting from vertex %d:\n", startVertex);
    dfs(startVertex);

    return 0;
}
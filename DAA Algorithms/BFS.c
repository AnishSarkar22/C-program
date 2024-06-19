#include <stdio.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
int adjacencyMatrix[MAX][MAX];
int visited[MAX];

void enqueue(int value) {
    if (rear == MAX - 1)
        printf("\nQueue is Full!!");
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
    }
}

int dequeue() {
    int value;
    if (front == -1)
        printf("\nQueue is Empty!!");
    else {
        value = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return value;
    }
    return -1; // If queue is empty, return -1
}

int isEmpty() {
    if (front == -1)
        return 1;
    else
        return 0;
}

void bfs(int startVertex, int numVertices) {
    int i, currentVertex;
    for (i = 0; i < numVertices; i++) {
        visited[i] = 0; // Mark all vertices as not visited
    }

    enqueue(startVertex);
    visited[startVertex] = 1;

    while (!isEmpty()) {
        currentVertex = dequeue();
        printf("%d ", currentVertex);

        for (i = 0; i < numVertices; i++) {
            if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int numVertices, i, j, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("Breadth-First Search starting from vertex %d:\n", startVertex);
    bfs(startVertex, numVertices);

    return 0;
}
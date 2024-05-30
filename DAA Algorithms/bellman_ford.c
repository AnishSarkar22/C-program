#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define E 6
#define V 4

typedef struct e {
    int u;
    int v;
    int weight;
} Edge;

void bellman(Edge edge[], int src);
void printSol(int dist[]);

int main() {
    Edge edge[E];
    int i;
    for (i = 0; i < E; i++) {
        printf("Enter the edge in the format (u, v, weight) %d:\n", i + 1);
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].weight);
    }

    bellman(edge, 0);

    return 0;
}

void bellman(Edge edge[], int src) {
    int i, j;
    int dist[V];

    for (i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    for (i = 1; i <= V - 1; i++) {
        for (j = 0; j < E; j++) {
            int u = edge[j].u;
            int v = edge[j].v;
            int weight = edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (j = 0; j < E; j++) {
        int u = edge[j].u;
        int v = edge[j].v;
        int weight = edge[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    printSol(dist);
}

void printSol(int dist[]) {
    int i;
    for (i = 0; i < V; i++) {
        printf("%d\t\t\t%d\n", i, dist[i]);
    }
}
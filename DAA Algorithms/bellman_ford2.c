#include <stdio.h>
#include <limits.h>

#define MAX_NODES 5
#define INFINITY 99999

void bellmanFord(int n, int src, int cost[MAX_NODES][MAX_NODES], int dist[]) {
    // Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INFINITY; // Set the initial distance to infinity
    }
    dist[src] = 0; // Set the distance of the source vertex to 0

    // Relax edges repeatedly
    for (int k = 0; k < n - 1; k++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (cost[u][v] != INFINITY && dist[u] != INFINITY && dist[u] + cost[u][v] < dist[v]) {
                    dist[v] = dist[u] + cost[u][v]; // Update the distance
                }
            }
        }
    }

   // Check for negative weight cycles
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (cost[u][v] != INFINITY && dist[u] != INFINITY && dist[u] + cost[u][v] < dist[v]) {
                printf("Graph contains negative weight cycle\n");
                return;
            }
        }
    }

    printf("Source \t Distance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d \t %d\n", i, dist[i]);
}

int main() {
    int cost[MAX_NODES][MAX_NODES];
    int dist[MAX_NODES];
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 6, 5, INFINITY, INFINITY},
        {INFINITY, 0, 2, 4, INFINITY},
        {INFINITY, INFINITY, 0, 3, 3},
        {INFINITY, INFINITY, INFINITY, 0, 1},
        {INFINITY, INFINITY, INFINITY, INFINITY, 0}
    };

    // Copy graph to cost matrix
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            cost[i][j] = graph[i][j];
        }
    }

    int src = 0; // Source office is Jadavpur
    bellmanFord(MAX_NODES, src, cost, dist);

    return 0;
}


/* ALGORITHM:
function bellmanFord(n, src, cost, dist):
    # Step 1: Initialization
    for i from 1 to n:
        dist[i] = INFINITY
    dist[src] = 0

    # Step 2: Relaxation
    for k from 1 to n-1:
        for u from 1 to n:
            for v from 1 to n:
                if cost[u][v] != INFINITY and dist[u] != INFINITY:
                    if dist[u] + cost[u][v] < dist[v]:
                        dist[v] = dist[u] + cost[u][v]

    # Step 3: Negative Weight Cycle Check
    for u from 1 to n:
        for v from 1 to n:
            if cost[u][v] != INFINITY and dist[u] != INFINITY:
                if dist[u] + cost[u][v] < dist[v]:
                    print "Graph contains negative weight cycle"
                    return

    # Output the distances
    for i from 1 to n:
        if i != src:
            if dist[i] == INFINITY:
                print "Vertex", src, "to", i, ": No path"
            else:
                print "Vertex", src, "to", i, ":", dist[i]
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define V 4

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int visitedSet[]);

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[V][V], int src);

int main()
{
    // Graph represented as an adjacency matrix
    int graph[V][V] = {{0, 4, 0, 0},
                       {4, 0, 8, 0},
                       {0, 8, 0, 7},
                       {0, 0, 7, 0}};

    // Run Dijkstra's algorithm from source vertex 0
    dijkstra(graph, 0);

    return 0;
}

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int visitedSet[])
{
    int min = INT_MAX, minIndex, i;

    // Iterate over all vertices to find the minimum distance vertex
    for (i = 0; i < V; i++)
    {
        if (visitedSet[i] == false && dist[i] < min)
        {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[V][V], int src)
{
    int dist[V];       // Array to hold the shortest distance from src to each vertex
    int visitedSet[V]; // Array to track visited vertices
    int i;

    // Initialize all distances as INFINITE and visitedSet[] as false
    for (i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visitedSet[i] = 0;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (i = 0; i < V; i++)
    {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, visitedSet);
        int v;

        // Mark the picked vertex as processed
        visitedSet[u] = 1;

        // Update dist[v] only if it is not in visitedSet, there is an edge from u to v,
        // and total weight of path from src to v through u is smaller than current value of dist[v]
        for (v = 0; v < V; v++)
        {
            if ((visitedSet[v] == false) && (dist[u] + graph[u][v] < dist[v]) && graph[u][v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printSol(dist);
}

// Function to print the constructed distance array
void printSol(int dist[])
{
    int i;
    printf("Vertex\t\tDistance from Source\n");
    for (i = 0; i < V; i++)
    {
        printf("%d\t\t\t%d\n", i, dist[i]);
    }
}

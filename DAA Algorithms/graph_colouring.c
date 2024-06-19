#include <stdio.h>

#define V 4  // Number of vertices
#define COLORS 3  // Number of colors

// Function to check if a color can be assigned to a vertex
int isSafe(int vertex, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] && color[i] == c) {
            return 0;  // Adjacent vertex has the same color
        }
    }
    return 1;  // Color can be assigned safely
}

// Recursive function to solve the graph coloring problem
int graphColoring(int vertex, int graph[V][V], int color[]) {
    if (vertex == V) {
        return 1;  // All vertices have been colored successfully
    }

    for (int c = 1; c <= COLORS; c++) {
        if (isSafe(vertex, graph, color, c)) {
            color[vertex] = c;  // Assign color to the vertex
            if (graphColoring(vertex + 1, graph, color)) {
                return 1;  // Coloring successful
            }
            color[vertex] = 0;  // Backtrack and try a different color
        }
    }

    return 0;  // No solution found
}

int main() {
    int graph[V][V] = {{0, 1, 1, 1},
                       {1, 0, 1, 0},
                       {1, 1, 0, 1},
                       {1, 0, 1, 0}};

    int color[V] = {0};

    if (graphColoring(0, graph, color)) {
        printf("Solution exists:\n");
        for (int i = 0; i < V; i++) {
            printf("Vertex %d -> Color %d\n", i, color[i]);
        }
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
// this code is found online

#include <stdio.h>
#include <limits.h>

#define V 6

int selectMinVertex(int value[], int processed[])
{
    int minimum = INT_MAX;
    int vertex;
    for(int i=0; i<V; ++i)
    {
        if(processed[i]==0 && value[i]<minimum)
        {
            vertex = i;
            minimum = value[i];
        }
    }
    return vertex;
}

void dijkstra(int graph[V][V])
{
    int parent[V]; 
    int value[V]; 
    int processed[V]; 

    for(int i=0; i<V; ++i)
    {
        value[i] = INT_MAX;
        processed[i] = 0;
    }

    parent[0] = -1; 
    value[0] = 0; 

    for(int i=0; i<V-1; ++i)
    {
        int U = selectMinVertex(value,processed);
        processed[U] = 1; 

        for(int j=0; j<V; ++j)
        {
            if(graph[U][j]!=0 && processed[j]==0 && value[U]!=INT_MAX
            && (value[U]+graph[U][j] < value[j]))
            {
                value[j] = value[U]+graph[U][j];
                parent[j] = U;
            }
        }
    }

    for(int i=1; i<V; ++i)
        printf("U->V: %d->%d  wt = %d\n", parent[i], i, graph[parent[i]][i]);
}

int main()
{
    int graph[V][V] = { {0, 1, 4, 0, 0, 0},
                        {1, 0, 4, 2, 7, 0},
                        {4, 4, 0, 3, 5, 0},
                        {0, 2, 3, 0, 4, 6},
                        {0, 7, 5, 4, 0, 7},
                        {0, 0, 0, 6, 7, 0} };

    dijkstra(graph);    
    return 0;
}

//TIME COMPLEXITY: O(V^2)
//TIME COMPLEXITY: (using Min-Heap + Adjacency_List): O(ElogV)
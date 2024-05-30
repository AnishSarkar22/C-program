#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define E 6
#define V 4

typedef struct e{
    int u;
    int v;
    int weight;
} Edge;

int main()
{

    struct e edge[E];
    int i;
    for(i=0;i<E;i++){
        printf("Enter the edge in the format(u,v,wieght) %d:\n",i+1);
        scanf("%d", &edge[i].u);
        scanf("%d", &edge[i].v);
        scanf("%d", &edge[i].weight);
    }



    bellman(edge,0);

    return 0;
}

void bellman(struct e edge[], int src){

    int i,j;

    int dist[V];

    for(i=0;i<V;i++){
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    for(i=0;i<V;i++){
        for(j=0;j<E;j++){
            int u = edge[i].u;
            int v = edge[i].v;
            int weight = edge[i].weight;
            if(dist[u]+weight < dist[v]){
                dist[v] = dist[u]+weight;
            }
        }
    }

    printSol(dist);

}

void printSol(int dist[]){

    int i;
    for(i=0;i<V;i++){
        printf("%d\t\t\t%d\n", i, dist[i]);
    }

}

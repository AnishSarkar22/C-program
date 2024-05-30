#include <stdio.h>
#include <stdlib.h>

void knapsack(int n, int weight[], int capacity, int profit[]);

int main()
{
    int n, capacity, i, j;

    printf("Enter the number of objects: ");
    scanf("%d", &n);

    printf("Enter the capacity: ");
    scanf("%d", &capacity);

    int weight[n];
    int profit[n];
    float ratio[n];

    for(i = 0; i < n; i++){
        printf("Enter the weight of object %d: ", i + 1);
        scanf("%d", &weight[i]);
        printf("Enter the profit of object %d: ", i + 1);
        scanf("%d", &profit[i]);
        ratio[i] = (float)profit[i] / weight[i];
    }

    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(ratio[i] < ratio[j]){
                float temp1 = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp1;

                int temp2 = weight[i];
                weight[i] = weight[j];
                weight[j] = temp2;

                int temp3 = profit[i];
                profit[i] = profit[j];
                profit[j] = temp3;
            }
        }
    }

    knapsack(n, weight, capacity, profit);

    return 0;
}

void knapsack(int n, int weight[], int capacity, int profit[]){
    float tp = 0;
    float x[n];
    int i;
    for(i = 0; i < n; i++){
        x[i] = 0;
    }

    for(i = 0; i < n; i++){
        if(weight[i] > capacity){
            break;
        }
        else{
            x[i] = 1;
            capacity = capacity - weight[i];
            tp = tp + profit[i];
        }
    }

    if(i < n){
        float frac = (float)capacity / weight[i];
        x[i] = frac;
        tp = tp + profit[i] * frac;
    }

    printf("Profit Vector: \n");
    for(i = 0; i < n; i++){
        printf("%f ", x[i]);
    }

    printf("\nTotal Profit: %f\n", tp);
}

#include <stdio.h>
#include <limits.h>
#include <string.h> // For memset

#define MAX_N 15 // Maximum number of cities

int n = 4; // Number of cities
int cost[MAX_N][MAX_N] = {
    {0, 10, 15, 20},
    {5, 0,  9,  10},
    {6, 13, 0,  12},
    {8, 8,  9,  0}
}; // Cost matrix
int dp[1 << MAX_N][MAX_N]; // Dynamic programming table

// Define the min function
int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return cost[pos][0]; // Return to the starting city
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;
    for (int next = 0; next < n; next++) {
        if ((mask & (1 << next)) == 0) { // If city 'next' is not visited
            int newCost = cost[pos][next] + tsp(mask | (1 << next), next);
            ans = min(ans, newCost);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp)); // Initialize dp array with -1

    int minCost = tsp(1, 0); // Start from city 0 with mask 1 (only city 0 visited)

    printf("Minimum cost of the TSP: %d\n", minCost);

    return 0;
}

#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 10000

int knapSack(int W, int wt[MAX_ITEMS], int val[MAX_ITEMS], int n) {
    int dp[MAX_ITEMS][MAX_WEIGHT + 1];

    // Initialize the DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W]; // Return the maximum value
}

int max(int a, int b) {
    return (a > b)? a : b;
}

int main() {
    int val[MAX_ITEMS] = {60, 100, 120}; // Values of items
    int wt[MAX_ITEMS] = {10, 20, 30}; // Weights of items
    int W = 50; // Maximum weight the knapsack can carry
    int n = sizeof(val) / sizeof(val[0]); // Number of items

    printf("Maximum value that can be put in knapsack = %d\n", knapSack(W, wt, val, n));

    return 0;
}

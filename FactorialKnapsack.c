#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 10000

int knapSack(int W, int wt[MAX_ITEMS], int val[MAX_ITEMS], int n) {
    int i, w;
    int K[MAX_WEIGHT + 1];

    /* Initialize K[0..W] as 0 */
    for (w = 0; w <= W; w++)
        K[w] = 0;

    /* Build table K[][] in bottom up manner */
    for (i = 1; i <= n; i++) {
        for (w = 1; w <= W; w++) {
            if (wt[i - 1] <= w)
                K[w] = max(val[i - 1] + K[w - wt[i - 1]], K[w]);
            else
                K[w] = K[w];
        }
    }

    return K[W]; // Return result
}

/* Helper function that returns maximum of two integers */
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

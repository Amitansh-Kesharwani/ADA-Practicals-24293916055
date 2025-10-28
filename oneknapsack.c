#include <stdio.h>
#include <time.h>

// Function to get max of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// 0/1 Knapsack using Dynamic Programming
int zeroOneKnapsack(int value[], int weight[], int n, int W) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i - 1] <= w)
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int value[n], weight[n];

    printf("Enter value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d (value weight): ", i + 1);
        scanf("%d %d", &value[i], &weight[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    // Start measuring time
    clock_t start_time = clock();
    int maxValue;
    for(int i=0;i<10000;i++){
        maxValue = zeroOneKnapsack(value, weight, n, W);
    }
    // End measuring time
    clock_t end_time = clock();

    double total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nMaximum value in knapsack = %d\n", maxValue);
    printf("Execution time(0/1 knapsack) = %f seconds\n", total_time);

    return 0;
}

#include <stdio.h>
#include <time.h>
#define MAX 10000
int fib_recursive(int n) {
    if (n <= 1)
        return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}
int fib_iterative(int n) {
    if (n <= 1)
        return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int memo[MAX];
int fib_top_down(int n) {
    if (memo[n] != -1)
        return memo[n];
    if (n <= 1)
        memo[n] = n;
    else
        memo[n] = fib_top_down(n - 1) + fib_top_down(n - 2);
    return memo[n];
}
int fib_bottom_up(int n) {
    if (n <= 1)
        return n;
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main() {
    int n = 15;
    clock_t start, end;
    double cpu_time_used;

    // Recursive
    start = clock();
    int res1 = fib_recursive(n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Recursive Fibonacci(%d) = %d, Time = %f sec\n", n, res1, cpu_time_used);

    // Iterative
    start = clock();
    int res2=0;
    for(int i=0;i<100000;i++){
        res2 = fib_iterative(n);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Iterative Fibonacci(%d) = %d, Time = %f sec\n", n, res2, cpu_time_used);

    // Top Down DP
    for (int i = 0; i < MAX; i++) memo[i] = -1; // reset memo
    start = clock();
    int res3=0;
    for(int i=0;i<100000;i++){
        res3 = fib_top_down(n);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Top-Down DP Fibonacci(%d) = %d, Time = %f sec\n", n, res3, cpu_time_used);

    // Bottom Up DP
    start = clock();
    int res4=0;
    for(int i=0;i<100000;i++){
        res4 = fib_bottom_up(n);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bottom-Up DP Fibonacci(%d) = %d, Time = %f sec\n", n, res4, cpu_time_used);

    return 0;
}

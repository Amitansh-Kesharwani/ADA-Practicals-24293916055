#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Item {
    float value, weight;
};

// Comparator function for sorting by value/weight ratio (descending)
int compare(const void *a, const void *b) {
    float r1 = ((struct Item*)a)->value / ((struct Item*)a)->weight;
    float r2 = ((struct Item*)b)->value / ((struct Item*)b)->weight;
    if (r1 < r2) return 1;
    if (r1 > r2) return -1;
    return 0;
}

float fractionalKnapsack(struct Item items[], int n, float capacity) {
    // Sort items by ratio
    qsort(items, n, sizeof(struct Item), compare);

    float totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity <= 0)
            break;
        if (items[i].weight <= capacity) {
            // Take the whole item
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            // Take fractional part
            totalValue += items[i].value * (capacity / items[i].weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    int n;
    float capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d (value weight): ", i + 1);
        scanf("%f %f", &items[i].value, &items[i].weight);
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    // Start measuring time
    clock_t start_time = clock();
    float maxValue;
    for(int i=0;i<10000;i++){
        maxValue = fractionalKnapsack(items, n, capacity);
    }
    // End measuring time
    clock_t end_time = clock();

    double total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nMaximum value in knapsack = %.2f\n", maxValue);
    printf("Execution time = %f seconds\n", total_time);

    return 0;
}
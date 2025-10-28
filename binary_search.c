#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 20000
int binary_search(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid; 
        else if (arr[mid] < key) 
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; 
}

void generateRandomArray(int arr[], int n){
    for(int i=0; i<n; i++){
        arr[i]= rand() % 100000;
    }
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int key, pos;
    int *arr= (int*)malloc(ARRAY_SIZE* sizeof(int));
    if(arr==NULL){
        printf("Memory allocation failed\n");
        return 1; 
    }

    clock_t start= clock();  
    for(int i=0; i<1000; i++){
        generateRandomArray(arr, ARRAY_SIZE);
        qsort(arr, ARRAY_SIZE, sizeof(int), compare);
        key = arr[rand() % ARRAY_SIZE]; 
        pos = binary_search(arr, ARRAY_SIZE, key);
    }
    clock_t end= clock();
    double time_taken= ((double)(end-start))/CLOCKS_PER_SEC/1000.0; 
    printf("Time taken to search in %d elements : %f seconds\n",ARRAY_SIZE,time_taken);
    free(arr);

    return 0;
}

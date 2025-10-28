#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];    
    int i = (low - 1);       
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
void generaterandomnumbers(int arr[],int n){
    for(int i=0;i<n;i++){
        arr[i]=rand()%10000;
    }
}
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    if(arr==NULL){
        return 1;
    }
    clock_t start=clock();
    for(int i=0;i<1000;i++){
        generaterandomnumbers(arr,n);
        quicksort(arr,0,n-1);
    }
    clock_t end=clock();
    double time_taken=((double)(end-start))/CLOCKS_PER_SEC/1000.0;
    printf("Time taken=%f",time_taken);
    free(arr);
    return 0;
}
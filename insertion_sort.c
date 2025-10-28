#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void insertionsort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
        insertionsort(arr,n);
    }
    clock_t end=clock();
    double time_taken=((double)(end-start))/CLOCKS_PER_SEC/1000.0;
    printf("Time taken=%f",time_taken);
    free(arr);
    return 0;
}
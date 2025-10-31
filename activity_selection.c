#include <stdio.h>

typedef struct {
    int start;
    int finish;
} activity;

void merge(activity arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    activity L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].finish <= R[j].finish)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(activity arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void activitySelection(activity arr[], int n) {
    mergeSort(arr, 0, n - 1);
    int i = 0;
    printf("\nSelected activities:\n");
    printf("Activity 1: Start = %d, Finish = %d\n", arr[i].start, arr[i].finish);
    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            printf("Activity %d: Start = %d, Finish = %d\n", j + 1, arr[j].start, arr[j].finish);
            i = j;
        }
    }
}

int main() {
    int n;
    printf("Enter number of activities: ");
    scanf("%d", &n);
    activity activities[n];
    for (int i = 0; i < n; i++) {
        printf("Activity %d:\n", i + 1);
        printf("Start time: ");
        scanf("%d", &activities[i].start);
        printf("Finish time: ");
        scanf("%d", &activities[i].finish);
    }
    activitySelection(activities, n);
    return 0;
}
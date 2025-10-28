#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 175

void add_matrix(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void multiply_dc(int n, int A[n][n], int B[n][n], int C[n][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int half = n / 2;
    int A11[half][half], A12[half][half], A21[half][half], A22[half][half];
    int B11[half][half], B12[half][half], B21[half][half], B22[half][half];
    int C11[half][half], C12[half][half], C21[half][half], C22[half][half];
    int temp1[half][half], temp2[half][half];

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    multiply_dc(half, A11, B11, temp1);
    multiply_dc(half, A12, B21, temp2);
    add_matrix(half, temp1, temp2, C11);

    multiply_dc(half, A11, B12, temp1);
    multiply_dc(half, A12, B22, temp2);
    add_matrix(half, temp1, temp2, C12);

    multiply_dc(half, A21, B11, temp1);
    multiply_dc(half, A22, B21, temp2);
    add_matrix(half, temp1, temp2, C21);

    multiply_dc(half, A21, B12, temp1);
    multiply_dc(half, A22, B22, temp2);
    add_matrix(half, temp1, temp2, C22);

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }
}

int main() {
    int A[N][N], B[N][N], C[N][N];
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
            //printf("%d ", A[i][j]);
        }
        //printf("\n");
    }
    printf("\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = rand() % 10;
            //printf("%d ", B[i][j]);
        }
        //printf("\n");
    }

    clock_t start = clock();
    for (int i = 0; i < 100; i++) {
        multiply_dc(N, A, B, C);
    }
    clock_t end = clock();

    printf("\n");

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken for size %d matrix: %f seconds\n",N,time_taken);

    return 0;
}
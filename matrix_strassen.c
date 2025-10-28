#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 256

void add_matrix(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void sub_matrix(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int n, int A[n][n], int B[n][n], int C[n][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int half = n / 2;
    int A11[half][half], A12[half][half], A21[half][half], A22[half][half];
    int B11[half][half], B12[half][half], B21[half][half], B22[half][half];
    int C11[half][half], C12[half][half], C21[half][half], C22[half][half];
    int M1[half][half], M2[half][half], M3[half][half], M4[half][half], M5[half][half], M6[half][half], M7[half][half];
    int T1[half][half], T2[half][half];

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

    add_matrix(half, A11, A22, T1);
    add_matrix(half, B11, B22, T2);
    strassen(half, T1, T2, M1);

    add_matrix(half, A21, A22, T1);
    strassen(half, T1, B11, M2);

    sub_matrix(half, B12, B22, T1);
    strassen(half, A11, T1, M3);

    sub_matrix(half, B21, B11, T1);
    strassen(half, A22, T1, M4);

    add_matrix(half, A11, A12, T1);
    strassen(half, T1, B22, M5);

    sub_matrix(half, A21, A11, T1);
    add_matrix(half, B11, B12, T2);
    strassen(half, T1, T2, M6);

    sub_matrix(half, A12, A22, T1);
    add_matrix(half, B21, B22, T2);
    strassen(half, T1, T2, M7);

    add_matrix(half, M1, M4, T1);
    sub_matrix(half, T1, M5, T2);
    add_matrix(half, T2, M7, C11);

    add_matrix(half, M3, M5, C12);

    add_matrix(half, M2, M4, C21);

    sub_matrix(half, M1, M2, T1);
    add_matrix(half, T1, M3, T2);
    add_matrix(half, T2, M6, C22);

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
    //printf("\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = rand() % 10;
            //printf("%d ", B[i][j]);
        }
        //printf("\n");
    }

    clock_t start = clock();
    for (int i = 0; i < 100; i++) {
        strassen(N, A, B, C);
    }
    clock_t end = clock();

    //printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            //printf("%d ", C[i][j]);
        }
        //printf("\n");
    }

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken for %d size matrix: %f seconds\n", N, time_taken);

    return 0;
}

#include <iostream>
using namespace std;

const int N = 2; // Matrix size (change to desired size)

void multiply(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void strassenMultiply(int A[N][N], int B[N][N], int C[N][N]) {
    if (N == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int m = N / 2;

    int A11[m][m], A12[m][m], A21[m][m], A22[m][m];
    int B11[m][m], B12[m][m], B21[m][m], B22[m][m];
    int C11[m][m], C12[m][m], C21[m][m], C22[m][m];
    int M1[m][m], M2[m][m], M3[m][m], M4[m][m], M5[m][m], M6[m][m], M7[m][m];

    // Divide matrices into 4 quadrants
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + m];
            A21[i][j] = A[i + m][j];
            A22[i][j] = A[i + m][j + m];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + m];
            B21[i][j] = B[i + m][j];
            B22[i][j] = B[i + m][j + m];
        }
    }

    // Calculate the 7 products (M1, M2, ..., M7)
    multiply(A11, B11, M1);
    multiply(A12, B21, M2);
    multiply(A11, B12, M3);
    multiply(A12, B22, M4);
    multiply(A21, B11, M5);
    multiply(A22, B21, M6);
    multiply(A21, B12, M7);

    // Calculate the quadrants of the result matrix using M1, M2, ..., M7
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            C11[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C12[i][j] = M3[i][j] + M5[i][j];
            C21[i][j] = M2[i][j] + M4[i][j];
            C22[i][j] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }

    // Combine the quadrants into the final result matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = C11[i][j];
            C[i][j + m] = C12[i][j];
            C[i + m][j] = C21[i][j];
            C[i + m][j + m] = C22[i][j];
        }
    }
}

int main() {
    int A[N][N] = {{1, 2}, {3, 4}};
    int B[N][N] = {{5, 6}, {7, 8}};
    int C[N][N];

    strassenMultiply(A, B, C);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << C[i][j] << " ";
        }
        cout<<endl;
    }

    return 0;
}

#include <stdio.h>


void multiplyMatrices(int mat1[][10], int mat2[][10], int result[][10], int row1, int col1, int row2, int col2) {
    if (col1 != row2) {
        printf("Matrix multiplication is not possible. Number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return;
    }

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Function to display a matrix
void displayMatrix(int mat[][10], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat1[10][10], mat2[10][10], result[10][10];
    int row1, col1, row2, col2;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &row1, &col1);

    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &row2, &col2);

    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    if (col1 != row2) {
        printf("Matrix multiplication is not possible. Number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return 0;
    }

    multiplyMatrices(mat1, mat2, result, row1, col1, row2, col2);

    printf("Result of matrix multiplication:\n");
    displayMatrix(result, row1, col2);

    return 0;
}

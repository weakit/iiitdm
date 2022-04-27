#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generateElements(int length) {
    int* array = malloc(sizeof(int) * length);
    srand(time(0));
    for(int i = 0; i < length; i++) array[i] = rand() % 999 + 1;
    return array;
}

int isBoundaryElement(int i, int rows, int cols) {
    if ((i + 1) % rows < 2) return 1;
    if (i < rows || i >= (rows * (cols - 1))) return 1;
    return 0;
}

int getRowNumber(int i, int rows, int cols) {
    return i / rows + 1;
}

int getColNumber(int i, int rows, int cols) {
    return (i % rows) + 1;
}

void encrypt(int* elements, int rows, int cols) {
    int size = rows * cols;
    for (int i = 0; i < size; i++) 
    if (isBoundaryElement(i, rows, cols)) elements[i] += getRowNumber(i, rows, cols);
    else elements[i] -= getRowNumber(i, rows, cols) + getColNumber(i, rows, cols);
}

void decrypt(int* elements, int rows, int cols) {
    int size = rows * cols;
    for (int i = 0; i < size; i++) 
    if (isBoundaryElement(i, rows, cols)) elements[i] -= getRowNumber(i, rows, cols);
    else elements[i] += getRowNumber(i, rows, cols) + getColNumber(i, rows, cols);
}

void printMatrix(int* elements, int rows, int cols) {
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
        printf("%03d ", elements[k++]);
        printf("\n");
    }
}

int main() {
    int rows, cols;
    printf("Enter rows: "); scanf("%d", &rows);
    printf("Enter cols: "); scanf("%d", &cols);
    
    printf("\n\nGenerated Matrix: \n");
    int* matrix = generateElements(rows * cols);
    printMatrix(matrix, rows, cols);
    
    printf("\nEncrypted Matrix: \n");
    encrypt(matrix, rows, cols);
    printMatrix(matrix, rows, cols);
    
    printf("\nDecrypted Matrix: \n");
    decrypt(matrix, rows, cols);
    printMatrix(matrix, rows, cols);
    
    return 0;
}
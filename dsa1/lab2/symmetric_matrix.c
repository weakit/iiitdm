#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double mean(int *list, int length) {
    double sum = 0;
    for (int i = 0; i < length; i++) sum += list[i];
    return sum / length;
}

double standardDeviation(int *list, int length) {
    // square elements
    int *squareList = malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++) squareList[i] = list[i] * list[i];
    
    // calculate means
    double squareMean = mean(squareList, length); free(squareList);
    double normalMean = mean(list, length);
    
    // calculate variance
    double variance = squareMean - normalMean * normalMean;
    
    // return standard deviation
    return sqrt(variance);
    
}

int* matrixTransform (int* oneDimensionalMatrix, int rank) {
    int i, j, k = 0;
    int* matrix = malloc(sizeof(int) * rank * rank);

    // insert input
    for (i = 0; i < rank; i++)
    for (j = i; j < rank; j++)
    matrix[i * rank + j] = oneDimensionalMatrix[k++];

    // fill in remaining rows with symmetrical elements
    for (i = 1; i < rank; i++)
    for (j = 0; j < i; j++)
    matrix[i * rank + j] = matrix[j * rank + i];

    return matrix;
}

void printMatrix(int* matrix, int rank) {
    int i, j, k = 0;
    for (i = 0; i < rank; i++) {
        for (j = 0; j < rank; j++)
        printf("%d ", matrix[k++]);
        printf("\n");
    }
}

int main() {
    int i;

    int rank;  // input rank
    printf("Enter the rank of the matrix: ");
    scanf("%d", &rank);
    
    if (rank < 1) {
        printf("Invalid Rank.");
        exit(0);
    }

    int elementsRequired = rank * (rank + 1) / 2;
    int* oneDimensionalMatrix = malloc(sizeof(int) * elementsRequired);

    printf("Enter elements of matrix as one dimensional array (%d elements): ", elementsRequired);
    for (i = 0; i < elementsRequired; i++) scanf("%d", oneDimensionalMatrix + i);

    int* transformedMatrix = matrixTransform(oneDimensionalMatrix, rank);
    printMatrix(transformedMatrix, rank); free(oneDimensionalMatrix);
    
    printf("\nMean is: %f", mean(transformedMatrix, rank * rank));
    printf("\nStandard Deviation is: %f", standardDeviation(transformedMatrix, rank * rank));
    free(transformedMatrix);
    
    return 0;
}
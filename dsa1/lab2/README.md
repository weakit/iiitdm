# Lab 2 Practice

### Getting Familiar with Moodle

1. `matrix_encryption.c`  
   Dynamically allocate a matrix with row and column values as user input. 
   Assign random values to the matrix elements. 
   Implement an encryption function in C to increase the boundary element values 
   of the matrix by the corresponding row number, and decrease the non-boundary
   elements by the corresponding (row+column) number. 
   Also, write the corresponding decryption function (opposite of the above).

   ![matrix encryption](https://user-images.githubusercontent.com/34541656/165494280-3131757f-0c78-4c18-8adc-a88774c71850.PNG)

2. `symmetric_matrix.c`  
   Write a C program to input the elements of a symmetric matrix as an 
   one-dimensional array (dynamic memory allocation). User should input
   the rank of a square matrix. Print the elements of the matrix. 
   Find the mean and Standard deviation of the elements as separate functions.

   Sample Test Case:
   ```
   Enter the Rank of the Matrix: 3
   Input Elements: 1 2 3 3 1 2

   Output:   1  2  3
             2  3  1
             3  1  2

   Mean is: 2

   Standard Deviation is: 0.8164
   ```

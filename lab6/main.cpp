#include <iostream>
#include <limits>
#include "func.h"




int main() {

    /* debug
    int matrix[NMax][NMax]{
        {9,9,9},
        {1,2,3},
        {1,2,3}
    };*/

    int matrix[NMax][NMax]{};
    inputMatrix(matrix);

    int biggestPrimeNumber = findBiggestPrimeNumber(matrix);

    printMatrix(matrix);

    if (hasTwoEqualRows(matrix)) {

        for (int i = 0; i < NMax; ++i) {
            for (int j = 0; j < NMax; ++j) {
                if (matrix[i][j] == findMinNumInColumn(matrix, j)) {
                    matrix[i][j] = biggestPrimeNumber;
                }
            }
        }
    }

    std::cout << std::endl;

    printMatrix(matrix);

    return 0;
}

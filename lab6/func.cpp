#include <iostream>
#include <limits>
#include "func.h"


void printMatrix(int matrix[][NMax]) {

    for (int i = 0; i < NMax; ++i) {
        if (i > 0) std::cout << std::endl;
        for (int j = 0; j < NMax; ++j) {
            std::cout << matrix[i][j] << " ";
        }
    }
    std::cout << std::endl;
}

bool hasTwoEqualRows(int matrix[][NMax]) {

    for (int i = 0; i < NMax - 1; ++i) {
        for (int j = 0; j < NMax; ++j) {
            if (matrix[i][j] != matrix[i + 1][j]) {
                break;
            }
            else if (j == NMax - 1) {
                return true;
            }
        }
    }

    return false;
}

int findMinNumInColumn(int matrix[][NMax], int columnIndex) {
    int min = std::numeric_limits<int>::max();
    for (int i = 0; i < NMax; ++i) {
        min = std::min(min, matrix[i][columnIndex]);
    }
    return min;
}

bool isPrime(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0)
            return false;
    return true;
}

int findBiggestPrimeNumber(int matrix[][NMax]) {
    int max = std::numeric_limits<int>::min();
    for (int i = 0; i < NMax; ++i) {
        for (int j = 0; j < NMax; ++j) {
            if (isPrime(matrix[i][j])) {
                max = std::max(matrix[i][j], max);
            }
        }
    }
    std::cout << "biggest prime number: " << max << std::endl;
    return max;
}

void inputMatrix(int matrix[][NMax]) {

    for (int i = 0; i < NMax; ++i) {
        for (int j = 0; j < NMax; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}
#pragma once

#include <iostream>
#include <limits>

const int NMax = 3;

void printMatrix(int matrix[][NMax]);

bool hasTwoEqualRows(int matrix[][NMax]);

int findMinNumInColumn(int matrix[][NMax], int columnIndex);

bool isPrime(int x);

int findBiggestPrimeNumber(int matrix[][NMax]);

void inputMatrix(int matrix[][NMax]);
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

// Функция для проверки, является ли число простым
bool isPrime(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0)
            return false;
    return true;
}

// Проверка наличия двух одинаковых строк
bool hasEqualRows(const vector<vector<int>>& A, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            bool equal = true;
            for (int k = 0; k < n; ++k) {
                if (A[i][k] != A[j][k]) {
                    equal = false;
                    break;
                }
            }
            if (equal) return true;
        }
    }
    return false;
}

int main() {

    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите n (<=100): ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));

    cout << "Введите элементы матрицы A:" << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    if (hasEqualRows(A, n)) {
        // Находим наибольший простой элемент
        int maxPrime = -1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (isPrime(A[i][j]))
                    maxPrime = max(maxPrime, A[i][j]);

        if (maxPrime == -1) {
            cout << "В матрице нет простых чисел." << endl;
        }
        else {
            // Находим минимальные элементы в каждом столбце
            for (int j = 0; j < n; ++j) {
                int minVal = A[0][j];
                for (int i = 1; i < n; ++i)
                    minVal = min(minVal, A[i][j]);

                // Заменяем все минимальные элементы этого столбца
                for (int i = 0; i < n; ++i)
                    if (A[i][j] == minVal)
                        A[i][j] = maxPrime;
            }

            cout << "Измененная матрица:" << endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j)
                    cout << A[i][j] << " ";
                cout << endl;
            }
        }
    }
    else {
        cout << "Одинаковых строк нет, матрица не изменяется." << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

// ������� ��� ��������, �������� �� ����� �������
bool isPrime(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0)
            return false;
    return true;
}

// �������� ������� ���� ���������� �����
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
    cout << "������� n (<=100): ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));

    cout << "������� �������� ������� A:" << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    if (hasEqualRows(A, n)) {
        // ������� ���������� ������� �������
        int maxPrime = -1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (isPrime(A[i][j]))
                    maxPrime = max(maxPrime, A[i][j]);

        if (maxPrime == -1) {
            cout << "� ������� ��� ������� �����." << endl;
        }
        else {
            // ������� ����������� �������� � ������ �������
            for (int j = 0; j < n; ++j) {
                int minVal = A[0][j];
                for (int i = 1; i < n; ++i)
                    minVal = min(minVal, A[i][j]);

                // �������� ��� ����������� �������� ����� �������
                for (int i = 0; i < n; ++i)
                    if (A[i][j] == minVal)
                        A[i][j] = maxPrime;
            }

            cout << "���������� �������:" << endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j)
                    cout << A[i][j] << " ";
                cout << endl;
            }
        }
    }
    else {
        cout << "���������� ����� ���, ������� �� ����������." << endl;
    }

    return 0;
}

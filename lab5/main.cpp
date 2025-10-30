#include <iostream>
#include <algorithm>

//task 1
bool hasTwoSameNumbers(int* a, int n) {
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[i] == a[j])
                return true;
    return false;
}

int lastDigit(int x) {
    return x % 10;
}

void task1() {
    const int nMax = 10000;
    int n;
    std::cin >> n;
    int* a = new int[nMax];

    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    if (hasTwoSameNumbers(a, n)) {
        std::sort(a, a + n, [](int x, int y) {
            return lastDigit(x) > lastDigit(y);
            });
    }

    for (int i = 0; i < n; ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    delete[] a;
}

//task 2
int firstDigit(int x) {
    while (x >= 10)
        x /= 10;
    return x;
}

int productDigits(int x) {
    int p = 1;
    while (x > 0) {
        p *= x % 10;
        x /= 10;
    }
    return p;
}

void task2() {
    const int nMax = 1000;
    int n;
    std::cin >> n;
    int* a = new int[nMax];

    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::sort(a, a + n, [](int x, int y) {
        int f1 = firstDigit(x), f2 = firstDigit(y);
        if (f1 != f2) return f1 < f2;

        int p1 = productDigits(x), p2 = productDigits(y);
        if (p1 != p2) return p1 < p2;

        return x < y;
        });

    for (int i = 0; i < n; ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    delete[] a;
}

//task 3
void task3() {
    const int nMax = 100, mMax = 100;
    int n, m;
    std::cin >> n >> m;
    int** A = new int* [n];
    for (int i = 0; i < n; ++i)
        A[i] = new int[m];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> A[i][j];

    int minCol = 0;
    int minSum = 1000000000;
    for (int j = 0; j < m; ++j) {
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum += A[i][j];
        if (sum < minSum) {
            minSum = sum;
            minCol = j;
        }
    }

    for (int i = 0; i < n; ++i)
        A[i][minCol] += 3;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            std::cout << A[i][j] << " ";
        std::cout << std::endl;
    }

    for (int i = 0; i < n; ++i)
        delete[] A[i];
    delete[] A;
}

//task 4
bool allDigitsDifferent(int x) {
    bool used[10] = { false };
    while (x > 0) {
        int d = x % 10;
        if (used[d]) return false;
        used[d] = true;
        x /= 10;
    }
    return true;
}

void task4() {
    const int nMax = 10000;
    int n;
    std::cin >> n;
    int* a = new int[nMax];

    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    int newN = 0;
    for (int i = 0; i < n; ++i)
        if (!allDigitsDifferent(a[i]))
            a[newN++] = a[i];

    int finalN = newN;
    for (int i = 0; i < newN; ++i) {
        int p = productDigits(a[i]);
        if (p % 14 == 0 && finalN < nMax)
            a[finalN++] = a[i];
    }

    for (int i = 0; i < finalN; ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    delete[] a;
}

//main
int main() {

    while (true) {

        int choice;
        std::cout << "Choose task: ";
        std::cin >> choice;

        switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        }
    }

    return 0;
}

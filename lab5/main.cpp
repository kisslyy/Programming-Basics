#include <iostream>

void task1() {
    int n;
    std::cin >> n;
    int a[10000];

    for (int i = 0; i < n; i++) std::cin >> a[i];

    bool hasEqual = false;
    for (int i = 0; i < n && !hasEqual; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                hasEqual = true;
                break;
            }
        }
    }

    if (hasEqual) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (a[j] % 10 < a[j + 1] % 10) {
                    int t = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = t;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) std::cout << a[i] << " ";
}

int firstDigit(int x) {
    while (x >= 10) x /= 10;
    return x;
}

int productDigits(int x) {
    int p = 1;
    while (x > 0) {
        p *= (x % 10);
        x /= 10;
    }
    return p;
}

void task2() {
    int n;
    std::cin >> n;
    int a[1000];

    for (int i = 0; i < n; i++) std::cin >> a[i];

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {

            int fd1 = firstDigit(a[j]);
            int fd2 = firstDigit(a[j+1]);

            if (fd1 > fd2 ||
               (fd1 == fd2 && productDigits(a[j]) > productDigits(a[j+1])) ||
               (fd1 == fd2 && productDigits(a[j]) == productDigits(a[j+1]) && a[j] > a[j+1])) {

                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }

    for (int i = 0; i < n; i++) std::cout << a[i] << " ";
}

void task3() {
    int n, m;
    std::cin >> n >> m;

    int a[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];

    long long minSum = 0;
    for (int i = 0; i < n; i++) minSum += a[i][0];
    int minCol = 0;

    for (int j = 1; j < m; j++) {
        long long s = 0;
        for (int i = 0; i < n; i++) s += a[i][j];
        if (s < minSum) {
            minSum = s;
            minCol = j;
        }
    }

    for (int i = 0; i < n; i++) a[i][minCol] += 3;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            std::cout << a[i][j] << " ";
        std::cout << "\n";
    }
}

bool allDigitsDifferent(int x) {
    bool used[10];
    for (int i = 0; i < 10; i++) used[i] = false;

    while (x > 0) {
        int d = x % 10;
        if (used[d]) return false;
        used[d] = true;
        x /= 10;
    }
    return true;
}

void task4() {
    int n;
    std::cin >> n;
    int a[10000];

    for (int i = 0; i < n; i++) std::cin >> a[i];

    int k = 0;
    for (int i = 0; i < n; i++) {
        if (!allDigitsDifferent(a[i])) {
            a[k++] = a[i];
        }
    }
    n = k;

    for (int i = 0; i < n; i++) {
        if (productDigits(a[i]) % 14 == 0) {

            for (int j = n; j > i; j--) {
                a[j] = a[j-1];
            }
            a[i+1] = a[i];
            n++;
            i++;
        }
    }

    for (int i = 0; i < n; i++) std::cout << a[i] << " ";
}


int main() {

    while (true)
    {
        std::cout<<"\nChoose task: ";

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        default: std::cout << "Wrong task number"; break;
        }
    }

    return 0;
}

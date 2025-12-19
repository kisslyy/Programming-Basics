#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <cstring>

using namespace std;

// ==================== ЧАСТЬ 1: "Что выведет программа?" ====================

void task1() {
    cout << "=== Задача 1 ===" << endl;
    int arr[4] = {10, 20, 30, 40};
    for (int i = 0; i <= 3; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << "Объяснение: Цикл проходит по всем корректным индексам массива." << endl << endl;
}

void task2() {
    cout << "=== Задача 2 ===" << endl;
    int arr[4] = {5, 6, 7, 8};
    for (int i = 0; i <= 6; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << "Объяснение: Выход за границы массива - неопределенное поведение (UB)." << endl << endl;
}

void task3() {
    cout << "=== Задача 3 ===" << endl;
    int x = 7; // 0111 в двоичном виде
    cout << (x & 1) << " " << (x >> 1);
    cout << endl << "Объяснение: x&1 проверяет младший бит, x>>1 сдвигает биты вправо." << endl << endl;
}

bool func() {
    cout << "func() called\n";
    return true;
}

void task4() {
    cout << "=== Задача 4 ===" << endl;
    if (false && func()) {
        cout << "Inside if\n";
    }
    cout << "Объяснение: Short-circuit evaluation - func() не вызывается." << endl << endl;
}

void task5() {
    cout << "=== Задача 5 ===" << endl;
    int arr[3] = {1, 2, 3};
    int* ptr = arr;
    cout << *(ptr + 1) << " " << ptr[2];
    cout << endl << "Объяснение: Арифметика указателей и доступ по индексу." << endl << endl;
}

int sum(int n) {
    return n + sum(n - 1);
}

void task6() {
    cout << "=== Задача 6 ===" << endl;
    cout << "Программа упадет из-за бесконечной рекурсии." << endl;
    cout << "Объяснение: Нет базового условия для остановки рекурсии." << endl << endl;
    // sum(3); // Раскомментировать для демонстрации падения
}

void task7() {
    cout << "=== Задача 7 ===" << endl;
    vector<int> vec = {1, 2, 3};
    vec.push_back(4);
    cout << vec.size() << " " << vec.capacity();
    cout << endl << "Объяснение: size - количество элементов, capacity - выделенная память." << endl << endl;
}

struct StudentTask8 {
    char grade; // 1 байт
    int age; // 4 байта
};

void task8() {
    cout << "=== Задача 8 ===" << endl;
    cout << "sizeof(Student) = " << sizeof(StudentTask8) << " байт" << endl;
    cout << "Объяснение: Из-за выравнивания (alignment) компилятор добавляет padding." << endl << endl;
}

void validate(int x) {
    if (x < 0) throw invalid_argument("Negative value");
}

void task9() {
    cout << "=== Задача 9 ===" << endl;
    try {
        validate(-5);
    } catch (const exception& e) {
        cout << e.what();
    }
    cout << endl << "Объяснение: Исключение бросается и перехватывается." << endl << endl;
}

#define SQUARE(x) x * x

void task10() {
    cout << "=== Задача 10 ===" << endl;
    cout << SQUARE(2 + 3);
    cout << endl << "Объяснение: Макрос раскрывается как 2+3*2+3 = 11 (нужны скобки)." << endl << endl;
}

namespace A { int x = 10; }
namespace B { int x = 20; }

void task11() {
    cout << "=== Задача 11 ===" << endl;
    using namespace A;
    cout << x << " " << B::x;
    cout << endl << "Объяснение: using namespace A + явное указание B::x." << endl << endl;
}

void print(int x) { cout << "int: " << x; }
void print(double x) { cout << "double: " << x; }

void task12() {
    cout << "=== Задача 12 ===" << endl;
    print(5.0f);
    cout << endl << "Объяснение: float преобразуется в double (лучшее соответствие)." << endl << endl;
}

void task13() {
    cout << "=== Задача 13 ===" << endl;
    int i = 0;
    do {
        cout << i << " ";
        i++;
    } while (i < 3);
    cout << endl << "Объяснение: do-while выполняется минимум один раз." << endl << endl;
}

void printSize(int arr[]) {
    cout << "In function: " << sizeof(arr) << endl;
}

void task14() {
    cout << "=== Задача 14 ===" << endl;
    int arr[10];
    cout << "In main: " << sizeof(arr) << endl;
    printSize(arr);
    cout << "Объяснение: В функции массив декэирует до указателя." << endl << endl;
}

void task15() {
    cout << "=== Задача 15 ===" << endl;
    const int x = 5;
    int* y = const_cast<int*>(&x);
    *y = 10;
    cout << "x = " << x << ", *y = " << *y << endl;
    cout << "Объяснение: Неопределенное поведение - изменение константы." << endl << endl;
}

void task16() {
    cout << "=== Задача 16 ===" << endl;
    int a = 2000000000;
    int b = 2000000000;
    int c = a + b;
    cout << c;
    cout << endl << "Объяснение: Переполнение целого числа (wrap-around)." << endl << endl;
}

void task17() {
    cout << "=== Задача 17 ===" << endl;
    cout << "Программа упадет при попытке модификации строкового литерала." << endl;
    cout << "Объяснение: Строковые литералы хранятся в read-only памяти." << endl << endl;
    // char* str = "Hello"; // Раскомментировать для демонстрации
    // strcat(str, " World"); // Опасная операция
}

void modify(int x, int& y, int* z) {
    x = 10; y = 20; *z = 30;
}

void task18() {
    cout << "=== Задача 18 ===" << endl;
    int a = 1, b = 2, c = 3;
    modify(a, b, &c);
    cout << a << " " << b << " " << c;
    cout << endl << "Объяснение: Передача по значению, ссылке и указателю." << endl << endl;
}

void task19() {
    cout << "=== Задача 19 ===" << endl;
    const int a = 10;
    int* ptr = const_cast<int*>(&a);
    *ptr = 20;
    cout << "a = " << a << ", *ptr = " << *ptr << endl;
    cout << "Объяснение: Неопределенное поведение - компилятор мог заинлайнить значение a." << endl << endl;
}

// ==================== ЧАСТЬ 2: Написание кода ====================

// 1. Функция, удаляющая пробелы из строки
string removeSpaces(const string& str) {
    string result = str;
    result.erase(remove(result.begin(), result.end(), ' '), result.end());
    return result;
}

// 2. Функция, возводящая целое число в целую степень
int power(int base, int exp) {
    if (exp < 0) {
        throw invalid_argument("Negative exponent not supported for integers");
    }
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

// 3. Структура Student и поиск по id
struct Student {
    int id;
    string name;
};

string findStudentName(const vector<Student>& students, int id) {
    for (const auto& student : students) {
        if (student.id == id) {
            return student.name;
        }
    }
    return ""; // не найден
}

// 4. Безопасное деление
double safeDivide(double a, double b) {
    if (b == 0.0) {
        throw runtime_error("Division by zero");
    }
    return a / b;
}

// 5. Swap через XOR (плохой вариант)
void swapXor(int& a, int& b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

// 6. Swap по указателям
void swapPtr(int* a, int* b) {
    if (!a || !b) return; // защита от nullptr
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 7. Структура Point и расстояние
struct Point {
    double x, y;
};

double distance(const Point& p1, const Point& p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

// 8. Сортировка пузырьком
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 9. Количество единиц в двоичном представлении
int countBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

// 10. Проверка числа на простоту
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// 11. Проверка, является ли число степенью двойки
bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return (n & (n - 1)) == 0;
}

// ==================== Демонстрация всех функций ====================

void demonstrateAllFunctions() {
    cout << "=== Демонстрация всех написанных функций ===" << endl << endl;
    
    // 1. Удаление пробелов
    cout << "1. Удаление пробелов из 'Hello World': " << removeSpaces("Hello World") << endl;
    
    // 2. Возведение в степень
    cout << "2. 2^5 = " << power(2, 5) << endl;
    
    // 3. Поиск студента
    vector<Student> students = {{1, "Alice"}, {2, "Bob"}, {3, "Charlie"}};
    cout << "3. Студент с id=2: " << findStudentName(students, 2) << endl;
    cout << "   Студент с id=5: " << findStudentName(students, 5) << endl;
    
    // 4. Безопасное деление
    try {
        cout << "4. 10/2 = " << safeDivide(10, 2) << endl;
        cout << "   10/0 = ";
        cout << safeDivide(10, 0) << endl;
    } catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    
    // 5. Swap через XOR
    int x = 5, y = 10;
    cout << "5. До swapXor: x=" << x << ", y=" << y;
    swapXor(x, y);
    cout << ", после: x=" << x << ", y=" << y << endl;
    
    // 6. Swap по указателям
    int a = 100, b = 200;
    cout << "6. До swapPtr: a=" << a << ", b=" << b;
    swapPtr(&a, &b);
    cout << ", после: a=" << a << ", b=" << b << endl;
    
    // 7. Расстояние между точками
    Point p1 = {0, 0};
    Point p2 = {3, 4};
    cout << "7. Расстояние между (0,0) и (3,4): " << distance(p1, p2) << endl;
    
    // 8. Сортировка пузырьком
    int arr[] = {5, 3, 8, 1, 2};
    int size = 5;
    cout << "8. До сортировки: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    bubbleSort(arr, size);
    cout << ", после: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
    
    // 9. Количество единиц в бинарном представлении
    cout << "9. Число 7 (111) имеет " << countBits(7) << " единиц" << endl;
    
    // 10. Проверка на простоту
    cout << "10. Число 17 простое? " << (isPrime(17) ? "Да" : "Нет") << endl;
    
    // 11. Проверка на степень двойки
    cout << "11. Число 16 - степень двойки? " << (isPowerOfTwo(16) ? "Да" : "Нет") << endl;
    cout << "    Число 15 - степень двойки? " << (isPowerOfTwo(15) ? "Да" : "Нет") << endl;
}

// ==================== Главная функция ====================

int main() {
    cout << "===== ПРАКТИЧЕСКАЯ ЧАСТЬ ЭКЗАМЕНА =====" << endl << endl;
    
    // Часть 1: Что выведет программа
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    task8();
    task9();
    task10();
    task11();
    task12();
    task13();
    task14();
    task15();
    task16();
    task17();
    task18();
    task19();
    
    // Часть 2: Демонстрация написанных функций
    demonstrateAllFunctions();
    
    return 0;
}
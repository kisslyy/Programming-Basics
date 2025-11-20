#include <iostream>
#include <vector>

void printVector(std::vector<int>& v) {
	for (int i = 0; i < v.size(); ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

void insertFront(std::vector<int>& v, int value) {
	v.insert(v.begin(), value);
}

void printArray(const int* arr, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int* insertFront(const int* arr, size_t size, int value, size_t& newSize) {
	newSize = size + 1;
	int* newArr = new int[newSize];

	newArr[0] = value;

	for (size_t i = 0; i < size; ++i) {
		newArr[i + 1] = arr[i];
	}

	return newArr;
}

int main() {

	int n = 0;
	std::cout << "n = ";
	std::cin >> n;

	std::vector<int> v;

	for (int i = 1; i <= n; ++i) {
		v.push_back(i);
	}

	printVector(v);

	insertFront(v, 0);

	printVector(v);


	int* arr = new int[n];
	for (int i = 0; i < n; ++i) {
		arr[i] = i + 1;
	}

	printArray(arr, n);

	size_t newSize = 0;
	int* newArr = insertFront(arr, n, 0, newSize);

	printArray(newArr, newSize);

	delete[] arr;
	delete[] newArr;

	return 0;
}

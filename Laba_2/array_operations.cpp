#include "array_operations.h"
#include <iostream>

void dynamicArrayOperations() {
    const int size = 10;
    int* arr = new int[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = i * 10;
    }

    std::cout << "������������ ������ �� 10 ���������:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    std::cout << "������� �������������� ���� ���������: " << static_cast<double>(sum) / size << std::endl;

    delete[] arr;
}


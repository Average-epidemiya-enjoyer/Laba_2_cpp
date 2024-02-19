#include "vector_operations.h"
#include <iostream>
#include <vector>
#include <random>
#include <cmath>

void vectorOperations() {
    std::vector<int> vec(10);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-20, 20);

    for (int i = 0; i < 10; ++i) {
        vec[i] = dis(gen);
    }

    std::cout << "Вектор из 10 случайных элементов:\n";
    for (int elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    double sumSquared = 0.0;
    for (int elem : vec) {
        sumSquared += elem * elem;
    }
    double meanSquared = sumSquared / vec.size();
    std::cout << "Среднее квадратичное всех элементов: " << std::sqrt(meanSquared) << std::endl;
}

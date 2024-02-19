#include "deque_set_operations.h"
#include <iostream>
#include <deque>
#include <set>
#include <algorithm>
#include <random>

void dequeSetOperations() {
    std::deque<int> dq(15);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-10, 10);

    for (int i = 0; i < 15; ++i) {
        dq[i] = dis(gen);
    }

    std::cout << "Массив из 15 случайных элементов:\n";
    for (int elem : dq) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::set<int> st(dq.begin(), dq.end());

    std::cout << "Массив, преобразованный в множество:\n";
    for (int elem : st) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    auto maxElem = std::max_element(dq.begin(), dq.end());
    int maxVal = *maxElem;

    std::for_each(dq.begin(), dq.end(), [maxVal](int& elem) {
        elem += maxVal;
        });

    std::sort(dq.begin(), dq.end(), [](int lhs, int rhs) {
        return std::abs(lhs) < std::abs(rhs);
        });

    std::cout << "Массив после прибавления максимального элемента и сортировки:\n";
    for (int elem : dq) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

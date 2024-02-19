#include "list_operations.h"
#include <iostream>
#include <list>

void listOperations() {
    std::list<int> lst;

    int num;
    char choice;
    do {
        std::cout << "Введите число: ";
        std::cin >> num;
        lst.push_back(num);

        std::cout << "Продолжить ввод? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    std::cout << "Список элементов:\n";
    for (int elem : lst) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    int maxAbs = lst.front();
    for (int elem : lst) {
        if (std::abs(elem) > std::abs(maxAbs)) {
            maxAbs = elem;
        }
    }
    std::cout << "Наибольший по модулю элемент: " << maxAbs << std::endl;
}
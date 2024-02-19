#include "map_operations.h"
#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>

void mapOperations() {
    std::map<std::string, double> refractiveIndices;

    std::ifstream inputFile("glass_data.txt");
    if (!inputFile.is_open()) {
        std::cout << "Ошибка открытия файла.\n";
        return;
    }

    std::string glassName;
    double refractiveIndex;
    while (inputFile >> glassName >> refractiveIndex) {
        refractiveIndices[glassName] = refractiveIndex;
    }
    inputFile.close();

    std::cout << "Список стекол и их показателей преломления:\n";
    for (const auto& pair : refractiveIndices) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    auto minMax = std::minmax_element(refractiveIndices.begin(), refractiveIndices.end(),
        [](const auto& lhs, const auto& rhs) {
            return lhs.second < rhs.second;
        });

    std::cout << "Стекла с минимальным и максимальным показателями преломления:\n";
    std::cout << "Минимальный: " << minMax.first->first << " (" << minMax.first->second << ")\n";
    std::cout << "Максимальный: " << minMax.second->first << " (" << minMax.second->second << ")\n";
}

#include "map_operations.h"
#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>

void mapOperations() {
    std::map<std::string, double> refractiveIndices;

    std::ifstream inputFile("glass_data.txt");
    if (!inputFile.is_open()) {
        std::cout << "������ �������� �����.\n";
        return;
    }

    std::string glassName;
    double refractiveIndex;
    while (inputFile >> glassName >> refractiveIndex) {
        refractiveIndices[glassName] = refractiveIndex;
    }
    inputFile.close();

    std::cout << "������ ������ � �� ����������� �����������:\n";
    for (const auto& pair : refractiveIndices) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    auto minMax = std::minmax_element(refractiveIndices.begin(), refractiveIndices.end(),
        [](const auto& lhs, const auto& rhs) {
            return lhs.second < rhs.second;
        });

    std::cout << "������ � ����������� � ������������ ������������ �����������:\n";
    std::cout << "�����������: " << minMax.first->first << " (" << minMax.first->second << ")\n";
    std::cout << "������������: " << minMax.second->first << " (" << minMax.second->second << ")\n";
}

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    int testAmount, itemAmount, bagSize;
    std::cin >> testAmount;
    if (!(testAmount <= (1e5) && testAmount >= 1)) return 0;
    for (int test = 0; test < testAmount; test++) {
        std::cin >> itemAmount >> bagSize;
        if (!(itemAmount >= 1 && itemAmount <= 5e3) || !(bagSize >= 1 && bagSize <= 5e3)) return 0;
        std::vector<int> weight(itemAmount), value(itemAmount), mysteryValue(1e5);
        int weightSize = itemAmount, valueSize = weightSize, mysteryValueSize = 1e5;
        for (int i = 0; i < weightSize; i++) {
            std::cin >> weight[i];
            while (weight[i] < 1 || weight[i] > bagSize) {
                std::cout << "1 <= input <" << bagSize << std::endl;
                std::cin >> weight[i];
            }
        }
        for (int i = 0; i < valueSize; i++) {
            std::cin >> value[i];
            while (value[i] < 1 || value[i] > 1e9) {
                std::cout << "1 <= input <" << 1e9 << std::endl;
                std::cin >> value[i];
            }
        }
        for (int i = 0; i < mysteryValueSize; i++) {
            std::cin >> mysteryValue[i];
            while (mysteryValue[i] < 1 || mysteryValue[i] > 1e9) {
                std::cout << "1 <= input <" << 1e9 << std::endl;
            }
        }
        for (int i = 0; i < valueSize; i++) {}
        long long weightSum = 0, valueSum = 0;
        for (int i = 0; i < weightSize; i++) weightSum += weight[i];
        if (itemAmount > bagSize || weightSum > bagSize) {
            std::cout << -1 << std::endl;
            return 0;
        }
        std::pmr::unordered_map<int, int> valueWeightMap;
        for (int i = 0; i < weightSize; i++) {
            valueWeightMap[value[i]] = weight[i];
        }
        std::sort(value.begin(), value.end(), std::greater<int>());
        int currentLoad = 0;
        int i = 0;
        while (currentLoad < bagSize || i < weightSize) {
            currentLoad += valueWeightMap[value[i]];
            valueSum += value[i];
            i++;
            int i1 = i;
            while (currentLoad > bagSize || i1 < weightSize) {
                currentLoad -= valueWeightMap[value[i1]];
                valueSum -= value[i1];
                i1++;
                currentLoad += valueWeightMap[value[i1]];
                valueSum += value[i1];
            }
        }
        std::cout << valueSum << std::endl;
    }
    return 0;
}

#include <iostream>
#include <vector>

int main() {
    int testAmount, itemAmount, bagSize;
    std::cin >> testAmount;
    if (!(testAmount <= (1e5) && testAmount >= 1)) return 0;
    for (int test = 0; test < testAmount; test++) {
        std::cin >> itemAmount >> bagSize;
        if (!(itemAmount >= 1 && itemAmount <= 5e5) || !(bagSize >= 1 && bagSize <= 1e9)) return 0;
        std::vector<int> weight(itemAmount), value(itemAmount);
        int weightSize = itemAmount, valueSize = weightSize;
        for (int i = 0; i < weightSize; i++) std::cin >> weight[i];
        for (int i = 0; i < valueSize; i++) std::cin >> value[i];
        long long weightSum = 0, valueSum = 0;
        for (int i = 0; i < weightSize; i++) weightSum += weight[i];
        for (int i = 0; i < valueSize; i++) valueSum += value[i];
        if (itemAmount > bagSize || weightSum > bagSize) {
            std::cout << -1 << std::endl;
            return 0;
        }
        // std::pmr::unordered_map<int, int> valueWeightMap;
        // for (int i = 0; i < weightSize; i++) {
        //     valueWeightMap[value[i]] = weight[i];
        // }
        // std::sort(value.begin(), value.end(), std::greater<int>());
        // int currentLoad = 0;
        // int i = 0;
        // int valueSum = 0;
        // while (currentLoad < bagSize || i < weightSize) {
        //     currentLoad += valueWeightMap[value[i]];
        //     valueSum += value[i];
        //     i++;
        //     int i1 = i;
        //     while (currentLoad > bagSize) {
        //         currentLoad -= valueWeightMap[value[i1]];
        //         valueSum -= value[i1];
        //         i1++;
        //         currentLoad += valueWeightMap[value[i1]];
        //         valueSum += value[i1];
        //     }
        // }
        std::cout << valueSum << std::endl;
    }
    return 0;
}

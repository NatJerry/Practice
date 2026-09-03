//
// Created by Jerry on 2026/9/3.
//

#include<iostream>
#include<vector>

int main() {
    int group = 0;
    while (true) {
        std::cin >> group;
        if (group >= 1 && group <= 1e4) break;
        std::cout << "Wrong input!" << std::endl;
    }
    int total = 0;
    for (int value = 0; value < group; value++) {
        int row = 0;
        while (true) {
            std::cin >> row;
            if (1 <= row && row <= 3e5) {
                if (const int tempTotal = total + row; 1 <= tempTotal && tempTotal <= 3e5) {
                    total = tempTotal;
                    break;
                }
            }
            std::cout << "Wrong input!" << std::endl;
        }
        auto height = std::vector<int>(row);
        for (int i = 0; i < row; i++) {
            bool pass2 = false;
            while (!pass2) {
                int n;
                std::cin >> n;
                if (i == 0 && n >= 1 && n <= 3e5) {
                    pass2 = true;
                    height[i] = n;
                } else if (n <= height[i - 1]) {
                    pass2 = true;
                    height[i] = n;
                } else {
                    std::cout << "must smaller than or equal last one." << std::endl;
                }
            }
        }
        int num = 0;
        int pairA = 0;
        int pairB = 0;
        {
            int i = 1;
            for (int hei: height) {
                if (hei % 2 == 0) {
                    pairA += hei / 2;
                    pairB += hei / 2;
                } else {
                    if (i % 2 == 0) {
                        pairA += hei / 2 + 1;
                        pairB += hei / 2;
                    } else {
                        pairA += hei / 2;
                        pairB += hei / 2 + 1;
                    }
                }
                i++;
            }
        }
        num = std::min(pairA, pairB);
        std::cout << num << std::endl;
    }
    return 0;
}

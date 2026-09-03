//
// Created by Jerry on 2026/9/3.
//

#include<iostream>
#include<vector>

int main() {
    int row = 0;
    {
        bool pass1 = false;
        while (!pass1) {
            std::cin >> row;
            if (1 <= row && row <= 3e5) break;
            std::cout << "Wrong input!" << std::endl;
        }
    }
    std::vector<int> height = std::vector<int>(row);
    for (int i = 0; i < row; i++) {
        bool pass2 = false;
        while (!pass2) {
            int n;
            std::cin >> n;
            if (i == 0 && n >= 1 && n <= 2) {
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
    bool isLastOddNumberPaired = false;
    for (int i = 0; i < row; i++) {
        if (i > 0) {
            if (height[i] % 2 == 0) {
                num += height[i] / 2;
            } else {
                if (height[i - 1] % 2 == 0) num += height[i] / 2;
                else {
                    if (isLastOddNumberPaired) {
                        num += height[i]/2;
                        isLastOddNumberPaired = false;
                    }
                    else {
                        num += height[i] / 2 + 1;
                        isLastOddNumberPaired = true;
                    }
                }
            }
        } else {
            num += height[i] / 2;
        }
    }
    std::cout << num << std::endl;
    return 0;
}

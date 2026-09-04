//
// Created by Jerry on 2026/9/4.
//

#include <iostream>
#include <vector>

int main() {
    int days = 0;
    while (!(days <= 100 && days >= 3)) {
        std::cin >> days;
    }
    auto runningRewards = std::vector<int>(days);
    auto learningRewards = std::vector<int>(days);
    auto gamingRewards = std::vector<int>(days);
    for (int day = 0; day < days; day++) {
        std::cin >> runningRewards[day];
    }
    for (int day = 0; day < days; day++) {
        std::cin >> learningRewards[day];
    }
    for (int day = 0; day < days; day++) {
        std::cin >> gamingRewards[day];
    }
    int sum = 0;
    for (int x = 0; x < days; x++) {
        int runningReward = runningRewards[x];
        for (int y = 0; y < days; y++) {
            if (y != x) {
                int learningReward = learningRewards[y];
                for (int z = 0; z < days; z++) {
                    if (z != y && z != x) {
                        int gamingReward = gamingRewards[z];
                        sum = std::max(sum, runningReward + learningReward + gamingReward);
                    }
                }
            }
        }
    }
    std::cout << sum << std::endl;
    return 0;
}

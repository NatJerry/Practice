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
    int maxRunningReward = 0;
    int maxLearningReward = 0;
    int maxGamingReward = 0;
    int selectedRunningDay = 0;
    int selectedLearningDay = 0;
    int selectedGamingDay = 0;
    for (int day = 0; day < days; day++) {
        if (runningRewards[day] > maxRunningReward) {
            maxRunningReward = runningRewards[day];
            selectedRunningDay = day;
        }
        if (learningRewards[day] > maxLearningReward) {
            maxLearningReward = learningRewards[day];
            selectedLearningDay = day;
        }
        if (gamingRewards[day] > maxGamingReward) {
            maxGamingReward = gamingRewards[day];
            selectedGamingDay = day;
        }
    }
    {
        while (true) {
            if (selectedLearningDay != selectedRunningDay && selectedGamingDay != selectedRunningDay && selectedLearningDay != selectedGamingDay) break;
            if (selectedRunningDay == selectedLearningDay) {
                if (maxRunningReward >= maxLearningReward) {
                    maxLearningReward = 0;
                    int lastSelectedDay = selectedLearningDay;
                    for (int day = 0; day < days; day++) {
                        if (day != lastSelectedDay) {
                            if (learningRewards[day] > maxLearningReward) {
                                maxLearningReward = learningRewards[day];
                                selectedLearningDay = day;
                            }
                        }
                    }
                }else {
                    maxRunningReward = 0;
                    int lastSelectedDay = selectedRunningDay;
                    for (int day = 0; day < days; day++) {
                        if (day != lastSelectedDay) {
                            if (runningRewards[day] > maxRunningReward) {
                                maxRunningReward = runningRewards[day];
                                selectedRunningDay = day;
                            }
                        }
                    }
                }
            }
            if (selectedRunningDay == selectedGamingDay) {
                if (maxRunningReward >= maxGamingReward) {
                    maxGamingReward = 0;
                    int lastSelectedDay = selectedGamingDay;
                    for (int day = 0; day < days; day++) {
                        if (day != lastSelectedDay) {
                            if (gamingRewards[day] > maxGamingReward) {
                                maxGamingReward = gamingRewards[day];
                                selectedGamingDay = day;
                            }
                        }
                    }
                }else {
                    maxRunningReward = 0;
                    int lastSelectedDay = selectedRunningDay;
                    for (int day = 0; day < days; day++) {
                        if (day != lastSelectedDay) {
                            if (runningRewards[day] > maxRunningReward) {
                                maxRunningReward = runningRewards[day];
                                selectedRunningDay = day;
                            }
                        }
                    }
                }
            }
            if (selectedLearningDay == selectedGamingDay) {
                if (maxRunningReward >= maxGamingReward) {
                    maxGamingReward = 0;
                    int lastSelectedDay = selectedGamingDay;
                    for (int day = 0; day < days; day++) {
                        if (day != lastSelectedDay) {
                            if (gamingRewards[day] > maxGamingReward) {
                                maxGamingReward = gamingRewards[day];
                                selectedGamingDay = day;
                            }
                        }
                    }
                }else {
                    maxRunningReward = 0;
                    int lastSelectedDay = selectedRunningDay;
                    for (int day = 0; day < days; day++) {
                        if (day != lastSelectedDay) {
                            if (runningRewards[day] > maxRunningReward) {
                                maxRunningReward = runningRewards[day];
                                selectedRunningDay = day;
                            }
                        }
                    }
                }
            }
        }
    }
    int sum = maxLearningReward + maxRunningReward + maxGamingReward;
    std::cout << sum << std::endl;
    return 0;
}


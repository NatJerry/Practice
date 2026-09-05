//
// Created by Jerry on 2026/9/4.
//

#include <iostream>
#include <regex>
#include <set>
#include <vector>

int main() {
    int group = 0;
    while (!(group >= 1 && group <= 2e5)) {
        std::cin >> group;
    }
    auto nums = std::vector<std::string>(group);
    {
        std::regex pattern("^[1-9]+$");
        for (int i = 0; i < group; i++) {
            while (true) {
                std::cin >> nums[i];
                if (std::regex_match(nums[i], pattern)) break;
                std::cout << nums[i] << "wrong input" << std::endl;
            }
        }
    }
    int sum = 0;
    for (const std::string &numStr: nums) {
        for (int i = 0; i < numStr.length(); i++) {
            //决定插多少空
            auto inserted = std::set<int>();
            auto splitted = std::set<int>();
            std::string lastStr = numStr;
            for (int j = 0; j <= i; j++) {
                // 第几个挡板插空的处理逻辑
                for (int k = 1; k <= numStr.length(); k++) {
                    //插第几个空
                    if (inserted.contains(k)) continue;
                    splitted.insert(std::stoi(lastStr.substr(0,k)));
                    lastStr = lastStr.substr(k);
                    inserted.insert(k);
                }
            }
        }
    }
    return 0;
}

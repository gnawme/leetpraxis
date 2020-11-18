#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
        std::vector<int> smallGuys;
        for (auto cit = nums.begin(); cit != nums.end(); ++cit) {
            auto current{*cit};

            std::vector<int> restof(nums);
            auto exclude{std::find(restof.begin(), restof.end(), current)};
            restof.erase(exclude);

            auto numSmaller{0};
            for (const auto& rest : restof) {
                if (rest < current) {
                    ++numSmaller;
                }
            }

            smallGuys.push_back(numSmaller);
        }

        return smallGuys;
    }
};

int main() {
    std::vector<int> test1{6, 5, 4, 8};
    Solution solution;
    auto test1Out{solution.smallerNumbersThanCurrent(test1)};

    for (const auto& count : test1Out) {
        std::cout << count << std::endl;
    }

    std::vector<int> test2{7, 7, 7, 7};
    auto test2Out{solution.smallerNumbersThanCurrent(test2)};
    for (const auto& count : test2Out) {
        std::cout << count << std::endl;
    }
}
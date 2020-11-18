#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        std::vector<int> runners;
        auto ridx{0};

        for (const auto& num : nums) {
            if (ridx == 0) {
                runners.push_back(num);
                ++ridx;
                continue;
            }

            runners.push_back(runners[ridx - 1] + num);
            ++ridx;
        }

        return runners;
    }
};

int main() {
    std::vector<int> test1{1, 1, 1, 1, 1};

    Solution solution;
    auto test1Out{solution.runningSum(test1)};
    for (const auto& out : test1Out) {
        std::cout << out << std::endl;
    }

    std::vector<int> test2{1, 2, 3, 4};
    auto test2Out{solution.runningSum(test2)};
    for (const auto& out : test2Out) {
        std::cout << out << std::endl;
    }
}
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> shuffle(std::vector<int>& nums, int n) {
        std::vector<int> shuffled;
        for (auto nit = nums.cbegin(); nit != nums.cend() - n; ++nit) {
            shuffled.push_back(*nit);
            shuffled.push_back(*(nit + n));
        }

        return shuffled;
    }
};

int main() {
    std::vector<int> test1{2, 5, 1, 3, 4, 7};

    Solution solution;
    auto test1Out{solution.shuffle(test1, 3)};
    for (const auto& out : test1Out) {
        std::cout << out << std::endl;
    }
}
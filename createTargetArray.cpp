#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> createTargetArray(std::vector<int>& nums, std::vector<int>& index) {
        std::vector<int> target;
        auto pos{0};
        for (auto nit = nums.cbegin(); nit != nums.cend(); ++nit) {
            target.insert(target.begin() + index[pos], *nit);
            ++pos;
        }
        return target;
    }
};

int main() {
    Solution solution;
    std::vector<int> test1Nums{0, 1, 2, 3, 4};
    std::vector<int> test1Index{0, 1, 2, 2, 1};
    auto test1Out{solution.createTargetArray(test1Nums, test1Index)};

    for (const auto& out : test1Out) {
        std::cout << out << std::endl;
    }
}
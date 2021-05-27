#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        if (nums.size() == 2) {
            return (nums[0] - 1) * (nums[1] - 1);
        }

        auto max1{std::max_element(nums.begin(), nums.end())};
        if (max1 == nums.begin()) {
            auto maxe{std::max_element(max1 + 1, nums.end())};
            return (*max1 - 1) * (*maxe - 1);
        } else if (max1 == nums.end()) {
            auto maxe{std::max_element(nums.begin(), max1 - 1)};
            return (*max1 - 1) * (*maxe - 1);
        }

        auto max2{std::max_element(nums.begin(), max1)};
        auto max3{std::max_element(max1 + 1, nums.end())};
        auto maxe{(*max2 < *max3) ? max3 : max2};

        return (*max1 - 1) * (*maxe - 1);
    }
};

int main() {
    std::vector<int> test1{3, 4, 5, 2};

    Solution solution;
    std::cout << std::boolalpha << (solution.maxProduct(test1) == 12) << std::endl;

    std::vector<int> test2{10, 2, 5, 2};
    std::cout << std::boolalpha << (solution.maxProduct(test2) == 36) << std::endl;
}
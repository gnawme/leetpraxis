#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
        auto maxelm{std::max_element(candies.begin(), candies.end())};

        std::vector<bool> besties;
        for (const auto& candy : candies) {
            besties.push_back((candy + extraCandies) >= *maxelm);
        }

        return besties;
    }
};

int main() {
    std::vector<int> test1{2, 3, 5, 1, 3};

    Solution solution;
    auto test1Out{solution.kidsWithCandies(test1, 3)};
    for (const auto& out : test1Out) {
        std::cout << std::boolalpha << out << std::endl;
    }

    std::vector<int> test2{4, 2, 1, 1, 2};
    auto test2Out{solution.kidsWithCandies(test2, 1)};
    for (const auto& out : test2Out) {
        std::cout << std::boolalpha << out << std::endl;
    }
}

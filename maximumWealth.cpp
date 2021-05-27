#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

class Solution {
public:
    int maximumWealth(std::vector<std::vector<int>>& accounts) {
        int maxWealth{std::numeric_limits<int>::min()};

        for (const auto& fatcat : accounts) {
            auto wealth{std::accumulate(fatcat.begin(), fatcat.end(), 0)};
            maxWealth = std::max(wealth, maxWealth);
        }

        return maxWealth;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> test1{{1, 2, 3}, {3, 2, 1}};
    std::cout << std::boolalpha << (solution.maximumWealth(test1) == 6) << std::endl;
}
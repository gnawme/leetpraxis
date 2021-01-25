#include <algorithm>
#include <vector>
#include <iostream>

class Solution {
public:
    int countGoodRectangles(std::vector<std::vector<int>>& rectangles) {
        auto minDim{0};
        for (const auto& rect : rectangles) {
            auto mini{std::min_element(rect.begin(), rect.end())};
            if (*mini > minDim) {
                minDim = *mini;
            }
        }

        auto numCuts{0};
        for (const auto& rect : rectangles) {
            auto w{rect[0]};
            auto l{rect[1]};

            if ((minDim <= w) && (minDim <= l)) {
                ++numCuts;
            }
        }

        return numCuts;
    }
};

int main() {
    std::vector<std::vector<int>> test1{{5, 8}, {3, 9}, {5, 12}, {16, 5}};
    Solution solution;
    std::cout << std::boolalpha << (solution.countGoodRectangles(test1) == 3) << std::endl;

    std::vector<std::vector<int>> test2{{2,3},{3,7},{4,3},{3,7}};
    std::cout << std::boolalpha << (solution.countGoodRectangles(test2) == 3) << std::endl;
}
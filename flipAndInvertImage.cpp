#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& A) {
        for (auto& row : A) {
            std::reverse(row.begin(), row.end());
            for (auto& cell : row) {
                cell = !cell;
            }
        }

        return A;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> test1{{{1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 0}}};
    std::vector<std::vector<int>> test1Out{solution.flipAndInvertImage(test1)};

    for (const auto& test : test1Out) {
        for (const auto& row : test) {
            std::cout << row << " ";
        }

        std::cout << std::endl;
    }
}

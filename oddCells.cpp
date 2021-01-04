#include <iostream>
#include <vector>

class Solution {
public:
    int oddCells(int n, int m, std::vector<std::vector<int>>& indices) {
        auto dim{m * n};
        auto cells{new int[dim]{}};

        for (const auto& index : indices) {
            auto row{index[0]};
            incRow(n, m, cells, row);
            auto col{index[1]};
            incCol(n, m, cells, col);
        }

        auto numOdd{0};
        for (auto i = 0; i < dim; ++i) {
            if (cells[i] % 2 != 0) {
                ++numOdd;
            }
        }
        return numOdd;
    }

    void incCol(int n, int m, int* cells, int col) {
        for (auto i = 0; i < n; ++i) {
            cells[i * m + col] += 1;
        }
    }

    void incRow(int n, int m, int* cells, int row) {
        for (auto i = 0; i < m; ++i) {
            cells[row * m + i] += 1;
        }
    }
};

int main() {
    Solution solution;

    std::vector<std::vector<int>> test1{{{0, 1}, {1, 1}}};
    std::cout << std::boolalpha << (solution.oddCells(2, 3, test1) == 6) << std::endl;

    std::vector<std::vector<int>> test2{{{1, 1}, {0, 0}}};
    std::cout << std::boolalpha << (solution.oddCells(2, 2, test2) == 0) << std::endl;
}
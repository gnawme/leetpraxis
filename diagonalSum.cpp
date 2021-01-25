#include <iostream>
#include <vector>

class Solution {
public:
    int diagonalSum(std::vector<std::vector<int>>& mat) {
        auto dim{mat.size()};
        auto sum{0};
        auto i = 0;
        auto j = 0;
        for (auto k = 0; k < dim; ++k) {
            sum += mat[i][j];
            ++i;
            ++j;
        }

        i = 0;
        j = dim - 1;
        for (auto k = 0; k < dim; ++k) {
            if (i != j) {
                sum += mat[i][j];
            }

            ++i;
            --j;
        }

        return sum;
    }
};

int main() {
    std::vector<std::vector<int>> test1{{{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}}};
    Solution solution;

    std::cout << std::boolalpha << (solution.diagonalSum(test1) == 8) << std::endl;

    std::vector<std::vector<int>> test2{{5}};
    std::cout << std::boolalpha << (solution.diagonalSum(test2) == 5) << std::endl;

    std::vector<std::vector<int>> test3{{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    std::cout << std::boolalpha << (solution.diagonalSum(test3) == 25) << std::endl;
}
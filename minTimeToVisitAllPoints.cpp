#include <cmath>
#include <iostream>
#include <vector>

class Solution {
    template<typename T>
    int sgn(T val) {
        return (T(0) < val) - (val < T(0));
    }

public:
    int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points) {
        int numSeconds{0};

        for (auto idx = 0; idx < points.size() - 1; ++idx) {
            auto pt0{points[idx]};
            auto pt1{points[idx + 1]};
            auto d0{pt1[0] - pt0[0]};
            auto d1{pt1[1] - pt0[1]};
            auto incX{sgn(d0)};
            auto incY{sgn(d1)};
            auto gX{pt0[0]};
            auto gY{pt0[1]};
            while ((gX != pt1[0]) && (gY != pt1[1])) {
                gX += incX;
                gY += incY;
                ++numSeconds;
            }

            if (gX == pt1[0]) {
                while (gY != pt1[1]) {
                    gY += incY;
                    ++numSeconds;
                }
            } else if (gY == pt1[1]) {
                while (gX != pt1[0]) {
                    gX += incX;
                    ++numSeconds;
                }
            }
        }

        return numSeconds;
    }
};

int main() {
    std::vector<std::vector<int>> test1{{1, 1}, {3, 4}, {-1, 0}};
    Solution solution;
    std::cout << std::boolalpha << (solution.minTimeToVisitAllPoints(test1) == 7) << std::endl;
}
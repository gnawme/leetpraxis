#include <cmath>
#include <iostream>
#include <vector>

class Solution {
public:
    int countGoodTriplets(std::vector<int>& arr, int a, int b, int c) {
        auto len{arr.size()};
        auto numTriplets{0};
        for (auto i = 0; i < len; ++i) {
            for (auto j = i + 1; j < len; ++j) {
                for (auto k = j + 1; k < len; ++k) {
                    bool testA{std::abs(arr[i] - arr[j]) <= a};
                    bool testB{std::abs(arr[j] - arr[k]) <= b};
                    bool testC{std::abs(arr[i] - arr[k]) <= c};
                    bool isGood{testA && testB && testC};
                    if (isGood) {
                        ++numTriplets;
                    }
                }
            }
        }

        return numTriplets;
    }
};

int main() {
    Solution solution;
    std::vector<int> test1{3, 0, 1, 1, 9, 7};
    std::cout << std::boolalpha << (solution.countGoodTriplets(test1, 7, 2, 3) == 4) << std::endl;
}
#include <cmath>
#include <iostream>
#include <vector>

class Solution {
public:
    bool isArmstrong(int N) {
        std::vector<int> digits;
        auto n{N};
        while (n > 0) {
            auto digit{n % 10};
            digits.push_back(digit);
            n /= 10;
        }

        auto sum{0};
        auto numDigits{int(digits.size())};
        for (const auto& dig : digits) {
            sum += std::pow(dig, numDigits);
        }

        return (sum == N);
    }
};

int main() {
    Solution solution;
    int test1{153};
    std::cout << std::boolalpha << (solution.isArmstrong(test1) == true) << std::endl;
}
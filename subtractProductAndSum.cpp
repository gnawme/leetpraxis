#include <iostream>
#include <new>
#include <numeric>
#include <vector>

class Solution {
public:
    int subtractProductAndSum(int n) {
        std::vector<int> digits;

        while (n > 0) {
            auto digit{n % 10};
            digits.push_back(digit);
            n /= 10;
        }

        auto sum{std::accumulate(digits.begin(), digits.end(), 0)};
        auto product{std::accumulate(digits.begin(), digits.end(), 1, std::multiplies<int>())};

        return (product - sum);
    }
};

int main() {
    auto moo{new (std::align_val_t{64}) double[1024]};
    Solution solution;
    std::cout << std::boolalpha << (solution.subtractProductAndSum(4421) == 21) << std::endl;
    delete[](std::align_val_t{64}, moo);
}
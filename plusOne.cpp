#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        std::deque<int> inked;
        int carry{1};
        for (auto rit = digits.rbegin(); rit != digits.rend(); ++rit) {
            auto digit{*rit + carry};
            if (digit > 9) {
                digit %= 10;
                carry = 1;
            } else {
                carry = 0;
            }

            inked.push_front(digit);
        }

        if (carry != 0) {
            inked.push_front(carry);
        }

        digits.assign(inked.begin(), inked.end());
        return digits;
    }
};

int main() {
    Solution solution;
    std::vector<int> test1{9};
    auto test1Out{solution.plusOne(test1)};
    for (const auto& test : test1Out) {
        std::cout << test << " ";
    }
    std::cout << std::endl;

    std::vector<int> test2{6, 1, 4, 5, 3, 9, 0, 1, 9, 5, 1, 8, 6, 7, 0, 5, 5, 4, 3};
    auto test2Out{solution.plusOne(test2)};
    for (const auto& test : test2Out) {
        std::cout << test << " ";
    }
    std::cout << std::endl;
}
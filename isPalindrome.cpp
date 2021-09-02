#include <deque>
#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        std::deque<int> digits;
        while (x > 0) {
            auto digit{x % 10};
            digits.push_front(digit);
            x /= 10;
        }

        bool isPal{true};
        while (!digits.empty()) {
            if (digits.size() == 1) {
                return isPal;
            }

            isPal = isPal && (digits.front() == digits.back());
            if (!isPal) {
                return false;
            }

            digits.pop_front();
            digits.pop_back();
        }

        return isPal;
    }
};

int main() {
    Solution solution;

    std::cout << std::boolalpha << solution.isPalindrome(121) << std::endl;
    std::cout << std::boolalpha << solution.isPalindrome(12321) << std::endl;
}
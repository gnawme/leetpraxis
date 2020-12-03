#include <iostream>
#include <vector>

class Solution {
public:
    int findNumbers(std::vector<int>& nums) {
        int numEvens{0};
        for (const auto& num : nums) {
            if ((getNumDigits(num) % 2) == 0) {
                ++numEvens;
            }
        }

        return numEvens;
    }

private:
    int getNumDigits(int num) {
        auto n{1};
        if (num >= 100000000) {
            n += 8;
            num /= 100000000;
        }
        if (num >= 10000) {
            n += 4;
            num /= 10000;
        }
        if (num >= 100) {
            n += 2;
            num /= 100;
        }
        if (num >= 10) {
            n += 1;
        }

        return n;
    }
};

int main() {
    std::vector<int> test1{12, 345, 2, 6, 7896};

    Solution solution;
    std::cout << std::boolalpha << (solution.findNumbers(test1) == 2) << std::endl;


    std::vector<int> test2{555, 901, 482, 1771};
    std::cout << std::boolalpha << (solution.findNumbers(test2) == 1) << std::endl;
    ;
}
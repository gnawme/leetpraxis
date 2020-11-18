#include <iostream>

class Solution {
public:
    int numberOfSteps(int num) {
        if (num == 0) {
            return 0;
        }

        int numSteps{0};
        while (num > 0) {
            if ((num % 2) == 0) {
                num /= 2;
                ++numSteps;
            } else {
                num -= 1;
                ++numSteps;
            }
        }

        return numSteps;
    }
};

int main() {
    Solution solution;
    std::cout << std::boolalpha << (solution.numberOfSteps(123) == 12) << std::endl;
}
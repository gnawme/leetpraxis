#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    int balancedStringSplit(std::string s) {
        std::stack<char> rlStack;
        char oppo{'R'};
        int numBalanced{0};

        for (const auto& current : s) {
            if (rlStack.empty()) {
                oppo = (current == 'L') ? 'R' : 'L';
                rlStack.push(current);
            } else {
                if (current == oppo) {
                    rlStack.pop();
                    if (rlStack.empty()) {
                        ++numBalanced;
                    }
                } else {
                    rlStack.push(current);
                }
            }
        }

        return numBalanced;
    }
};

int main() {
    Solution solution;

    std::string test1{"RLRRLLRLRL"};
    std::cout << std::boolalpha << (solution.balancedStringSplit(test1) == 4) << std::endl;
    std::string test2{"RLLLLRRRLR"};
    std::cout << std::boolalpha << (solution.balancedStringSplit(test2) == 3) << std::endl;
    std::string test3{"RLRRRLLRLL"};
    std::cout << std::boolalpha << (solution.balancedStringSplit(test3) == 2) << std::endl;
}
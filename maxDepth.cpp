#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    int maxDepth(std::string s) {
        std::string::size_type maxDepth{0u};

        std::stack<char> pstack;
        for (const auto& item : s) {
            if (item == '(') {
                pstack.push(item);
            } else if (item == ')') {
                maxDepth = std::max(maxDepth, pstack.size());
                pstack.pop();
            }
        }

        return maxDepth;
    }
};

int main() {
    std::string test1{"(1+(2*3)+((8)/4))+1"};
    Solution solution;
    std::cout << std::boolalpha << (solution.maxDepth(test1) == 3) << std::endl;

    std::string test2{"(1)+((2))+(((3)))"};
    std::cout << std::boolalpha << (solution.maxDepth(test2) == 3) << std::endl;
}
#include <iostream>
#include <string>

class Solution {
public:
    std::string removeOuterParentheses(std::string& input) {
        std::string output;

        return output;
    }
};

int main() {
    std::string test1("(()())(())");

    Solution solution;
    std::cout << (solution.removeOuterParentheses(test1) == "()()()") << std::endl;
}
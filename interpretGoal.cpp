#include <iostream>
#include <string>

class Solution {
public:
    std::string interpret(std::string command) {
        std::string output;
        for (auto it = command.begin(); it != command.end(); ++it) {
            if (*it == 'G') {
                output.push_back(*it);
            } else if (*it == '(') {
                if (*(it + 1) == ')') {
                    output.push_back('o');
                    ++it;
                } else if (*(it + 1) == 'a') {
                    output.push_back('a');
                    output.push_back('l');
                    it += 2;
                }
            }
        }

        return output;
    }
};

int main() {
    Solution solution;
    std::string test1{"G()(al)"};
    std::cout << solution.interpret(test1) << std::endl;
    std::string test2{"(al)G(al)()()G"};
    std::cout << solution.interpret(test2) << std::endl;
}
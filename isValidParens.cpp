#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        constexpr char lParen{'('};
        constexpr char rParen{')'};
        constexpr char lBrace{'{'};
        constexpr char rBrace{'}'};
        constexpr char lBrack{'['};
        constexpr char rBrack{']'};

        std::stack<char> inchar;
        for (const auto& next : s) {
            if (((next == rParen) || (next == rBrace) || (next == rBrack)) && inchar.empty()) {
                return false;
            }

            if ((next == lParen) || (next == lBrace) || (next == lBrack)) {
                inchar.push(next);
                continue;
            }

            if ((next == rParen) || (next == rBrace) || (next == rBrack)) {
                switch (next) {
                case rParen:
                    if (inchar.top() != lParen) {
                        return false;
                    } else {
                        inchar.pop();
                    }
                    break;

                case rBrace:
                    if (inchar.top() != lBrace) {
                        return false;
                    } else {
                        inchar.pop();
                    }
                    break;

                case rBrack:
                    if (inchar.top() != lBrack) {
                        return false;
                    } else {
                        inchar.pop();
                    }
                    break;
                }
            }
        }

        if (!inchar.empty()) {
            return false;
        }

        return true;
    }
};

int main() {
    Solution solution;
    std::string test1{"()[]{}"};
    std::cout << std::boolalpha << (solution.isValid(test1) == true) << std::endl;

    std::string test2{"([)]"};
    std::cout << std::boolalpha << (solution.isValid(test2) == false) << std::endl;

    std::string test3{"{[]}"};
    std::cout << std::boolalpha << (solution.isValid(test3) == true) << std::endl;

    std::string test4{"["};
    std::cout << std::boolalpha << (solution.isValid(test4) == false) << std::endl;
}
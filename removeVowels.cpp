#include <iostream>
#include <set>
#include <string>

class Solution {
public:
    std::string removeVowels(std::string s) {
        std::string vowels{"aeiou"};
        while (true) {
            auto pos{s.find_first_of(vowels)};
            if (pos == std::string::npos) {
                return s;
            }

            s.erase(pos, 1);
        }
    }
};

int main() {
    std::string test1{"leetcodeisacommunityforcoders"};
    Solution solution;
    auto test1Out{solution.removeVowels(test1)};
    std::cout << test1 << ":" << test1Out << std::endl;

    std::string test2{"aeiou"};
    auto test2Out{solution.removeVowels(test2)};
    std::cout << test2 << ":" << test2Out << std::endl;
}
#include <cctype>
#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
public:
    bool halvesAreAlike(std::string s) {
        std::unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        auto slen{s.length() / 2};
        std::string upper{s.substr(0, slen)};
        std::string lower{s.substr(slen, s.length())};

        auto upVowels{0};
        auto loVowels{0};
        for (auto i = 0; i < slen; ++i) {
            if (auto uit = vowels.find(upper[i]); uit != vowels.end()) {
                ++upVowels;
            }

            if (auto lit = vowels.find(lower[i]); lit != vowels.end()) {
                ++loVowels;
            }
        }

        return (upVowels == loVowels);
    }
};

int main() {
    Solution solution;
    std::string test1{"AbCdEfGh"};
    std::cout << std::boolalpha << (solution.halvesAreAlike(test1) == true) << std::endl;

    std::string test2{"aA"};
    std::cout << std::boolalpha << (solution.halvesAreAlike(test2) == true) << std::endl;
}
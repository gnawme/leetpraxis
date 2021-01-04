#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <utility>

class Solution {
public:
    int countLetters(std::string S) {
        std::multimap<char, int> lettres;

        auto runLength{1};
        for (auto i = 0; i < S.length() - 1; ++i) {
            if (S[i] == S[i + 1]) {
                ++runLength;
            } else {
                lettres.insert(std::make_pair(S[i], runLength));
                runLength = 1;
            }
        }

        lettres.insert(std::make_pair(S[S.length() - 1], runLength));

        auto count{0};
        for (const auto& letter : lettres) {
            auto& [alfa, num]{letter};
            count += int((std::pow(num, 2) + num) / 2);
        }

        return count;
    }
};

int main() {
    Solution solution;
    std::string test1{"aaaba"};
    std::cout << std::boolalpha << (solution.countLetters(test1) == 8) << std::endl;

    std::string test2{"aaaaaaaaaa"};
    std::cout << std::boolalpha << (solution.countLetters(test2) == 55) << std::endl;

    std::string test3{"ddddk"};
    std::cout << std::boolalpha << (solution.countLetters(test3) == 11) << std::endl;
}
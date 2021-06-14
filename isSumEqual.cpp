#include <cmath>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool isSumEqual(std::string firstWord, std::string secondWord, std::string targetWord) {
        auto sum1{getWordSum(firstWord)};
        auto sum2{getWordSum(secondWord)};
        auto sum3{getWordSum(targetWord)};

        return ((sum1 + sum2) == sum3);
    }

    int getWordSum(std::string word) {
        std::vector<int> digits;
        for (const auto& letter : word) {
            digits.push_back(letter - 'a');
        }

        auto sum{0};
        auto power{digits.size() - 1};
        for (const auto& digit : digits) {
            sum += int(digit * std::pow(10.f, float(power)));
            --power;
        }

        return sum;
    }
};

int main() {
    Solution solution;

    std::cout << std::boolalpha << solution.isSumEqual("acb", "cba", "cdb") << std::endl;
    std::cout << std::boolalpha << solution.isSumEqual("h", "fhjfdghj", "fhjfdgig") << std::endl;
}
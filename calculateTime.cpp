#include <cstdlib>
#include <iostream>
#include <string>

class Solution {
public:
    int calculateTime(std::string keyboard, std::string word) {
        std::string::size_type lastTyme{0u};
        std::string::size_type tyme{0u};
        for (auto index = 0; index < word.length(); ++index) {
            auto where{keyboard.find(word[index])};
            auto thisTyme{std::abs(static_cast<int>(where - lastTyme))};
            tyme += thisTyme;
            lastTyme = where;
        }

        return tyme;
    }
};

int main() {
    std::string test1Kbd{"abcdefghijklmnopqrstuvwxyz"};
    std::string test1Word{"cba"};

    Solution solution;
    std::cout << std::boolalpha << (solution.calculateTime(test1Kbd, test1Word) == 4) << std::endl;

    std::string test2Kbd{"pqrstuvwxyzabcdefghijklmno"};
    std::string test2Word{"leetcode"};
    std::cout << std::boolalpha << (solution.calculateTime(test2Kbd, test2Word) == 73) << std::endl;
}
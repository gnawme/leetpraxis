#include <iostream>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
    int countConsistentStrings(std::string allowed, std::vector<std::string>& words) {
        if (allowed.empty() || words.empty()) {
            return 0;
        }

        std::set<char> legal(allowed.begin(), allowed.end());
        auto numConsistent{0};

        for (const auto& word : words) {
            bool isConsistent{true};
            for (const auto& letter : word) {
                isConsistent &= (legal.find(letter) != legal.end());
            }

            if (isConsistent) {
                ++numConsistent;
            }
        }

        return numConsistent;
    }
};

int main() {
    Solution solution;

    std::vector<std::string> test1{"ad", "bd", "aaab", "baa", "badab"};
    std::string test1A{"ab"};
    std::cout << std::boolalpha << (solution.countConsistentStrings(test1A, test1) == 2)
              << std::endl;
}
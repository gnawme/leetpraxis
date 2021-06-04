#include <iostream>
#include <map>
#include <string>
#include <vector>

class Solution {
public:
    int countMatches(
            std::vector<std::vector<std::string>>& items,
            std::string ruleKey,
            std::string ruleValue) {

        std::map<std::string, int> RULE_IDX{{{"type"}, 0}, {{"color"}, 1}, {{"name"}, 2}};

        auto ruleIndex{RULE_IDX[ruleKey]};

        int numMatches{0};
        for (const auto& item : items) {
            if (item[ruleIndex] == ruleValue) {
                ++numMatches;
            }
        }

        return numMatches;
    }
};

int main() {
    std::vector<std::vector<std::string>> test1{
            {"phone", "blue", "pixel"},
            {"computer", "silver", "lenovo"},
            {"phone", "gold", "iphone"}};

    Solution solution;
    std::cout << std::boolalpha << (solution.countMatches(test1, "color", "silver") == 1)
              << std::endl;
    std::cout << std::boolalpha << (solution.countMatches(test1, "type", "phone") == 2)
              << std::endl;
}
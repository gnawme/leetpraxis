#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) {
            return {};
        }

        if (strs.size() == 1) {
            return strs[0];
        }

        if (strs[0][0] != strs[1][0]) {
            return {};
        }

        std::sort(strs.begin(), strs.end());
        if (strs[0].empty() && strs[strs.size() - 1].empty()) {
            return {};
        }

        auto str1{strs[0].c_str()};
        auto str2{strs[strs.size() - 1].c_str()};

        std::string prefix;
        while ((*str1 == *str2) && (*str1 != '\0' || *str2 != '\0')) {
            prefix.push_back(*str1);
            *str1++;
            *str2++;
        }

        return prefix;
    }
};

int main() {
    Solution solution;

    std::vector<std::string> test1{"", ""};
    std::cout << solution.longestCommonPrefix(test1) << std::endl;

    std::vector<std::string> test2{"flower", "flow", "flight"};
    std::cout << solution.longestCommonPrefix(test2) << std::endl;

    std::vector<std::string> test3{"flower", "flower", "flower"};
    std::cout << solution.longestCommonPrefix(test3) << std::endl;
}
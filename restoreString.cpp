#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string restoreString(std::string s, std::vector<int>& indices) {
        std::string nustr(s);

        auto i{0};
        for (const auto& index : indices) {
            nustr[index] = s[i];
            ++i;
        }

        return nustr;
    }
};

int main() {
    std::string test1s{"codeleet"};
    std::vector<int> test1indices{4, 5, 6, 7, 0, 2, 1, 3};

    Solution solution;
    std::cout << test1s << std::endl;
    std::cout << solution.restoreString(test1s, test1indices) << std::endl;

    std::string test2s{"aaiougrt"};
    std::vector<int> test2indices{4, 0, 2, 6, 7, 3, 1, 5};
    std::cout << test2s << std::endl;
    std::cout << solution.restoreString(test2s, test2indices) << std::endl;
}
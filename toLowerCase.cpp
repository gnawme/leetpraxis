#include <algorithm>
#include <iostream>
#include <string>

class Solution {
public:
    std::string toLowerCase(std::string str) {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }
};

int main() {
    Solution solution;
    std::string test1{"LOVELY"};
    std::cout << solution.toLowerCase(test1) << std::endl;
}
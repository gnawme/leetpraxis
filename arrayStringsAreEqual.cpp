#include <iostream>
#include <numeric>
#include <string>
#include <vector>

class Solution {
public:
    bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2) {
        std::string mt{""};
        std::string s1{std::accumulate(word1.begin(), word1.end(), mt)};
        std::string s2{std::accumulate(word2.begin(), word2.end(), mt)};

        return (s1 == s2);
    }
};

int main() {
    std::vector<std::string> test1a{"ab", "c"};
    std::vector<std::string> test1b{"a", "bc"};
    Solution solution;
    std::cout << std::boolalpha << solution.arrayStringsAreEqual(test1a, test1b) << std::endl;
}
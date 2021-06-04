#include <iostream>
#include <set>
#include <string>

class Solution {
public:
    bool checkIfPangram(std::string sentence) {
        std::set<char> pangram(sentence.begin(), sentence.end());

        return (pangram.size() == 26);
    }
};

int main() {
    std::string test1{"thequickbrownfoxjumpsoverthelazydog"};
    Solution solution;

    std::cout << std::boolalpha << solution.checkIfPangram(test1) << std::endl;
}
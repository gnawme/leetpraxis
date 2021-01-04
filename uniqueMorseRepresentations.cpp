#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
    std::unordered_map<char, std::string> morseMap{
            {'a', ".-"},   {'b', "-..."}, {'c', "-.-."}, {'d', "-.."},  {'e', "."},
            {'f', "..-."}, {'g', "--."},  {'h', "...."}, {'i', ".."},   {'j', ".---"},
            {'k', "-.-"},  {'l', ".-.."}, {'m', "--"},   {'n', "-."},   {'o', "---"},
            {'p', ".--."}, {'q', "--.-"}, {'r', ".-."},  {'s', "..."},  {'t', "-"},
            {'u', "..-"},  {'v', "...-"}, {'w', ".--"},  {'x', "-..-"}, {'y', "-.--"},
            {'z', "--.."}};

public:
    int uniqueMorseRepresentations(std::vector<std::string>& words) {
        std::set<std::string> moonique;
        for (const auto& word : words) {
            std::string morse;
            for (auto& lettre : word) {
                morse.append(morseMap[lettre]);
            }
            moonique.emplace(morse);
        }

        return moonique.size();
    }
};

int main() {
    std::vector<std::string> test1{"gin", "zen", "gig", "msg"};
    Solution solution;
    std::cout << std::boolalpha << (solution.uniqueMorseRepresentations(test1) == 2) << std::endl;
}

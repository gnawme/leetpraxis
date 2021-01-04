#include <iostream>

class Solution {
public:
    int numberOfMatches(int n) {
        auto numTeams{n};
        auto numMatches{0};

        while (numTeams > 1) {
            if (numTeams % 2 == 0) {
                numMatches += (numTeams / 2);
                numTeams /= 2;
            } else {
                numMatches += ((numTeams - 1) / 2);
                numTeams = ((numTeams - 1) / 2) + 1;
            }
        }

        return numMatches;
    }
};

int main() {
    Solution solution;

    auto test1{7};
    std::cout << std::boolalpha << (solution.numberOfMatches(test1) == 6) << std::endl;

    auto test2{14};
    std::cout << std::boolalpha << (solution.numberOfMatches(test2) == 13) << std::endl;
}
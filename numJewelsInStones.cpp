#include <iostream>
#include <string>

class Solution {
public:
    int numJewelsInStones(std::string jewels, std::string stones) {
        auto numJewels{0};
        auto found{stones.find_first_of(jewels)};
        if (found == std::string::npos) {
            return 0;
        }

        ++numJewels;
        stones.erase(found, 1);
        while (found != std::string::npos) {
            found = stones.find_first_of(jewels);
            if (found == std::string::npos) {
                break;
            }

            ++numJewels;
            stones.erase(found, 1);
        }

        return numJewels;
    }
};

int main() {
    std::string test1J{"aA"};
    std::string test1S{"aAAbbbb"};

    Solution solution;
    std::cout << std::boolalpha << (solution.numJewelsInStones(test1J, test1S) == 3) << std::endl;

    std::string test2J{"bec"};
    std::string test2S{"deea"};
    std::cout << std::boolalpha << (solution.numJewelsInStones(test2J, test2S) == 2) << std::endl;
}
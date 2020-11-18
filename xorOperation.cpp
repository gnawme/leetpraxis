#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int xorOperation(int n, int start) {
        std::vector<int> nums(n);
        std::generate(
                nums.begin(), nums.end(), [i = 0, start]() mutable { return start + (i++ * 2); });
        auto git{nums.begin()};
        auto xorro{*git};
        for (++git; git != nums.end(); ++git) {
            xorro ^= *git;
        }

        return xorro;
    }
};

int main() {
    Solution solution;
    std::cout << std::boolalpha << (solution.xorOperation(5, 0) == 8) << std::endl;
    std::cout << std::boolalpha << (solution.xorOperation(4, 3) == 8) << std::endl;
    std::cout << std::boolalpha << (solution.xorOperation(1, 7) == 7) << std::endl;
}
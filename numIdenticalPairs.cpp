#include <iostream>
#include <set>
#include <vector>

class Solution {
public:
    int numIdenticalPairs(std::vector<int>& nums) {
        int numIdentical{0};
        for (auto it = nums.begin(); it != nums.end() - 1; ++it) {
            std::multiset<int> restof(it + 1, nums.end());
            numIdentical += restof.count(*it);
        }

        return numIdentical;
    }
};

int main() {
    std::vector<int> test1{1, 2, 3, 1, 1, 3};

    Solution solution;
    std::cout << std::boolalpha << (solution.numIdenticalPairs(test1) == 4) << std::endl;

    std::vector<int> test2{1, 1, 1, 1};
    std::cout << std::boolalpha << (solution.numIdenticalPairs(test2) == 6) << std::endl;
}
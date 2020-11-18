#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> decompressRLElist(std::vector<int>& nums) {
        std::vector<int> expanded;
        for (auto it = nums.begin(); it != nums.end(); it += 2) {
            auto runlength{*it};
            auto number{*(it + 1)};
            std::vector<int> stub(runlength, number);
            expanded.insert(expanded.end(), stub.begin(), stub.end());
        }

        return expanded;
    }
};

int main() {
    Solution solution;
    std::vector<int> test1{1, 2, 3, 4};
    auto test1Out{solution.decompressRLElist(test1)};
    for (const auto& test : test1Out) {
        std::cout << test << std::endl;
    }
}
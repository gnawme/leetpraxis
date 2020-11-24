#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> anagramMappings(std::vector<int>& A, std::vector<int>& B) {
        std::vector<int> mapping;
        for (const auto& a : A) {
            auto inB{std::find(B.begin(), B.end(), a)};
            mapping.push_back(std::distance(B.begin(), inB));
        }

        return mapping;
    }
};

int main() {
    std::vector<int> test1A{12, 28, 46, 32, 50};
    std::vector<int> test1B{50, 12, 32, 46, 28};

    Solution solution;
    auto mapping{solution.anagramMappings(test1A, test1B)};

    for (const auto& mapped : mapping) {
        std::cout << mapped << " ";
    }

    std::cout << std::endl;
}
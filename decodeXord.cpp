#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> decode(std::vector<int>& encoded, int first) {
        std::vector<int> decoded;
        decoded.push_back(first);
        auto xorme{first};
        for (const auto& enc : encoded) {
            int dec{xorme ^ enc};
            decoded.push_back(dec);
            xorme = dec;
        }

        return decoded;
    }
};

int main() {
    Solution solution;
    std::vector<int> test1{1, 2, 3};

    auto dec1{solution.decode(test1, 1)};
    for (const auto& dec : dec1) {
        std::cout << dec << " ";
    }
    std::cout << std::endl;

    std::vector<int> test2{6, 2, 7, 3};
    auto dec2{solution.decode(test2, 4)};
    for (const auto& dec : dec2) {
        std::cout << dec << " ";
    }
    std::cout << std::endl;
}
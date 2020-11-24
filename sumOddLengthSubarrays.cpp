#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

class Solution {
public:
    int sumOddLengthSubarrays(std::vector<int>& arr) {
        int summa{0};
        for (const auto& num : arr) {
            summa += num;
        }

        if (arr.size() < 3) {
            return summa;
        }

        if (arr.size() % 2) {
            summa += std::accumulate(arr.begin(), arr.end(), 0);
        }

        if (arr.size() > 3) {
            for (auto odds = 3; odds < arr.size(); odds += 2) {
                auto len{odds - 1};
                for (auto it = 0; it + len < arr.size(); ++it) {
                    auto dist{std::distance(arr.begin(), arr.begin() + it)};
                    auto subaru{std::accumulate(arr.begin() + it, arr.begin() + it + odds, 0)};
                    summa += subaru;
                }
            }
        }

        return summa;
    }
};

int main() {
    std::vector<int> test1{1, 4, 2, 5, 3};
    Solution solution;
    std::cout << std::boolalpha << (solution.sumOddLengthSubarrays(test1) == 58) << std::endl;

    std::vector<int> test2{10, 11, 12};
    std::cout << std::boolalpha << (solution.sumOddLengthSubarrays(test2) == 66) << std::endl;

    std::vector<int> test3{1};
    std::cout << std::boolalpha << (solution.sumOddLengthSubarrays(test3) == 1) << std::endl;

    std::vector<int> test4{1, 2};
    std::cout << std::boolalpha << (solution.sumOddLengthSubarrays(test4) == 3) << std::endl;
}
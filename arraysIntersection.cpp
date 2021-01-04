#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int>
    arraysIntersection(std::vector<int>& arr1, std::vector<int>& arr2, std::vector<int>& arr3) {
        std::vector<int> int1;
        std::set_intersection(
                arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), std::back_inserter(int1));
        std::vector<int> int2;
        std::set_intersection(
                arr3.begin(), arr3.end(), int1.begin(), int1.end(), std::back_inserter(int2));
        return int2;
    }
};

int main() {
    std::vector test1v1{1, 2, 3, 4, 5};
    std::vector test1v2{1, 2, 5, 7, 9};
    std::vector test1v3{1, 3, 4, 5, 8};

    Solution solution;
    auto test1Out{solution.arraysIntersection(test1v1, test1v2, test1v3)};

    for (const auto& inter : test1Out) {
        std::cout << inter << " ";
    }
    std::cout << std::endl;
}
#include <iostream>
#include <vector>

class Solution {
public:
    int busyStudent(std::vector<int>& startTime, std::vector<int>& endTime, int queryTime) {
        auto numBusy{0};
        for (auto sit = startTime.begin(), eit = endTime.begin(); sit != startTime.end();
             ++sit, ++eit) {
            if ((*sit <= queryTime) && (*eit >= queryTime)) {
                ++numBusy;
            }
        }

        return numBusy;
    }
};

int main() {
    std::vector<int> test1Start{9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> test1End{10, 10, 10, 10, 10, 10, 10, 10, 10};

    Solution solution;
    std::cout << std::boolalpha << (solution.busyStudent(test1Start, test1End, 5) == 5)
              << std::endl;
}
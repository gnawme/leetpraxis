#include <iostream>
#include <numeric>
#include <vector>

bool isLegitimate(std::vector<std::vector<int>> arr) {
    bool isLegit = true;
    auto top{std::accumulate(arr[0].begin(), arr[0].end(), 0)};
    auto bot{std::accumulate(arr[arr.size() - 1].begin(), arr[arr.size() - 1].end(), 0)};
    isLegit = isLegit && (top == 0);
    isLegit = isLegit && (bot == 0);

    if (!isLegit) {
        return false;
    }

    for (const auto& lane : arr) {
        isLegit = isLegit && (lane[0] == 0);
        isLegit = isLegit && (lane[lane.size() - 1] == 0);
    }

    return isLegit;
}

int main() {
    std::vector<std::vector<int>> test1{
            {{0, 0, 0, 0, 0, 0, 0, 0},
             {0, 1, 1, 1, 1, 1, 0, 0},
             {0, 1, 1, 1, 1, 1, 0, 0},
             {0, 1, 1, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0}}};

    std::cout << std::boolalpha << isLegitimate(test1) << std::endl;
}
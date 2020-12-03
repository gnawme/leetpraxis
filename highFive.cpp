#include <iostream>
#include <map>
#include <queue>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> highFive(std::vector<std::vector<int>>& items) {
        std::map<int, std::priority_queue<int>> scores;

        for (const auto& item : items) {
            auto idx{1};
            for (const auto& datum : item) {
                static int id = 0;
                if ((idx % 2) == 0) {
                    scores[id].push(datum);
                } else {
                    id = datum;
                }
                ++idx;
            }
        }

        std::vector<std::vector<int>> highest;
        for (auto& [id, marks] : scores) {
            std::vector<int> student;
            student.push_back(id);
            auto accum{0};
            for (auto i = 0; i < 5; ++i) {
                accum += marks.top();
                marks.pop();
            }
            student.push_back(int(accum / 5));
            highest.push_back(student);
        }

        return highest;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> test1{
            {{1, 91},
             {1, 92},
             {2, 93},
             {2, 97},
             {1, 60},
             {2, 77},
             {1, 65},
             {1, 87},
             {1, 100},
             {2, 100},
             {2, 76}}};

    auto highest{solution.highFive(test1)};
    for (const auto& stud : highest) {
        std::cout << "id: " << stud[0] << " average: " << stud[1] << std::endl;
    }
}
#include <cmath>
#include <iostream>
#include <vector>

struct ListNode {
    int val{0};
    ListNode* next{nullptr};
    ListNode() = default;
    ListNode(int x) : val(x) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        std::vector<int> binvec;
        for (auto node = head; node != nullptr; node = node->next) {
            binvec.push_back(node->val);
        }

        int decimal{0};
        auto raised{binvec.size() - 1u};
        for (const auto& binval : binvec) {
            auto twoval{static_cast<int>(std::pow(2.0, static_cast<double>(raised)))};
            decimal += binval * twoval;
            --raised;
        }

        return decimal;
    }
};

int main() {
    std::vector<int> test1{1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0};
    ListNode* list1{new ListNode(test1[0])};
    ListNode* nexNode{list1};
    for (auto i = 1; i < test1.size(); ++i) {
        ListNode* node(new ListNode(test1[i]));
        nexNode->next = node;
        nexNode = nexNode->next;
    }

    for (auto node = list1; node != nullptr; node = node->next) {
        std::cout << node->val;
    }

    std::cout << std::endl;

    Solution solution;
    std::cout << std::boolalpha << (solution.getDecimalValue(list1) == 18880);
}
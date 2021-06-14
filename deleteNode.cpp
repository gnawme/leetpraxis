#include "LeetList.h"
#include <iostream>

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* next{node->next};
        node->val = next->val;
        node->next = next->next;
        delete next;
    }
};

int main() {
    // 4,5,1,9
    Solution solution;
    List list;
    list.insert(9);
    list.insert(1);
    ListNode* five = list.insert(5);
    list.insert(4);

    for (auto nodule = list.list; nodule != nullptr; nodule = nodule->next) {
        std::cout << nodule->val << std::endl;
    }

    solution.deleteNode(five);
    for (auto nodule = list.list; nodule != nullptr; nodule = nodule->next) {
        std::cout << nodule->val << std::endl;
    }
}
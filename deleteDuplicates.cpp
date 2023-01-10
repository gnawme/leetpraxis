#include "LeetList.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto node{head};
        while (node != nullptr) {
            auto next{node->next};
            if (next == nullptr) {
                break;
            }

            while (next->val == node->val) {
                node->next = next->next;
                delete next;
                next = node->next;

                if (next == nullptr) {
                    break;
                }
            }

            node = node->next;
        }

        return head;
    }
};

int main() {
    Solution solution;
    ListNode* node = new ListNode(1);
    node->next = new ListNode(1);
    node->next->next = new ListNode(2);
    node->next->next->next = new ListNode(3);
    node->next->next->next->next = new ListNode(3);

    auto result{solution.deleteDuplicates(node)};
}

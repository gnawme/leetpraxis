#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }

        if (l2 == nullptr) {
            return l1;
        }

        ListNode* output{(l1->val < l2->val) ? l1 : l2};
        if (l1->val < l2->val) {
            l1 = l1->next;
        } else {
            l2 = l2->next;
        }

        ListNode* current{output};
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }

            current = current->next;
        }

        if (l1 != nullptr) {
            current->next = l1;
        } else if (l2 != nullptr) {
            current->next = l2;
        }

        return output;
    }
};

int main() {
    auto l1Ptr{new ListNode(1)};
    l1Ptr->next = new ListNode(2);
    l1Ptr->next->next = new ListNode(4);

    auto l2Ptr{new ListNode(1)};
    l2Ptr->next = new ListNode(3);
    l2Ptr->next->next = new ListNode(4);

    Solution solution;
    auto res{solution.mergeTwoLists(l1Ptr, l2Ptr)};

    for (; res != nullptr; res = res->next) {
        std::cout << res->val << " ";
    }
    std::cout << std::endl;
}
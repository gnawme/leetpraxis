#include "LeetList.h"
#include <iostream>

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* nth{head};
        for (auto i = 0; i < n; ++i) {
            if (nth->next == nullptr) {
                if (i == n - 1) {
                    head = head->next;
                    return head;
                }
            }

            nth = nth->next;
        }

        ListNode* idx{head};
        while (nth->next != nullptr) {
            nth = nth->next;
            idx = idx->next;
        }

        ListNode* delme{idx->next};
        idx->next = idx->next->next;
        delete delme;
        return head;
    }
};

int main() {
    // 1,2,3,4,5
    List ent(5);
    ent.insert(4);
    ent.insert(3);
    ent.insert(2);
    ListNode* head = ent.insert(1);

    Solution solution;
    solution.removeNthFromEnd(head, 2);
}
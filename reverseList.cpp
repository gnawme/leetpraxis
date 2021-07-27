#include "LeetList.h"
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        

        return head;
    }
};

int main() {
    // 1,2,3,4,5
    List list(5);
    list.insert(4);
    list.insert(3);
    list.insert(2);
    list.insert(1);

    Solution solution;
    auto reversi{solution.reverseList(list.list)};
}
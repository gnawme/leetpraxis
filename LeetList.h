/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    ListNode(int x) : val(x), next(nullptr) {}

    int val{0};
    ListNode* next{nullptr};
};

struct List {
    List() = default;
    List(int x) : list(new ListNode(x)) {}

    ~List() {
        if (list != nullptr) {
            for (ListNode* node = list; node != nullptr;) {
                ListNode* nexum = node->next;
                delete node;
                node = nexum;
            }
        }
    }

    ListNode* insert(int x) {
        ListNode* node{new ListNode(x)};
        node->next = list;
        list = node;
        return node;
    }

    ListNode* list{nullptr};
};
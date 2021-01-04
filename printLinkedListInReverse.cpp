#include <iostream>
#include <stack>

class ImmutableListNode {
public:
    void printValue() {}
    ImmutableListNode* getNext() {
        static ImmutableListNode instance;
        return &instance;
    }
};


class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        std::stack<ImmutableListNode*> nodes;
        for (auto node = head; node != nullptr; node = node->getNext()) {
            nodes.push(node);
        }

        while (!nodes.empty()) {
            auto node{nodes.top()};
            node->printValue();
            nodes.pop();
        }
    }
};

int main() {}
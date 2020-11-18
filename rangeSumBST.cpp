#include <iostream>
#include <vector>

struct TreeNode {
    int val{0};
    TreeNode* left{nullptr};
    TreeNode* right{nullptr};
    TreeNode() = default;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}

    TreeNode* insert(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }

        if (val < root->val) {
            root->left = insert(root->left, val);
        } else if (val > root->val) {
            root->right = insert(root->right, val);
        }

        return root;
    }
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int summa{0};
        sumInOrder(root, low, high, summa);
        return summa;
    }

private:
    void sumInOrder(TreeNode* node, int low, int high, int& summa) {
        if (node == nullptr) {
            return;
        }

        sumInOrder(node->left, low, high, summa);
        sumInOrder(node->right, low, high, summa);

        if ((low <= node->val) && (node->val <= high)) {
            summa += node->val;
        };
    }
};

int main() {
    Solution solution;
    std::vector<int> test1{10, 5, 15, 3, 7, 13, 18, 1, 6};
    auto test1Tree{new TreeNode};
    for (const auto& num : test1) {
        test1Tree = test1Tree->insert(test1Tree, num);
    }

    std::cout << std::boolalpha << (solution.rangeSumBST(test1Tree, 6, 10) == 23) << std::endl;

    std::vector<int> test2{10, 5, 15, 3, 7, 18};
    auto test2Tree{new TreeNode};
    for (const auto& num : test2) {
        test2Tree = test2Tree->insert(test2Tree, num);
    }

    std::cout << std::boolalpha << (solution.rangeSumBST(test2Tree, 7, 15) == 32) << std::endl;
}
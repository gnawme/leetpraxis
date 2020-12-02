#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int val{0};
    TreeNode* left{nullptr};
    TreeNode* right{nullptr};

    TreeNode() = default;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

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
    void logLevel(TreeNode* root, std::vector<int>& lonely) {
        std::queue<TreeNode*> treeQ;
        treeQ.push(root);

        while (!treeQ.empty()) {
            TreeNode* current{treeQ.front()};
            treeQ.pop();

            if (current->left) {
                treeQ.push(current->left);
            }

            if (current->right) {
                treeQ.push(current->right);
            }

            if (current->left && !current->right) {
                lonely.push_back(current->left->val);
            }

            if (current->right && !current->left) {
                lonely.push_back(current->right->val);
            }
        }
    }

    std::vector<int> getLonelyNodes(TreeNode* root) {
        std::vector<int> lonely;
        logLevel(root, lonely);
        return lonely;
    }
};

int main() {
    TreeNode* tree1{new TreeNode(1)};
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);
    tree1->left->right = new TreeNode(4);

    Solution solution;
    std::vector<int> test1Out{solution.getLonelyNodes(tree1)};
    for (const auto& lone : test1Out) {
        std::cout << lone << std::endl;
    }


    TreeNode* tree2(new TreeNode(7));
    tree2->left = new TreeNode(1);
    tree2->right = new TreeNode(4);
    tree2->left->left = new TreeNode(6);
    tree2->right->left = new TreeNode(5);
    tree2->right->right = new TreeNode(3);
    tree2->right->right->right = new TreeNode(2);
    std::vector<int> test2Out{solution.getLonelyNodes(tree2)};
    for (const auto& lone : test2Out) {
        std::cout << lone << std::endl;
    }
}
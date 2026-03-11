#include <iostream>
#include <cmath>
#include <utility>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    pair<bool, int> isBalanced_fast(TreeNode* root) {
        if (!root) {
            return {true, 0};
        }

        pair<bool, int> left = isBalanced_fast(root->left);
        pair<bool, int> right = isBalanced_fast(root->right);
        bool leftAns = left.first;
        bool rightAns = right.first;
        bool diff = abs(left.second - right.second) <= 1;

        return {leftAns && rightAns && diff, max(left.second, right.second) + 1};
    }

    bool isBalanced(TreeNode* root) {
        return isBalanced_fast(root).first;
    }
};

int main() {
    // Example 1: Balanced tree
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->right = new TreeNode(6);

    // Example 2: Unbalanced tree
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->left->left = new TreeNode(4);

    Solution sol;
    cout << "Is Tree 1 balanced? " << (sol.isBalanced(root1) ? "Yes" : "No") << endl;
    cout << "Is Tree 2 balanced? " << (sol.isBalanced(root2) ? "Yes" : "No") << endl;

    return 0;
}

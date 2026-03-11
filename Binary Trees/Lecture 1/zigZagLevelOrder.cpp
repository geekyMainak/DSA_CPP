#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        int count = 0;

        while(!q.empty()) {
            int level = q.size();
            vector<int> levels;

            for(int i = 0; i < level; i++) {
                TreeNode* temp = q.front();
                levels.push_back(temp->val);
                q.pop();

                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            if (count % 2 != 0) {
                reverse(levels.begin(), levels.end());
            }

            result.push_back(levels);
            count++;
        }
        return result;
    }
};

// Utility function to print 2D vector
void printZigzag(const vector<vector<int>>& result) {
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example Tree:
    //         1
    //        / \
    //       2   3
    //      / \   \
    //     4   5   6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution sol;
    vector<vector<int>> result = sol.zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:\n";
    printZigzag(result);

    // Clean up memory (optional in contest, recommended in production)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}

// Check that the given Binary Tree is Max Heap or not
#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left = right = NULL;
    }
};

int countNodes(Node* root) {
    if(!root)   return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isCBT(Node* root, int index, int totalNodes) {
    if(!root)   return true;

    if(index > totalNodes)  return false;

    return isCBT(root->left, 2*index, totalNodes) && isCBT(root->right, 2*index + 1, totalNodes);
}

bool isMaxOrder(Node* root) {
    if(!root)   return true;

    if(root->left && root->val < root->left->val)   return false;
    if(root->right && root->val < root->right->val)   return false;

    return isMaxOrder(root->left) && isMaxOrder(root->right);
}

bool isMaxHeap(Node* root) {
    int index = 1;
    int totalNodes = countNodes(root);
    return isCBT(root, index, totalNodes) && isMaxOrder(root);
}

int main() {
    Node* root = new Node(30);
    root->left = new Node(20);
    root->right = new Node(10);
    root->left->left = new Node(5);
    root->left->right = new Node(8);

    if (isMaxHeap(root)) cout << "It is a Max-Heap\n";
    else cout << "Not a Max-Heap\n";

    return 0;
}

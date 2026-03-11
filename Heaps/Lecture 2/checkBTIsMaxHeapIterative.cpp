// Check that the given Binary Tree is Max Heap or not  (Iterative)
#include <iostream>
#include <queue>

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

bool isMaxHeap(Node* root) {
    if(!root)   return true;
    
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

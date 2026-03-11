#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left = right = nullptr;
    }
};

pair<bool, string> isMaxHeap(Node* root) {
    if (!root)
        return {true, "Empty tree (valid Max-Heap)"};

    queue<Node*> q;
    q.push(root);
    bool nullChildSeen = false;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        // Check left child
        if (curr->left) {
            if (nullChildSeen)
                return {false, "CBT violation at node: " + to_string(curr->val)};
            if (curr->val < curr->left->val)
                return {false, "Heap property violated: parent " + to_string(curr->val) +
                               " < left child " + to_string(curr->left->val)};
            q.push(curr->left);
        } else {
            nullChildSeen = true;
        }

        // Check right child
        if (curr->right) {
            if (nullChildSeen)
                return {false, "CBT violation at node: " + to_string(curr->val)};
            if (curr->val < curr->right->val)
                return {false, "Heap property violated: parent " + to_string(curr->val) +
                               " < right child " + to_string(curr->right->val)};
            q.push(curr->right);
        } else {
            nullChildSeen = true;
        }
    }

    return {true, "Valid Max-Heap"};
}

int main() {
    system("cls");
    Node* root = new Node(30);
    root->left = new Node(20);
    root->right = new Node(10);
    root->left->left = new Node(5);
    root->left->right = new Node(35);  // Heap property violation here

    pair<bool, string> result = isMaxHeap(root);

    cout << (result.first ? "YES: " : "NO: ") << result.second << endl;

    return 0;
}

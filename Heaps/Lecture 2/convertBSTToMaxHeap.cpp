#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }  
};

void reverseInorder(vector<int> &rev_inorder, Node* root){
    if(!root)   return;

    reverseInorder(rev_inorder, root->right);
    rev_inorder.push_back(root->val);
    reverseInorder(rev_inorder, root->left);
}

void buildTreeFromPreorder(vector<int> &rev_inorder, Node* root, int &i){
    if(!root)   return;

    root->val = rev_inorder[i++];
    buildTreeFromPreorder(rev_inorder, root->left, i);
    buildTreeFromPreorder(rev_inorder, root->right, i);
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
        while(!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if(temp) {
                cout << temp->val <<" ";
                if(temp->left)      q.push(temp->left);
                if(temp->right)      q.push(temp->right);
            }
            else {
                cout << endl;
                if(!q.empty())  q.push(NULL);
            }
        }
}

void print(vector<int> &v) {
    for(auto ele : v)   cout << ele <<" ";
    cout << endl;
}

int main() {
    Node* a = new Node(10);
    Node* b = new Node(5);
    Node* c = new Node(16);
    Node* d = new Node(1);
    Node* e = new Node(8);
    Node* f = new Node(12);
    Node* g = new Node(20);
    a->left = b;    a->right = c;
    b->left = d;    b->right = e;
    c->left = f;    c->right = g;
    levelOrderTraversal(a);
    cout << endl;

    vector<int> rev_inorder;
    reverseInorder(rev_inorder, a);
    print(rev_inorder);
    cout << endl;

    int i = 0;
    buildTreeFromPreorder(rev_inorder, a, i);
    levelOrderTraversal(a);
    cout << endl;
    
    return 0;
}
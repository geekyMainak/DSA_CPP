// Boundary Traversal
#include <iostream>
#include <queue>
#include <vector>
 
using namespace std;

class Node {
    public :
        int val;
        Node* left;
        Node* right;

    Node(int d) {
        this->val = d;
        this->left = NULL;
        this->right = NULL;
   }
};

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

void buildFromLevelOrder(Node* &root) {
    queue<Node*> q;
    cout << "Enter root :";
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter left node for " << temp->val << ":";
        int leftData;
        cin >> leftData;
        if(leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for " << temp->val << ":";
        int rightData;
        cin >> rightData;
        if(rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

void leftTraversal_Iterative(Node* root, vector<int> &v) {    // ITERATIVE
    if(!root)   return;
    Node* temp = root;

    while(temp) {
        if (temp->left || temp->right)  v.push_back(temp->val);  // Skip leaf nodes

            if (temp->left) temp = temp->left;
            else            temp = temp->right;
    }
}

void leftTraversal_Recursive(Node* root, vector<int> &v) {    // RECURSIVE
    if(!root || (!root->left && !root->right))   return;

    v.push_back(root->val); 

    if (root->left) leftTraversal_Recursive(root->left, v);
    else            leftTraversal_Recursive(root->right, v);
}

void leafTraversal(Node* root, vector<int> &v) {  
    if(!root)   return;

    if(!root->left && !root->right) {
        v.push_back(root->val);
    }
    leafTraversal(root->left, v);
    leafTraversal(root->right, v);
}

void rightTraversal_Iterative(Node* root, vector<int> &v) { // ITERATIVE
    Node* temp = root;
    vector<int> tempVec;
    while (temp) {
        if (temp->left || temp->right)  tempVec.push_back(temp->val);  // Skip leaf nodes

        if (temp->right) temp = temp->right;
        else             temp = temp->left;
    }
    // Add in reverse order
    for (int i = tempVec.size() - 1; i >= 1; --i)
        v.push_back(tempVec[i]);
}

void rightTraversal_Recursive(Node* root, vector<int> &v) {    // RECURSIVE
    if(!root || (!root->left && !root->right))   return;

    if (root->right) rightTraversal_Recursive(root->right, v);
    else            rightTraversal_Recursive(root->left, v);

    v.push_back(root->val); 
}

void boundaryTraversal(Node* root, vector<int> &v) {
    if (!root) return;

    v.push_back(root->val); // Add root
    //leftTraversal_Iterative(root->left, v);
    leftTraversal_Recursive(root->left,v);
    leafTraversal(root, v);
    //rightTraversal_Iterative(root, v);
    rightTraversal_Recursive(root->right,v);
}

int main () {
    Node* root = NULL;
    // 1 3 7 11 5 17 -1 -1 -1 -1 -1 -1 -1 
    buildFromLevelOrder(root);
    cout << endl <<"Level Order Traversal: \n";
    levelOrderTraversal(root);

    vector<int> v;
    boundaryTraversal(root, v);
    for(auto i : v)     cout << i <<" ";

    return 0;
}
// Height, Diameter and Count leaf nodes
#include <iostream>
#include <queue>
 
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

int countLeafNodes(Node* root) {
    if(!root)   return 0;
    if(!root->left && !root->right)     return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

pair <int, int> diameter_and_height(Node* root) {
    if(!root) {
        pair<int, int> p = make_pair(0,0);
        return p;
    }

    pair<int, int> left = diameter_and_height(root->left);
    pair<int, int> right = diameter_and_height(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}

int main () {
    Node* root = NULL;
    // 1 3 7 11 5 17 -1 -1 -1 -1 -1 -1 -1 
    buildFromLevelOrder(root);
    cout << endl <<"Level Order Traversal:\n";
    levelOrderTraversal(root);

    cout << "\nNumber of leaf nodes: " << countLeafNodes << endl;
    cout << "Height of the tree : " << diameter_and_height(root).second << endl;
    cout << "Diameter of the tree : " << diameter_and_height(root).first << endl;

    return 0;
}
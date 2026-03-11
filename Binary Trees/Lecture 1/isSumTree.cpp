// IS SUM TREE OR NOT
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

pair<bool, int> isSumTree(Node* root) {
    // base cases
    if (!root) {
        return {true, 0};  // empty tree is a sum tree
    }

    if(!root->left && !root->right) {
        pair<bool, int> p = make_pair(true, root->val);
        return p;
    }

    pair<bool, int> traverseLeft = isSumTree(root->left);
    pair<bool, int> traverseRight = isSumTree(root->right);

    bool isLeftSumTree = traverseLeft.first;
    bool isRightSumTree = traverseRight.first;
    bool condn = ((traverseLeft.second + traverseRight.second) == root->val);

    pair<bool, int> ans;
    ans.first = (isLeftSumTree && isRightSumTree && condn) ? true : false;
    ans.second = 2 * root->val;

    return ans;
}

int main () {
    Node* root = NULL;
    // 1 3 7 11 5 17 -1 -1 -1 -1 -1 -1 -1 
    buildFromLevelOrder(root);
    cout << endl <<"Level Order Traversal:\n";
    levelOrderTraversal(root);

    cout << "\nIs sum tree: ";
    if(isSumTree(root).first)   cout << "TRUE" << endl;
    else    cout << "FALSE" << endl;

    return 0;
}
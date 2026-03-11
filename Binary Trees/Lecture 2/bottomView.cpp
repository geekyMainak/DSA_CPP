// Bottom View Traversal
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
 
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

vector<int> bottomView(Node* root) {
    vector<int> ans;
    if(!root)   return ans;

    map<int, int> topNode;   // horizontalDistace, node->data
    queue<pair<Node*, int>> q;
    pair<Node*, int> temp = {root,0};
    q.push(temp);

    while(!q.empty()) {
       pair<Node*, int> temp = q.front();
       q.pop();

       Node* frontNode = temp.first;
       int hd = temp.second;

       topNode[hd] = frontNode->val;

       if(frontNode->left)  q.push({frontNode->left, hd-1});
       if(frontNode->right)  q.push({frontNode->right, hd+1});
    
    }

       for(auto i : topNode) {
        ans.push_back(i.second);
       }
    return ans;
}

int main () {
    Node* root = NULL;
    // 1 3 7 11 5 17 -1 -1 -1 -1 -1 -1 -1 
    buildFromLevelOrder(root);
    cout << endl <<"Level Order Traversal: \n";
    levelOrderTraversal(root);

    cout << "\nBottom View: ";
    vector<int> v = bottomView(root);
    for(auto i : v)     cout << i <<" ";

    return 0;
}
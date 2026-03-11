// Vertical Traversal
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

vector<vector<int>> verticalTraversal(Node*  root) {
    map<int, map<int, vector<int> > > nodes;    // hd, lvl , val
    queue<pair<Node* , pair<int, int> > > q;    // node , hd, lvl
    vector<vector<int>> ans;

    if(!root)   return ans;

    q.push({root, {0,0}});
    
    while(!q.empty()) {
        pair<Node* , pair<int, int> > temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        // Mark the answer
        nodes[hd][lvl].push_back(frontNode->val);

        // push the left and right  child
        if(frontNode->left)  q.push({frontNode->left, {hd-1, lvl+1}});
        if(frontNode->right)  q.push({frontNode->right, {hd+1, lvl+1}});

    }

        for (auto it1 = nodes.begin(); it1 != nodes.end(); ++it1) {
        vector<int> column;
        map<int, vector<int>>& levelMap = it1->second;

        for (auto it2 = levelMap.begin(); it2 != levelMap.end(); ++it2) {
            vector<int>& vals = it2->second;
            sort(vals.begin(), vals.end());
            column.insert(column.end(), vals.begin(), vals.end());
        }

        ans.push_back(column);
    }   
    return ans; 
}

int main () {
    Node* root = NULL;
    // 1 3 7 11 5 17 -1 -1 -1 -1 -1 -1 -1 
    buildFromLevelOrder(root);
    cout << endl <<"Level Order Traversal: \n";
    levelOrderTraversal(root);

    vector<vector<int>> v = verticalTraversal(root);
    cout << "\nVertical Traversal:\n";
    for (auto column : v) {
        for (int val : column)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
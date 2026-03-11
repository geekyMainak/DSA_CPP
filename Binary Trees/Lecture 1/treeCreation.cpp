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

Node* buildTree(Node* root) {
    cout << "Enter the root: ";
    int data;
    cin >> data;

    root = new Node(data);
    if(data == -1)      return NULL;

    // LEFT PART
    cout << "Enter the data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    // RIGHT PART
    cout << "Enter the data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
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

int main () {
    Node* root = NULL;
    buildFromLevelOrder(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
     root = buildTree(root);
    cout << endl <<"Level Order Traversal:\n";
    levelOrderTraversal(root);


    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to build tree from space-separated level order input
Node* buildTree(const string& str) {
    if (str.empty() || str[0] == 'N') return NULL;

    istringstream iss(str);
    vector<string> values;
    string val;
    while (iss >> val) values.push_back(val);

    Node* root = new Node(stoi(values[0]));
    queue<Node*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < values.size()) {
        Node* curr = q.front(); q.pop();

        if (values[i] != "N") {
            curr->left = new Node(stoi(values[i]));
            q.push(curr->left);
        }
        i++;
        if (i >= values.size()) break;

        if (values[i] != "N") {
            curr->right = new Node(stoi(values[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// Morris Inorder Traversal
vector<int> morrisInorderTraversal(Node* root) {
    vector<int> result;
    Node* curr = root;

    while (curr) {
        if (!curr->left) {
            result.push_back(curr->data);
            curr = curr->right;
        } else {
            Node* pred = curr->left;
            while (pred->right && pred->right != curr) {
                pred = pred->right;
            }

            if (!pred->right) {
                pred->right = curr;
                curr = curr->left;
            } else {
                pred->right = NULL;
                result.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return result;
}

// Morris Preorder Traversal
vector<int> morrisPreorderTraversal(Node* root) {
    vector<int> result;
    Node* curr = root;

    while (curr) {
        if (!curr->left) {
            result.push_back(curr->data);
            curr = curr->right;
        } else {
            Node* pred = curr->left;
            while (pred->right && pred->right != curr) {
                pred = pred->right;
            }

            if (!pred->right) {
                pred->right = curr;
                result.push_back(curr->data);
                curr = curr->left;
            } else {
                pred->right = NULL;
                curr = curr->right;
            }
        }
    }

    return result;
}

int main() {
    string input;
    cout << "Enter space-separated level-order tree (use N for null):\n";
    getline(cin, input);

    Node* root = buildTree(input);

    vector<int> inorder = morrisInorderTraversal(root);
    vector<int> preorder = morrisPreorderTraversal(root);

    cout << "\nMorris Inorder Traversal:\n";
    for (int val : inorder) cout << val << " ";
    
    cout << "\n\nMorris Preorder Traversal:\n";
    for (int val : preorder) cout << val << " ";

    cout << endl;
    return 0;
}

#include <iostream>
using namespace std;

struct Node {
    int data;
    int height;
    Node *left, *right;

    Node(int value) {
        data = value;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(Node* root) {
    if(!root)   return 0;
    return root->height;
}

// Left Rotation
Node* leftRotation(Node* root) {
    Node* child = root->right;          
    Node* leftChild = child->left;
    child->left = root;
    root->right = leftChild;
    
    // Update the height 
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    
    return child;
}

// Right Rotation
Node* rightRotation(Node* root) {
    Node* child = root->left;          
    Node* rightChild = child->right;
    child->right = root;
    root->left = rightChild;

    // Update height of root and child
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    
    return child;
}

Node* insert(Node* root, int key) {
    // DNE
    if(!root)   return new Node(key);

    // Exist (Insert the key in the tree)
    if(key < root->data)    
        root->left = insert(root->left, key);
    else if(key > root->data)      
        root->right = insert(root->right, key);    
    else    
        return root;

    // Update the height of the tree
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Check Balancing
    int balance = getHeight(root->left) - getHeight(root->right);

    // Now Checking the type of Rotation cases
    // Left Left Case
    if(balance > 1 && key < root->left->data) {
        return rightRotation(root);
    }
    // Right Right Case
    else if(balance < -1 && key > root->right->data) {
        return leftRotation(root);
    }
    // Left Right Case
    else if(balance > 1 && key > root->left->data) {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    // Right Left Case
    else if (balance < -1 && key < root->right->data) {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    // No Balancing
    else {
        return root;
    }
}

void inOrder(Node* root) {
    if(!root)   return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main () {
    // Duplicates elements are not present
    Node* root = NULL;
    root = insert(root,10);
    root = insert(root,12);
    root = insert(root,16);
    root = insert(root,13);
    root = insert(root,14);

    cout << "Inorder: ";
    inOrder(root);   //  should print: 10 12 13 14 16

    return 0;
}

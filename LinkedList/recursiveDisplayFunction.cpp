#include <iostream>

using namespace std;

class Node {
public :
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void display(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->val <<"-->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void displayRecursive(Node* head) {
    // base case
    if(head == NULL) {
        cout << "NULL\n";
        return;
    }
    cout << head->val <<"-->";
    displayRecursive(head->next);
}

void displayReverseRecursive(Node* head) {
    // base case
    if(head == NULL) {
        return;
    }
    displayReverseRecursive(head->next);
    cout << head->val <<"-->";
}

int main() {
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    display(a);
    displayRecursive(a);
    displayReverseRecursive(a);  // LINKED LIST IS NOT REVERSE WE ARE PRINTING IT IN REVERSE ORDER

    return 0;
}
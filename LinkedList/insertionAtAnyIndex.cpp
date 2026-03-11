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

void insertionAtAnyIndex(Node* &head, int idx, int data) {
    Node* temp = new Node(data);
    if(idx == 0) {
        temp->next = head;
        head = temp;
    }
    else {
    Node* h1 = head;
    for(int i = 0; i < idx - 1; i++)    h1 = h1->next;
    temp->next = h1->next;
    h1->next = temp;
    }
}

void display(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->val << "-->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    cout << "Enter the number of nodes: ";
    int n;
    cin >> n;
    Node* head = new Node(-1);   // DUMMY NODE
    Node* tail = head;

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        tail->next = new Node(temp);
        tail = tail->next;
    }
    head = head->next;
    cout << "The given list is ";
    display(head);

    int idx, data;
    cout << "Enter the index (0th based indexing) and value: ";
    cin >> idx >> data;

    insertionAtAnyIndex(head, idx, data);

    cout << "After insertion: ";
    display(head);

    return 0;
}
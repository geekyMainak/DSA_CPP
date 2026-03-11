// DOUBLY LINKED LIST IMPLEMENTATION INSERTION AND DELETION
#include <iostream>
using namespace std;

class Node {
public:
    Node* prev;
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

Node* insertAtAnyIndex(Node* &head, int val, int idx) {
    Node* newNode = new Node(val);

    // Inserting into an empty list
    if (!head) {
        if (idx == 0) {
            return newNode;
        } else {
            cout << "Index out of bounds!" << endl;
            return NULL;
        }
    }

    // Insertion at begining
    if(idx == 0) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else {
    // Insertion at any index except begining 
    Node* temp = head;
    for(int i = 0; i < idx - 1; i++) {
        if (!temp->next) {
            cout << "Index out of bounds!" << endl;
            delete newNode;
            return head;
        }
        temp = temp->next;
    }

    // Insertion at mid or end   ALternate
    // newNode->next = temp->next;
    // if (temp->next)     temp->next->prev = newNode;
    // temp->next = newNode;
    // newNode->prev = temp;

    bool flag = true;
    if(!temp->next)     flag = false;

    if(flag) {
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }   else {
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    return head;
}

Node* deleteAtAnyIndex(Node* head, int idx) {
    if (!head) {
        cout << "List is empty!" << endl;
        return NULL;
    }

    // Case 1: Delete head
    if (idx == 0) {
        Node* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        delete temp;
        return head;
    }

    // Case 2: Delete from middle or end
    Node* temp = head;
    for (int i = 0; i < idx; i++) {   // Traversing to idx - 1
        temp = temp->next;
        if (!temp) {
            cout << "Index out of bounds!" << endl;
            return head;
        }
    }
    if (temp->prev)      temp->prev->next = temp->next;
    if (temp->next)      temp->next->prev = temp->prev;
    delete temp;
    
    return head;
}

void display(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->val << "<->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    cout << "Enter the number of nodes: ";
    int n;
    cin >> n;

    if (n <= 0) {
        cout << "List is empty." << endl;
        return 0;
    }

    cout << "Enter the elements: ";
    int x;
    cin >> x;

    Node* head = new Node(x);
    Node* tail = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        Node* newNode = new Node(x);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    display(head);
    
    insertAtAnyIndex(head, 70, 4);
    deleteAtAnyIndex(head, 2);
    display(head);

    return 0;
}



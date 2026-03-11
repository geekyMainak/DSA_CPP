#include <iostream>
#include <string>

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

void insertionAtAnyIndex(Node* &head, int idx, int data, int &size) {
    Node* temp = new Node(data);
    if(idx == 0) {
        temp->next = head;
        head = temp;
        size++;
    }
    else if(idx < 0 || idx >= size) {
        cout << "Invalid index\n";
    }
    else {
    Node* h1 = head;
    for(int i = 0; i < idx - 1; i++)    h1 = h1->next;
    temp->next = h1->next;
    h1->next = temp;
    size++;
    }
}

void deletionAtAnyIndex(Node* &head, int idx, int &size) {
    Node* temp;
    if(idx == 0) {
        temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    else if(idx < 0 || idx >= size) {
        cout << "Invalid index\n";
    }
    else {
    Node* h1 = head;
    for(int i = 0; i < idx - 1; i++)    h1 = h1->next;
    temp = h1->next;
    h1->next = temp->next;
    delete temp;
    size--;
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
    int size = 0;
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        tail->next = new Node(temp);
        tail = tail->next;
        size++;
    }
    head = head->next;
    cout << "The given list is ";
    display(head);
    cout << "Do you need any changes in the list ?(YES / NO): ";
    string s;
    cin >> s;
    while(s != "NO") {
        int idx, data;
        cout << "\nChoose an operation:\n";
        cout << "1. Insert node\n2. Delete node\n";
        int x;
        cin >> x;

        switch(x) {
        case  1:
            cout << "Enter the index (0th based indexing) and value: ";
            cin >> idx >> data;
            insertionAtAnyIndex(head, idx, data, size);
            break;
        
            case 2:
                cout << "Enter the index (0th based indexing): ";
                cin >> idx;
                deletionAtAnyIndex(head, idx, size);
                break;
        }
    cout << "\nDo you need more changes? (YES / NO): ";
    cin >> s;
    }

    cout << "\nFinal list: ";
    display(head);

    
    return 0;
}

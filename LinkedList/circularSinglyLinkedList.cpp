#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

// Function to display the circular list
void display(Node* head) {
    if (!head) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->val << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)" << endl;
}

// Insert at any index
Node* insertAtIndex(Node* head, int val, int idx) {
    Node* newNode = new Node(val);

    // Case 1: Empty list
    if (!head) {
        if (idx == 0) {
            newNode->next = newNode;
            return newNode;
        } else {
            cout << "Index out of bounds!" << endl;
            delete newNode;
            return nullptr;
        }
    }

    // Case 2: Insert at head
    if (idx == 0) {
        Node* tail = head;
        while (tail->next != head)
            tail = tail->next;

        newNode->next = head;
        tail->next = newNode;
        head = newNode;
        return head;
    }

    // Case 3: Insert at middle or end
    Node* temp = head;
    for (int i = 0; i < idx - 1; i++) {
        temp = temp->next;
        if (temp == head) {
            cout << "Index out of bounds!" << endl;
            delete newNode;
            return head;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Delete at any index
Node* deleteAtIndex(Node* head, int idx) {
    if (!head) {
        cout << "List is empty!" << endl;
        return nullptr;
    }

    // Case 1: Delete head
    if (idx == 0) {
        // Only one node
        if (head->next == head) {
            delete head;
            return nullptr;
        }

        Node* tail = head;
        while (tail->next != head)
            tail = tail->next;

        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
        return head;
    }

    // Case 2: Delete middle or end
    Node* temp = head;
    for (int i = 0; i < idx - 1; i++) {
        temp = temp->next;
        if (temp->next == head) {
            cout << "Index out of bounds!" << endl;
            return head;
        }
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;

    return head;
}

int main() {
    Node* head = nullptr;

    head = insertAtIndex(head, 10, 0); // Insert at head
    head = insertAtIndex(head, 20, 1);
    head = insertAtIndex(head, 30, 2);
    head = insertAtIndex(head, 5, 0);  // New head
    display(head);

    head = deleteAtIndex(head, 2);     // Delete element at index 2
    display(head);

    head = deleteAtIndex(head, 0);     // Delete head
    display(head);

    return 0;
}

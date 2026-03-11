#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;

    Node(int val) {
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

// Display in forward direction
void displayForward(Node* head) {
    if (!head) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->val << " <-> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)" << endl;
}

// Display in reverse direction
void displayReverse(Node* head) {
    if (!head) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* tail = head->prev;
    Node* temp = tail;
    do {
        cout << temp->val << " <-> ";
        temp = temp->prev;
    } while (temp != tail);
    cout << "(tail)" << endl;
}

// Insert at any index
Node* insertAtIndex(Node* head, int val, int idx) {
    Node* newNode = new Node(val);

    // Case 1: Empty list
    if (!head) {
        if (idx == 0) {
            newNode->next = newNode;
            newNode->prev = newNode;
            return newNode;
        } else {
            cout << "Index out of bounds!" << endl;
            delete newNode;
            return nullptr;
        }
    }

    // Case 2: Insert at head
    if (idx == 0) {
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
        return head;
    }

    // Case 3: Insert in middle or end
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
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

// Delete at any index
Node* deleteAtIndex(Node* head, int idx) {
    if (!head) {
        cout << "List is empty!" << endl;
        return nullptr;
    }

    // Only one node
    if (head->next == head && idx == 0) {
        delete head;
        return nullptr;
    }

    // Case 1: Delete head
    if (idx == 0) {
        Node* tail = head->prev;
        Node* temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
        return head;
    }

    // Case 2: Delete middle or end
    Node* temp = head;
    for (int i = 0; i < idx; i++) {
        temp = temp->next;
        if (temp == head) {
            cout << "Index out of bounds!" << endl;
            return head;
        }
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;

    return head;
}

int main() {
    Node* head = nullptr;

    head = insertAtIndex(head, 10, 0);
    head = insertAtIndex(head, 20, 1);
    head = insertAtIndex(head, 30, 2);
    head = insertAtIndex(head, 5, 0);   // Insert at head

    cout << "Forward: ";
    displayForward(head);

    cout << "Reverse: ";
    displayReverse(head);

    head = deleteAtIndex(head, 2); // Delete index 2
    cout << "After deleting index 2:" << endl;
    displayForward(head);

    head = deleteAtIndex(head, 0); // Delete head
    cout << "After deleting head:" << endl;
    displayForward(head);

    return 0;
}

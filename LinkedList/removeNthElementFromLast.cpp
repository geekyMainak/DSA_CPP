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

Node* removeNthFromEnd(Node* head, int n) {
        Node* temp;
        Node* slow = head;
        Node* fast = head;

        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        if(fast == NULL) {
            temp = head;
            head = head->next;
            delete(temp);
            return head;
        }

        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        temp = slow->next;
        slow->next = temp->next;
        delete(temp);

        return head;
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

    int idx;
    cout << "Enter the index (1 based indexing): ";
    cin >> idx;

    cout << "After removing Nth element from the end: ";
    removeNthFromEnd(head, idx);

    display(head);

    return 0;
}

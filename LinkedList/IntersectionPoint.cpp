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

Node *getIntersectionNode(Node *headA, Node *headB) {
        if (!headA || !headB) return NULL;
        Node* slow = headA;
        Node* fast = headB;
        while(slow != fast) {
            slow = (slow == NULL) ? headA : slow->next;
            fast = (fast == NULL) ? headB : fast->next;
        }
        return slow;
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
    // Create common intersection part: 8 -> 10
    Node* common = new Node(8);
    common->next = new Node(10);

    // List 1: 1 -> 2 -> 3 -> 8 -> 10
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = common;

    // List 2: 4 -> 5 -> 8 -> 10
    Node* head2 = new Node(4);
    head2->next = new Node(5);
    head2->next->next = common;

    cout << "List 1: ";
    display(head1);
    cout << "List 2: ";
    display(head2);

    Node* intersection = getIntersectionNode(head1, head2);
    if (intersection)
        cout << "The intersection node is: " << intersection->val << endl;
    else
        cout << "No intersection node found." << endl;

    return 0;
}
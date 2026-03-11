// Merge two sorted linked list
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

Node* mergeTwoLists(Node* list1, Node* list2) {
        Node* dummy = new Node(-1);
        Node* temp = dummy;

        while(list1 && list2) {
            if(list1->val >= list2->val) {
                temp->next = list2;
                list2 = list2->next;
            }
            else {
                temp->next = list1;
                list1 = list1->next;
            }
            temp = temp->next;
        }
        temp->next = (list1) ? list1 : list2;

        return dummy->next;        
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
    cout << "List 1: ";
    display(head);


    cout << "\nEnter the number of nodes: ";
    int n2;
    cin >> n2;
    Node* head2 = new Node(-1);   // DUMMY NODE
    Node* tail2 = head2;

    cout << "Enter the elements: ";
    for(int i = 0; i < n2; i++) {
        int temp;
        cin >> temp;
        tail2->next = new Node(temp);
        tail2 = tail2->next;
    }
    head2 = head2->next;
    cout << "List 2: ";
    display(head2);

    Node* head3 = mergeTwoLists(head, head2);
    cout << "\nAfter sorting: ";
    display(head3);

    return 0;
}
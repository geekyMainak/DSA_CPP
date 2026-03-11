// Merge Sort in Linked List
#include <iostream>

using namespace std;

class ListNode {
public :
    int val;
    ListNode* next;
        ListNode(int val) {
            this->val = val;
            this->next = NULL;
        }
};

ListNode* getMid(ListNode* &head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* mergeTwoLists(ListNode* &list1, ListNode* &list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

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

    ListNode* sortList(ListNode* &head) {
        if(!head || !head->next)    return head;

        ListNode* mid = getMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);

        return mergeTwoLists(left, right);
    }

    void display(ListNode* head) {
    ListNode* temp = head;
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
    ListNode* head = new ListNode(-1);   // DUMMY NODE
    ListNode* tail = head;

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        tail->next = new ListNode(temp);
        tail = tail->next;
    }
    head = head->next;
    cout << "List: ";
    display(head);

    cout <<"The sorted list: ";
    head = sortList(head);
    display(head);

    return 0;
}
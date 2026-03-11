// FLATTEN LINKED LIST
#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = NULL;
        next = NULL;
        child = NULL;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)   return NULL;

        Node* curr = head;
        while(curr) {
            if(curr->child) {
                // Save the next node
                Node* next = curr->next;

                // Flatten child list
                Node* child = flatten(curr->child);

                // Insert the child list
                curr->next = child;
                child->prev = curr;
                curr->child = NULL;

                // Go to the end of the child list
                while(curr->next)   curr = curr->next;
                
                // Reconnect with next
                curr->next = next;
                if(next)    next->prev = curr;
            }
            curr = curr->next;
        }
        return head;        
    }
};

// Function to print flattened list
void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->val;
        if (curr->next) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Build the list manually for input:
    // [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    Node* n10 = new Node(10);
    Node* n11 = new Node(11);
    Node* n12 = new Node(12);

    // First level
    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;
    n5->next = n6; n6->prev = n5;

    // Second level (child of 3)
    n3->child = n7;
    n7->next = n8; n8->prev = n7;
    n8->next = n9; n9->prev = n8;
    n9->next = n10; n10->prev = n9;

    // Third level (child of 8)
    n8->child = n11;
    n11->next = n12; n12->prev = n11;

    // Run solution
    Solution sol;
    Node* flattenedHead = sol.flatten(n1);

    // Print flattened list
    printList(flattenedHead);

    return 0;
}

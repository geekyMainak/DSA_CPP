// BY ME
#include <iostream>
#include <vector>
using namespace std;

/* Node definition */
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/* Your Solution class */

class Solution {
public:
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);

        if(!head) {
            head = newNode;
            tail = newNode;
            return;
        } else {
                tail->next = newNode;
                tail = newNode;
        }
    }

    Node* copyRandomList(Node* head) {
        // step 1: Copy the list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;
        while(temp) {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        // step 2: Add clone node in between original node
        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while(originalNode && cloneNode) {
            Node* next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;

            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }

       // step 3: Copy Random Pointers
        temp = head;
        while(temp) {
             temp->next->random = (temp->random) ?
                 temp->random->next : temp->random;
              temp = temp->next->next;
        }

        // step 4: Revert changes in step 2
        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode && cloneNode) {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;

            if(originalNode)    cloneNode->next = originalNode->next;
            cloneNode = cloneNode->next;
        }

        // step 5: return cloneHead as answer
        return cloneHead;       
    }
};

/* Helper to print a list */
void printList(Node* head) {
    while (head) {
        cout << "Val: " << head->val << ", ";
        if (head->random)
            cout << "Random: " << head->random->val;
        else
            cout << "Random: NULL";
        cout << endl;
        head = head->next;
    }
}

/* Main to test */
int main() {
    // Step 1: Create original nodes
    vector<Node*> nodes;
    vector<pair<int, int>> input = {
        {7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0}
    };

    for (auto& p : input)
        nodes.push_back(new Node(p.first));

    // Step 2: Connect next pointers
    for (int i = 0; i < nodes.size() - 1; ++i)
        nodes[i]->next = nodes[i + 1];

    // Step 3: Connect random pointers
    for (int i = 0; i < input.size(); ++i) {
        int randIndex = input[i].second;
        nodes[i]->random = (randIndex != -1) ? nodes[randIndex] : nullptr;
    }

    Node* head = nodes[0];

    // Step 4: Copy list
    Solution sol;
    Node* copied = sol.copyRandomList(head);

    // Step 5: Print copied list
    cout << "Copied List:\n";
    printList(copied);

    return 0;
}
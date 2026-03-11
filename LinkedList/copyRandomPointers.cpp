// BY CHATGPT
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
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        // Step 1: Clone nodes and insert next to originals
        Node* temp = head;
        while (temp) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        // Step 2: Copy random pointers
        temp = head;
        while (temp) {
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        // Step 3: Restore original and separate clone
        Node* dummy = new Node(-1);
        Node* cloneTail = dummy;
        Node* original = head;

        while (original) {
            cloneTail->next = original->next;
            cloneTail = cloneTail->next;

            original->next = cloneTail->next;
            original = original->next;
        }

        return dummy->next;
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

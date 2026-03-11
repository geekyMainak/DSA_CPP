#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Stack class using linked list
class Stack {
private:
    Node* topNode;

public:
    Stack() {
        topNode = nullptr;
    }

    // Push operation
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
        cout << value << " pushed to stack.\n";
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow. Cannot pop.\n";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        cout << temp->data << " popped from stack.\n";
        delete temp;
    }

    // Peek / Top operation
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return -1; // return an invalid value
        }
        return topNode->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return topNode == nullptr;
    }

    // Display stack contents
    void display() {
        Node* temp = topNode;
        cout << "Stack: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    // Destructor to free memory
    // ~Stack() {
    //     while (!isEmpty()) {
    //         pop();
    //     }
    // }
};

// Driver code
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Top element: " << s.top() << "\n";
    s.pop();
    s.display();

    return 0;
}

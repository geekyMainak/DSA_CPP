#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        next = NULL;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue(){
        front = rear = NULL;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        if(rear == NULL) {  // first element
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    void pop() {
        if(isEmpty()) {  // first element
            cout <<  "Queue underflow!" << endl;
            return;
        } 
        else {
            Node* temp = front;
            front = front->next;
            delete(temp);
        }
        if (front == NULL)   rear = NULL;

    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        else    return front->val;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void display() {
    Node* temp = front;
    while(temp) {
        cout << temp->val <<" ";
        temp = temp->next;
    }
    cout << endl;
    }
};

int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    
    q.display(); 

    return 0;
}
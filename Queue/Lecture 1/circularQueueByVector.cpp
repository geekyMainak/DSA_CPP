#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue {
public:
    int front;
    int rear;
    int size;
    vector<int> arr;

    MyCircularQueue(int k) {
        front = -1;
        rear = -1;
        size = k;
        arr = vector<int>(k);  // simplified and direct
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        if (isEmpty()) front = rear = 0;
        else rear = (rear + 1) % size;
        arr[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        if (front == rear) front = rear = -1; // only one element
        else front = (front + 1) % size;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return arr[front];        
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return arr[rear];        
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return (rear + 1) % size == front;
    }
};

int main() {
    MyCircularQueue* q = new MyCircularQueue(3); // Initialize queue of size 3

    cout << "Enqueue 1: " << q->enQueue(1) << endl;  // true
    cout << "Enqueue 2: " << q->enQueue(2) << endl;  // true
    cout << "Enqueue 3: " << q->enQueue(3) << endl;  // true
    cout << "Enqueue 4 (should fail): " << q->enQueue(4) << endl;  // false (full)

    cout << "Rear: " << q->Rear() << endl;           // 3
    cout << "Is Full: " << q->isFull() << endl;      // true

    cout << "Dequeue: " << q->deQueue() << endl;     // true
    cout << "Enqueue 4 (after dequeue): " << q->enQueue(4) << endl; // true

    cout << "Rear: " << q->Rear() << endl;           // 4
    cout << "Front: " << q->Front() << endl;         // 2

    cout << "Dequeue: " << q->deQueue() << endl;     // true
    cout << "Dequeue: " << q->deQueue() << endl;     // true
    cout << "Dequeue: " << q->deQueue() << endl;     // true
    cout << "Dequeue (should fail): " << q->deQueue() << endl; // false (empty)

    cout << "Is Empty: " << q->isEmpty() << endl;    // true

    delete q;
    return 0;
}

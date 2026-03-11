#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int size;
    int front;
    int rear;

public:
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = val;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        if (front == rear) {
            // Only one element
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }

    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue q(5);  // capacity is 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();  // 10 20 30 40 50

    q.dequeue();
    q.dequeue();

    q.display();  // 30 40 50

    q.enqueue(60);
    q.enqueue(70);  // Reuses freed space

    q.display();   // 30 40 50 60 70

    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;

    return 0;
}

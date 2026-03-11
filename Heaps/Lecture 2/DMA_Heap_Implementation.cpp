#include <iostream>
#include <stdexcept>

using namespace std;

class minHeap {
private:
    int* arr;
    int idx;
    int capacity;

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 1; i < idx; ++i)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
    }

public:
    minHeap(int initialCapacity = 100) {
        capacity = initialCapacity;
        arr = new int[capacity];
        idx = 1; 
    }

    int top() {
        if (idx == 1)    cout << "Heap is empty";
        return arr[1];
    }

    void push(int val) {
        if (idx >= capacity)
            resize();

        int i = idx;
        arr[idx++] = val;

        while (i != 1 && arr[i / 2] > arr[i]) {
            swap(arr[i / 2], arr[i]);
            i /= 2;
        }
    }

    void pop() {
        if (idx == 1) return;  

        arr[1] = arr[--idx];  

        int i = 1;

        while (true) {
            int left = 2 * i;
            int right = 2 * i + 1;
            int smallest = i;

            if (left < idx && arr[left] < arr[smallest])
                smallest = left;

            if (right < idx && arr[right] < arr[smallest])
                smallest = right;

            if (smallest != i) {
                swap(arr[i], arr[smallest]);
                i = smallest; 
            } 
            else    break;  
        }
    }

    int size() {
        return idx - 1;
    }

    bool empty() {
        return idx == 1;
    }

    void clear() {
        idx = 1;
    }

    void display() {
        cout << "Heap elements (level-order): ";
        for (int i = 1; i < idx; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }

    
    ~minHeap() {
        delete[] arr;
    }
};

int main() {
    minHeap h;
    h.push(10);
    h.push(5);
    h.push(2);
    h.push(20);

    h.display();  
    cout << "Top element: " << h.top() << endl;  

    h.pop();
    h.display();   

    cout << (h.empty() ? "Heap is empty" : "Heap is not empty") << endl;

    return 0;
}

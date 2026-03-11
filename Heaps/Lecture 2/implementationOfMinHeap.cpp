// #include <iostream>

// using namespace std;

// class minHeap {
// public :
//     int arr[100];
//     int idx;

//     minHeap() {
//         idx = 1;
//     }

//     int top() {
//         if (idx == 1)   throw runtime_error("Heap is empty");
//         return arr[1];
//     }

//     void push(int val) {
//         int i = idx;
//         arr[idx++] = val;

//         while(i != 1 && arr[i / 2] > arr[i]) { 
//             swap(arr[i/2], arr[i]);
//             i /= 2;
//         }
//     }

//     int size() {
//         return idx-1;
//     }

//     void clear() {
//         idx = 1;
//     }

//     void pop() {
//         // Step 1: Check if heap is empty
//         if (idx == 1) return;  // Heap has no elements

//         // Step 2: Replace root with the last element in the heap
//         arr[1] = arr[--idx];   // Decrease heap size and move last element to root

//         int i = 1;  // Start at the root

//         // Step 3: Percolate down to restore heap property
//         while (2 * i < idx) {  // While the current node has at least a left child
//             int left = 2 * i;         // Index of left child
//             int right = 2 * i + 1;    // Index of right child
//             int smallest = left;      // Assume left child is smaller initially

//             // Step 4: Check if right child exists and is smaller than left
//             if (right < idx && arr[right] < arr[left])
//             smallest = right;  // Update smallest to right if smaller

//             // Step 5: If current node is bigger than smallest child, swap them
//             if (arr[i] > arr[smallest]) {
//                 swap(arr[i], arr[smallest]);  // Swap parent with smaller child
//                 i = smallest;  // Move down to the child's position
//             } 
//             else    break;  // Heap property is restored
//         }
//     }

//     bool empty() {
//         return  idx == 1;
//     }

//     void display() {
//         cout << "Heap elements (level-order): ";
//         for(int i = 1; i < idx; i++)    cout << arr[i] << " ";
//         cout << endl;
//     }

// };

// int main() {
//     minHeap h;
//     h.push(10);
//     h.push(5);
//     h.push(2);
//     h.push(20);

//     h.display();     // Output: 2 10 5 20
//     cout << h.top() << endl;  // Output: 2

//     h.pop();
//     h.display();     // Output: 5 10 20

//     cout << (h.empty() ? "Heap is empty" : "Heap is not empty") << endl;

//     return 0;
// }




#include <iostream>
#include <stdexcept>
using namespace std;

class minHeap {
public:
    int* arr;   // dynamic array
    int idx;    // current index (next empty position)
    int cap;    // capacity of the heap

    minHeap(int capacity = 10) {
        cap = capacity;
        arr = new int[cap + 1]; // index 0 unused
        idx = 1;
    }

    ~minHeap() {
        delete[] arr;
    }

    int top() {
        if (idx == 1) throw runtime_error("Heap is empty");
        return arr[1];
    }

    void push(int val) {
        if (idx > cap) resize();

        int i = idx;
        arr[idx++] = val;

        while (i != 1 && arr[i / 2] > arr[i]) {
            swap(arr[i / 2], arr[i]);
            i /= 2;
        }
    }

    int size() {
        return idx - 1;
    }

    void clear() {
        idx = 1;
    }

    void pop() {
        if (idx == 1) return; // empty heap

        arr[1] = arr[--idx];  // replace root with last element

        int i = 1;
        while (true) {
            int left = 2 * i;
            int right = 2 * i + 1;
            int smallest = i;

            if (left < idx && arr[left] < arr[smallest])
                smallest = left;

            if (right < idx && arr[right] < arr[smallest])
                smallest = right;

            if (smallest == i) break;

            swap(arr[i], arr[smallest]);
            i = smallest;
        }
    }

    bool empty() {
        return idx == 1;
    }

    void display() {
        cout << "Heap elements (level-order): ";
        for (int i = 1; i < idx; i++) cout << arr[i] << " ";
        cout << endl;
    }

private:
    void resize() {
        int newCap = cap * 2;
        int* newArr = new int[newCap + 1];
        for (int i = 1; i < idx; i++)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
        cap = newCap;
    }
};

int main() {
    minHeap h;
    h.push(10);
    h.push(5);
    h.push(2);
    h.push(20);

    h.display();              // Output: 2 10 5 20
    cout << h.top() << endl;  // Output: 2

    h.pop();
    h.display();              // Output: 5 10 20

    cout << (h.empty() ? "Heap is empty" : "Heap is not empty") << endl;

    return 0;
}

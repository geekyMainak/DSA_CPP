#include <iostream>

using namespace std;

void maxheapify(int arr[], int n, int i) {
    while (2 * i <= n) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;

        if (left <= n && arr[left] > arr[largest])
            largest = left;

        if (right <= n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            i = largest;  // Move down to the new position
        } else {
            break;  // Heap property satisfied
        }
    }
}

void buildMaxHeap(int arr[], int n) {
    for(int i = n/2; i >= 1; i--)   maxheapify(arr, n, i);
}

void minheapify(int arr[], int n, int i) {
    while(2*i <= n) {
        int left = 2*i;
        int right = 2*i + 1;
        int smallest = i;

        if(left <= n && arr[left] < arr[smallest])     smallest = left;
        if(right <= n && arr[right] < arr[smallest])   smallest = right;

        if(smallest != i) {
            swap(arr[i], arr[smallest]);
            i = smallest;
        }
        else    break;
    }
}

void buildMinHeap(int arr[], int n) {
    for(int i = n/2; i >= 1; i--)   minheapify(arr, n, i);
}

int main() {
    int original[] = {-1, 10, 20, 15, 30, 40};  // Dummy at index 0
    int n = sizeof(original) / sizeof(int) - 1;

    int minHeapArr[6], maxHeapArr[6];
    for (int i = 0; i <= n; i++) {
        minHeapArr[i] = original[i];
        maxHeapArr[i] = original[i];
    }

    cout << "Original array: ";
    for (int i = 1; i <= n; i++) cout << original[i] << " ";

    buildMinHeap(minHeapArr, n);
    cout << "\nMin-heap: ";
    for (int i = 1; i <= n; i++) cout << minHeapArr[i] << " ";

    buildMaxHeap(maxHeapArr, n);
    cout << "\nMax-heap: ";
    for (int i = 1; i <= n; i++) cout << maxHeapArr[i] << " ";

    return 0;
}



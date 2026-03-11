#include <iostream>

using namespace std;

void cycleSortIterative(int arr[], int size) {
    int i = 0; 
    while(i < size) {
        int correctIdx = arr[i] - 1;
        if(i == correctIdx)     i++;
        else    swap(arr[i], arr[correctIdx]);
    }
}

void cycleSortRecursive(int arr[], int size, int st) {
    // base case
    if(st == size)    return;

    if(st != arr[st] - 1) {
        swap(arr[st], arr[arr[st] - 1]);
        cycleSortRecursive(arr, size, st);
    }
    cycleSortRecursive(arr, size, st + 1);
}

int main () {
    int arr1[] = {5,1,2,4,3,6,7,10,8,9};  
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {5,1,2,4,3,6,7,10,8,9,15,13,14,11,12};  
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    cycleSortRecursive(arr1, n1, 0);
    cycleSortIterative(arr2, n2);

    for(int i = 0; i < n1; i++) {
        cout << arr1[i] <<" ";
    }

    cout << endl;

    for(int i = 0; i < n2; i++) {
        cout << arr2[i] <<" ";
    }
    
    return 0;
}
#include <iostream>

using namespace std;

int partition(int arr[], int st, int end) {
    int pivot = arr[end], idx = st - 1;
    for(int j = st; j < end; j++) {
        if(arr[j] <= pivot)  swap(arr[++idx], arr[j]);
    }
    swap(arr[++idx], arr[end]);

    return idx;
}

void quickSort(int arr[], int st, int end) {
    if(st < end) {
        int piv_idx = partition(arr, st, end);
        quickSort(arr, st, piv_idx - 1);
        quickSort(arr, piv_idx + 1, end);
    }
}

int main () {
    int arr[] = {5,6,1,9,3,8,4,10,13,22};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++) {
        cout << arr[i] <<" ";
    }

    return 0;
}
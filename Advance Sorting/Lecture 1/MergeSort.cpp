#include <iostream>

using namespace std;

void merge(int arr[], int st, int mid, int end) {
    int temp[end + 1];
    int i = st, j = mid + 1, k = st;

    // MERGING TWO SORTED ARRAYS
    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j])     temp[k++] = arr[i++];
        else    temp[k++] = arr[j++];
    }
    while(i <= mid)     temp[k++] = arr[i++];
    while(j <= end)     temp[k++] = arr[j++];

    // COPYING ELEMENTS FROM THE temp TO arr
    for(int m = st; m < end + 1; m ++) {
        arr[m] = temp[m];
    }
}

void mergeSort(int arr[], int st, int end) {
    int mid = st + (end - st) / 2;
    if(st < end) {
        mergeSort(arr, st, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, st, mid, end);
    }
}

int main () {
    int arr[] = {5,6,1,9,3,8,4,10,13,22};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++) {
        cout << arr[i] <<" ";
    }

    return 0;
}
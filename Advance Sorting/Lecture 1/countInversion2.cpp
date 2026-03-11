// COUNT INVERSIONS (GLOBAL VARIABLE IS NOT USED)
#include <iostream>

using namespace std;

int inversions(int arr[], int st, int mid, int end) {
    int c = 0;
    int i = st, j = mid + 1;
    while(i <= mid && j <= end) {
        if(arr[i] > arr[j]) {
            c += (mid - i + 1);
            j++;
        }
        else    i++;
    }
    return c;
}

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

int mergeSort(int arr[], int st, int end) {
    int inv_count = 0;

    int mid = st + (end - st) / 2;
    if(st < end) {
        inv_count += mergeSort(arr, st, mid);
        inv_count += mergeSort(arr, mid + 1, end);
        inv_count += inversions(arr, st, mid, end);
        merge(arr, st, mid, end);
    }
    return inv_count;
}

int main () {
    int arr[] = {5,1,8,2,3}; // 5
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << mergeSort(arr, 0, n - 1) << endl;

    for(int i = 0; i < n; i++) {
        cout << arr[i] <<" ";
    }

    return 0;
}
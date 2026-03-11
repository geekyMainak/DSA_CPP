// COUNT INVERSIONS (GLOBAL VARIABLE IS DISCOURAGED FOR A CLEAN CODE)
#include <iostream>

using namespace std;

int count = 0; // GLOBAL VARIABLE

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

void mergeSort(int arr[], int st, int end) {
    int mid = st + (end - st) / 2;
    if(st < end) {
        mergeSort(arr, st, mid);
        mergeSort(arr, mid + 1, end);

        // Count  the inversions
        count += inversions(arr, st, mid, end);

        merge(arr, st, mid, end);
    }
}

int main () {
    int arr[] = {5,1,8,2,3}; // 5
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++) {
        cout << arr[i] <<" ";
    }

    cout << endl <<count;

    return 0;
}
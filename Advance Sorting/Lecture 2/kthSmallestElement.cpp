// Finding Kth Smallest Element. (USING QUICK SELECT ALGORITHM)
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

int quickSort(int arr[], int st, int end, int k) {
    if(st < end) {
        int piv_idx = partition(arr, st, end);
        if( k - 1 == piv_idx)   return arr[piv_idx];
        else if(k - 1 < piv_idx)     quickSort(arr, st, piv_idx - 1, k);
        else    quickSort(arr, piv_idx + 1, end, k);
    }
}

int main () {
    int arr[] = {5,6,1,9,3,8,4,10,13,22};  // 1 3 4 5 6 8 9 10 13 22 
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;

    cout << quickSort(arr, 0, n - 1, k);

    return 0;
}
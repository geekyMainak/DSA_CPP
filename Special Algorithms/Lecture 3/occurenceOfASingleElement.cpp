// Given an array where every elements occurs twice except only one element. Find that element ?
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int findingleUniqueElement(int arr[], int n) {  // T.C. -> O(nlogn)
    sort(arr, arr + n);
    int k = INT_MIN;
    for(int i = 1; i < n; i+=2) {
        if((arr[i - 1] ^ arr[i]) != 0) {
            k = arr[i - 1];
            break;
        }
    }
    return ((k == INT_MIN) ? arr[n - 1] : k);
}

int findingleUniqueElementAlternate(int arr[], int n) {  // T.C. -> O(n)
    int result = 0;
    for(int i = 0; i < n; i++) {
        result ^= arr[i];
    }
    return result;
}

int main () {
    int arr[] = {2,3,2,6,7,3,5,5,7,8,6,9,0,9,0};   
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findingleUniqueElement(arr, n) << endl;    // 8
    cout << findingleUniqueElementAlternate(arr, n);   // 8
    return 0;
}
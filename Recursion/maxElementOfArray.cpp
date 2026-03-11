// MAXIMUM ELEMENT IN AN ARRAY USING RECURSION
#include <iostream>
#include <climits>

using namespace std;

int maxElement( int arr[], int n, int idx) {
    // base case
    if(idx == n)    return INT_MIN; // WE CAN ALSO USE arr[0] instead of INT_MIN
    return max(arr[idx], maxElement(arr, n, idx + 1));
}

int main() {
    int arr[5] = {1,5,8,20,4};
    int k = maxElement(arr, 5, 0);
    cout << k;
    return 0;
}

// MAXIMUM SUM OF SUBARRAY OF SIZE K
#include <iostream>
#include <climits>

using namespace std;

int main() {
    int arr[] = {7,1,2,5,8,4,9,3,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    // int maxSum = INT_MIN;
    // int maxIdx = -1;

    // // METHOD - 1   BRUTE FORCE APPROACH T.C. -> O(n^2)
    // for(int i =0 ; i <= n - k; i++) {
    //     int sum = 0;
    //     for(int j = i; j < i + k; j++) {
    //         sum += arr[j];
    //     }
    //     if(maxSum < sum) {
    //         maxSum = sum;
    //         maxIdx = i;
    //     }
    // }

// METHOD - 2
        int curr_sum = 0;
        int maxIdx = -1;
        for(int i = 0; i < k; i++) {
            curr_sum += arr[i];
        }
        int maxSum = curr_sum;
        int i = 1, j = k;
        while(j < n) {
            curr_sum += arr[j] - arr[i - 1];

            if(maxSum < curr_sum) {
                maxSum = curr_sum;
                maxIdx = i;
            }
          i++;
          j++;
         }

    cout << maxSum <<" at " <<maxIdx;

    return 0;
}

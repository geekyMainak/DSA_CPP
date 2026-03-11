// First Negative Number In Every Window
#include <iostream>

using namespace std;

int main() {
    int arr[] = {2,3,4,4,-7,-1,4,-2,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    int ans[n - k + 1];

    int i = 1, j = k;
    int prev_idx = -1;
    for(int i = 0; i < k - 1; i++) {
        if(arr[i] < 0) {
            prev_idx = i;
            break;
        }
    }
    ans[0] = (prev_idx == -1) ? 0 : arr[prev_idx];
    while(j < n) {
        if(prev_idx >= i)   ans[i] = arr[prev_idx];
        else {
            prev_idx = -1;
            for(int x = i; x <= j; x++) {
                if(arr[x] < 0) {
                    prev_idx = x;
                    break;
                }
            }
            ans[i] =  (prev_idx == -1) ? 0 : arr[prev_idx];
        }
        i++;
        j++;
    }

    for(int i : ans) {
        cout << i <<" ";
    }

    return 0;
}
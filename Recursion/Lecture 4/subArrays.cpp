// SUBARRAYS
#include <iostream>
#include <vector>

using namespace std;

void subArrays(int arr[], int n, vector<int> ans, int idx) {
    // base case
    if(idx == n) {
        for(int i : ans) {
            cout <<"[" << i <<"]" <<" ";
        }
        cout << endl;
        return;
    }

    subArrays(arr, n, ans, idx + 1);  // left
    //if(ans.size() == 0 || ans[ans.size() - 1] == arr[idx - 1]) {   any of the two conditions are correct.
    if(ans.empty() || (idx > 0 && ans.back() == arr[idx - 1])) {   // ans.back() is used to find the last element of the vector
        ans.push_back(arr[idx]);           // right
        subArrays(arr, n, ans, idx + 1);   // right
    }
}

int main() {
    int arr[] = {1,2,3,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v;
    subArrays(arr, n, v, 0);
    return 0;
}

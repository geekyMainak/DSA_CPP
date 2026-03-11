#include <iostream>
#include <vector>
#include <string>

using namespace std;

void combinationSum(vector<int> v, int arr[], int n, int target, int idx) {
    // base case
    if(target == 0) {
        for(int ele : v) {
            cout << ele <<" ";
        }
        cout << endl;
        return;
    }
    if(target < 0)  return;

    for(int i = idx; i < n; i++) {
        v.push_back(arr[i]);
        combinationSum(v, arr, n, target - arr[i], i);
        v.pop_back();
    }

}

int main() {
    int arr[] = {2,3,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v;
    int target = 8;
    combinationSum(v, arr, n, target, 0);

    return 0;
}
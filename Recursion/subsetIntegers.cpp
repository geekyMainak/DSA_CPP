// SUBSET
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void subsetAlternate(int arr[], int n, vector<int> ans,  int idx) {
    // base case
    if(idx == n) {
        for(int ele : ans) {
        cout <<"[" << ele <<"]" <<" ";
        }
        cout << endl;
        return;
    }

    subsetAlternate(arr, n, ans, idx + 1);
    ans.push_back(arr[idx]);
    subsetAlternate(arr, n, ans, idx + 1);

}

int main() {
    int arr[] = {1,2,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans;
    subsetAlternate(arr, n, ans, 0);
    
    return 0;
}

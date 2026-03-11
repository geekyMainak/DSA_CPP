// First Negative In Window Of Size K.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> firstNegativeInWindowOfSizeK(vector<int> v, int k) {
    queue<int> q;
    int n = v.size();
    for(int i = 0; i < v.size(); i++) {
        if(v[i] < 0)    q.push(i);
    }
    vector<int> ans(n-k+1,0);
    for(int i = 0; i < n-k+1; i++) {
        if(!q.empty() && (i <= q.front() && q.front() < i+k))    ans[i] = v[q.front()];
        else {
            if(!q.empty())    q.pop();
            if(!q.empty() && (i <= q.front() && q.front() < i+k))    ans[i] = v[q.front()];
        }
    }
    return ans;
}

vector<int> firstNegativeInWindowOfSizeK_Alternate(vector<int> v, int k) {
    queue<int> q;
    int n = v.size();
    for(int i = 0; i < v.size(); i++) {
        if(v[i] < 0)    q.push(i);
    }
    vector<int> ans(n-k+1,0);
    for(int i = 0; i < n-k+1; i++) {
        // Remove all indices that are outside the current window
        while (!q.empty() && q.front() < i)   q.pop();

        // Check if the front of queue is in the current window
        if (!q.empty() && q.front() < i + k)    ans[i] = v[q.front()];
        else  ans[i] = 0;
    }
    return ans;
}

int main() {
    vector<int> v = {-1, -2, -3, 4, 5, -6, 7, 8};
    vector<int> ans = firstNegativeInWindowOfSizeK_Alternate(v,3);
    for(auto i : ans)   cout << i <<" ";
    cout << endl;
    vector<int> ans1 = firstNegativeInWindowOfSizeK(v,3);
    for(auto i : ans1)   cout << i <<" ";
    return 0;
}


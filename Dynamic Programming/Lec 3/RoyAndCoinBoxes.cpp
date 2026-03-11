// Hacker Earth Problem
// Difference Array Approach
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<int> dp (n+1, 0);

    while(m--) {
        int l,r;
        cin >> l >> r;

        dp[l]++;
        dp[r+1]--;
    }

    for(int i = 2; i < n+1; i++)    dp[i] += dp[i-1];       // Prefix Sum

    int q;
    cin >> q;

    vector<int> freq(n+1, 0);
    for(int i = 1; i < n+1; i++)    freq[dp[i]]++;

    for(int i = n-1; i >= 0; i--)     freq[i] += freq[i+1];     // Suffix Sum
    
    while(q--) {
        int a;
        cin >> a;
        cout << freq[a] << " ";
    }

    return 0;
}

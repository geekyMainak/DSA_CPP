/* Taro and Jiro will play the following game against each other.
Initially, they are given a sequence 
a=(a1 ,a2 ,…,aN). Until a becomes empty, the two players perform the following operation alternately, starting from Taro:
Remove the element at the beginning or the end of 
a. The player earns x points, where x is the removed element.Let X and Y be Taro's and Jiro's total score at the end of the game, respectively. 
Taro tries to maximize X−Y, while Jiro tries to minimize X−Y. Assuming that the two players play optimally, find the resulting value of X−Y. */

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

ll arr[3005];
ll dp[3005][3005];

ll f(int i, int j) {
    // base case
    if(i == j)  return arr[i];
    if(dp[i][j] != -1)     return dp[i][j];

    return dp[i][j] = max(arr[i] - f(i+1, j), arr[j] - f(i, j-1));
}

ll fbu(int n) {
    // base case
    memset(dp, -1, sizeof(dp));
    rep(i, n)   dp[i][i] = arr[i];

    for(int len = 2; len <= n; len++) {
        for(int i = 0; i + len <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = max(arr[i] - dp[i+1][j], arr[j] - dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;      cin >> n;
    rep(i, n)   cin >> arr[i];  

    memset(dp, -1, sizeof(dp));
    cout << f(0, n-1) << "\n";

    cout << fbu(n) << "\n";
    return 0;
}
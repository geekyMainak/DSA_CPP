#include <bits/stdc++.h>
using namespace std;

vector<int> dp(1000001, -1);

const int MOD = 1e9 + 7;

int totalWays(int n) {
    if(n == 0)  return 1;
    if(dp[n] != -1)    return dp[n];

    int ways = 0;
    for(int i = 1; i <= 6; i++) {
        if(n-i < 0)   break;
        ways = (ways + totalWays(n-i)) % MOD;
    }
    return dp[n] = ways;
}

int totalWays_Iterative(int n) {
    dp[0] = 1;

    for(int i = 1; i <= n; i++) {
        dp[i] = 0;
        for(int j = 1; j <= 6; j++) {
            if(i-j < 0)   break;
            dp[i] = (dp[i] + dp[i-j]) % MOD;
        }
    }    
    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << totalWays_Iterative(n) << "\n";
    cout << totalWays(n) << "\n";
    return 0;    
}


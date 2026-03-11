// Problem link :- https://atcoder.jp/contests/dp/tasks/dp_o

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)   for(int i = 1; i <= n; i++)

int n;
static const int MOD = 1e9 + 7;
vector<vector<int>> c;     // Compatibility Matrix
int dp[22][1 << 22];

int f(int i, int mask) {
    // base case
    if(i == n+1) {
        return mask == 0;
    }

    if(dp[i][mask] != -1)   return dp[i][mask];

    int ans = 0;
    for(int w = 1; w <= n; w++) {
        bool available = mask & (((1 << (w-1))));
        if(available && c[i][w]) {
            ans = ((ans % MOD) + (f(i+1, mask ^ (((1 << (w-1)))))) % MOD) % MOD;
        }
    }
    return dp[i][mask] = ans;
}

int main () {
    cin >> n;
    c.resize(n+1, vector<int> (n+1));

    rep(i, n) {
        rep(j, n) {
            cin >> c[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << f(1, (1 << n) - 1) << "\n";

    return 0;
}
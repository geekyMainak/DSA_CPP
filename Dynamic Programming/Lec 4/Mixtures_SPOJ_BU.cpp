//for n > 100
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[105][105];
vector<ll> colors;
ll pref[105]; // prefix sum mod 100

ll g(int i, int j) {
    // Compute sum of colors[i..j] % 100 in O(1)
    return (pref[j+1] - pref[i] + 100) % 100;
}

ll f(int n) {
    for(int len = 2; len <= n; len++) {
        for(int i = 0; i + len <= n; i++) {
            int j = i + len - 1;
            ll result = LLONG_MAX;
            for (int k = i; k < j; k++) {  
                result = min(result, dp[i][k] + dp[k+1][j] + g(i, k) * g(k+1, j));
            }
            dp[i][j] = result;
        }
    }
    return dp[0][n-1];    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, 0, sizeof(dp));

    int n;
    cin >> n;
    colors.resize(n);
    for (int i = 0; i < n; i++) cin >> colors[i];

    // ✅ Precompute prefix sums mod 100
    pref[0] = 0;
    for (int i = 0; i < n; i++) {
        pref[i+1] = (pref[i] + colors[i]) % 100;
    }

    cout << f(n) << "\n";

    return 0;
}
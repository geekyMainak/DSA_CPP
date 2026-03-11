// Problem Link :- https://atcoder.jp/contests/dp/tasks/dp_u

#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 16;

vector<long long> dp(1 << MAXN, -1);
vector<long long> sums(1 << MAXN, 0);

long long calc(vector<vector<int>> &compat, int mask, int n) {
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            for (int j = i + 1; j < n; j++) {
                if (mask & (1 << j)) {
                    ans += compat[i][j];
                }
            }
        }
    }
    return ans;
}

void precompute(vector<vector<int>> &compat, int n) {
    for (int mask = 1; mask < (1 << n); mask++) {
        sums[mask] = calc(compat, mask, n);
    }
}

long long f(int mask) {
    if (mask == 0) return 0;
    if (dp[mask] != -1) return dp[mask];

    long long ans = 0;

    // iterate over all submasks
    for (int g = mask; g > 0; g = (g - 1) & mask) {
        ans = max(ans, sums[g] + f(mask ^ g));
    }

    return dp[mask] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> compat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> compat[i][j];
        }
    }

    precompute(compat, n);

    cout << f((1 << n) - 1) << "\n";
    return 0;
}

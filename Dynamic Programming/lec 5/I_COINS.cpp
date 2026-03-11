// AtCoder Eduacational DP Contest

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,a,b) for(int i=(a); i<(b); ++i) // from a to b-1
using ll = long long;
using P = pair<int,int>;

double dp[3005][3005];

double f(vector<double> &probability, int i, int x) {
    if(x == 0)      return 1;
    if(i == 0)      return 0;
    if(dp[i][x] > -0.9)     return dp[i][x];

    return dp[i][x] = f(probability, i-1, x-1)*probability[i] + f(probability, i-1, x)*(1-probability[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;      cin >> n;
    vector<double> probability(n+1);
    rep1 (i, 1, n+1)      cin >> probability[i];

    memset(dp, -1, sizeof(dp));
    int x = (n + 1) / 2;    // Total number of heads we required
    cout << fixed << setprecision(10) << f(probability, n, x) << "\n";

    return 0;
}
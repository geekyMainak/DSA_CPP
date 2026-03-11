#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,a,b) for(int i=(a); i<(b); ++i) // from a to b-1
using ll = long long;
using P = pair<int,int>;

int dp[105][105][2];

int AdjBC(int n, int k, int last) {
    // Base Cases
    if(n == 0)  return 0;
    if(n == 1) {
        if(k < 0)   return 0;
        if(k == 0)  return 1;
    }
    if(dp[n][k][last] != -1)    return dp[n][k][last];

    if(last == 1)   return dp[n][k][last] = (AdjBC(n-1, k-1, 1) + AdjBC(n-1, k, 0));
    else   return dp[n][k][last] = (AdjBC(n-1, k, 1) + AdjBC(n-1, k, 0));
}

int main() {
    int T;      cin >> T;
    
    while (T--) {
        int a, n, k;
        cin >> a >> n >> k;
        
        memset(dp, -1, sizeof(dp));
        int ans = AdjBC(n, k, 0) + AdjBC(n, k, 1);

        cout << a << " " << ans << "\n";
    }
    return 0;
}

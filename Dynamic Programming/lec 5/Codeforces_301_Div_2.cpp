#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,a,b) for(int i=(a); i<(b); ++i) // from a to b-1
using ll = long long;
using ld = long double;
using P = pair<int,int>;

ld dp[105][105][105];

ld f_p(int r, int s, int p) {
    // base cases
    if(r == 0)  return 0.0;
    if(p == 0)  return 0.0;
    if(s == 0)  return 1.0;
    if(dp[r][s][p] > -0.9)      return dp[r][s][p];

    ld total = r*p + r*s + p*s;
    ld result = 0.0;

    result += f_p(r, s-1, p)*((r*s) / total);
    result += f_p(r-1, s, p)*((r*p) / total);
    result += f_p(r, s, p-1)*((p*s) / total);

    return dp[r][s][p] = result;
}

ld f_s(int r, int s, int p) {
    // base cases
    if(r == 0)  return 1.0;
    if(p == 0)  return 0.0;
    if(s == 0)  return 0.0;
    if(dp[r][s][p] > -0.9)      return dp[r][s][p];

    ld total = r*p + r*s + p*s;
    ld result = 0.0;

    result += f_s(r, s-1, p)*((r*s) / total);
    result += f_s(r-1, s, p)*((r*p) / total);
    result += f_s(r, s, p-1)*((p*s) / total);

    return dp[r][s][p] = result;
}

ld f_r(int r, int s, int p) {
    // base cases
    if(r == 0)  return 0.0;
    if(p == 0)  return 1.0;
    if(s == 0)  return 0.0;
    if(dp[r][s][p] > -0.9)      return dp[r][s][p];

    ld total = r*p + r*s + p*s;
    ld result = 0.0;

    result += f_r(r, s-1, p)*((r*s) / total);
    result += f_r(r-1, s, p)*((r*p) / total);
    result += f_r(r, s, p-1)*((p*s) / total);

    return dp[r][s][p] = result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, s, p;
    cin >> r >> s >> p;

    memset(dp, -1.0, sizeof(dp));
    cout << fixed << setprecision(12) << f_r(r, s, p) << "\n";

    memset(dp, -1.0, sizeof(dp));
    cout << fixed << setprecision(12) << f_s(r, s, p) << "\n";

    memset(dp, -1.0, sizeof(dp));
    cout << fixed << setprecision(12) << f_p(r, s, p) << "\n";

    return 0;
}
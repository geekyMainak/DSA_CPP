// Problem Link :-  https://codeforces.com/problemset/problem/1743/A
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,a,b) for(int i=(a); i<(b); ++i) // from a to b-1
using ll = long long;
using P = pair<int,int>;

ll nCr(ll n, ll r) {
    r = min(r, n-r);
    ll res = 1;
    for(int i = 1; i <= r; i++)     res = (res * (n - i + 1)) / i;

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        int x;
        rep(i, n)   cin >> x;

        cout << nCr(10 - n, 2) * 6 << "\n";
    }

    return 0;
}
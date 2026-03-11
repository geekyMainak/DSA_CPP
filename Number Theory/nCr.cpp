#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,a,b) for(int i=(a); i<(b); ++i) // from a to b-1
using ll = long long;
using P = pair<int,int>;

ll nCr(ll n, ll r) {
    r = min(r, n - r);
    ll res = 1;
    for (ll i = 1; i <= r; i++) {
        res = (res * (n - i + 1)) / i;
    }
    return (ll)res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << nCr(5, 2) << "\n";

    return 0;
}
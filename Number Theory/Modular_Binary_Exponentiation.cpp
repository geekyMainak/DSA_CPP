// Modular Binary Exponentiation  (Time Complexity :  O(log b))

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,a,b) for(int i=(a); i<(b); ++i) // from a to b-1
using ll = long long;
using P = pair<int,int>;

ll binexp(ll a, ll b, ll mod) {
    a %= mod;
    ll res = 1;

    while(b > 0) {
        if(b & 1)   res = (res * a) % mod;       // if b is odd

        a = (a * a) % mod;      // square base
        b >>= 1;                // b = b / 2
    }
    return res;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a = 3;
    ll b = 6;
    ll mod = 1e9 + 7;
    cout << binexp(a, b, mod);

    return 0;
}
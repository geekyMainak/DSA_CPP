// Problem Link :-  https://codeforces.com/problemset/problem/913/A
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,a,b) for(int i=(a); i<(b); ++i) // from a to b-1
using ll = long long;
using P = pair<int,int>;

ll binexp(ll a, ll b) {
    ll res = 1;
    while(b > 0) {
        if(b & 1)   res *= a;

        a *= a;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,n;
    cin >> n >> m;
    
    if(n > m || n > 30)   cout << m << "\n";
    else    cout << m % binexp(2, n) << "\n";

    return 0;
}
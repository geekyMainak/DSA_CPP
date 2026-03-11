// Problem Link :-  https://codeforces.com/problemset/problem/1374/A
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,a,b) for(int i=(a); i<(b); ++i) // from a to b-1
using ll = long long;
using P = pair<int,int>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        ll x,y,n;
        cin >> x >> y >> n;

        int q = n / x;
        ll c = (q * x) + y;
        if(c > n)      c = 1;
        cout << max(((q-1) * x) + y, c) << "\n";
    }
    return 0;
}
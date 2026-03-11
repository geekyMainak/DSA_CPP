// Problem Link :- https://codeforces.com/problemset/problem/1740/A
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
        int n;
        cin >> n;

        if(n == 2 || n == 3)      cout << 7 << "\n";
        else {
            cout << 3 << "\n";
        }
    }

    return 0;
}

 
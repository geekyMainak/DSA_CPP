// Problem Link :- https://codeforces.com/problemset/problem/1861/A
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
        string str;
        cin >> str;

        for(int i = 0; i < 9; i++) {
            if(str[i] == '1') {
                cout << 13 << "\n";
                break;
            } else if(str[i] == '3') {
                cout << 31 << "\n";
                break;
            }
        }
    }

    return 0;
}

 
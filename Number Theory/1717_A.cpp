// Problem Link :-  https://codeforces.com/problemset/problem/1717/A
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,a,b) for(int i=(a); i<(b); ++i) // from a to b-1
using ll = long long;
using P = pair<int,int>;

/* gcd(a, b) can have 3 values i.e. 1, 2 and 3. Therefore,
    case 1:-  gcd(a, b) = 1
            lcm(a, b) = gcd(a, b)  it is possible when a = b   Therefore, n pairs
    case 2:- gcd(a, b) = 2
            lcm(a, b) = 2 * gcd(a, b) it is possible when a = 2b   Therefore, (n/2) * 2 pairs 
    case 3:- gcd(a, b) = 3
            lcm(a, b) = 3 * gcd(a, b) it is possible when a = 3b   Therefore, (n/3) * 2 pairs */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;
        cout << n + (n/2)*2 + (n/3)*2 << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,a,b) for(int i=(a); i<(b); ++i) // from a to b-1
using ll = long long;
using P = pair<int,int>;

// Time Complexity : O(log min(a, b))
ll gcd(ll a, ll b) {
    return (a == 0) ? b : gcd(b % a, a);
}


// Time Complexity : O(log min(a, b))
ll gcd_Iterative(ll a, ll b) {
    while (a != 0) {
        ll r = b % a;
        b = a;
        a = r;
    }
    return b;
}

ll lcm(ll a, ll b) {
    return (a * b) / __gcd(a, b);     // Using STL to find GCD of a and b
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << gcd(16, 26) << "\n";
    return 0;
}
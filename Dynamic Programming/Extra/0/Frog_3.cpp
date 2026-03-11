#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,a,b) for(int i=(a); i<(b); ++i)
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define nl '\n'

using ll = long long;
using P = pair<int,int>;

const int mxn = 200005;

struct line {
    ll m, c;
    line(ll a, ll b) {
        m = a;
        c = b;
    }
};

struct CHT {
    vector<line> v;

    void init() {
        v.clear();
    }

    // l2 is useless
    bool bad(line l1, line l2, line l3) {
        long double a = (long double)(l2.c - l1.c) * (l2.m - l3.m);
        long double b = (long double)(l3.c - l2.c) * (l1.m - l2.m);
        return a >= b;
    }

    void add(line a) {
        v.push_back(a);
        int sz = v.size();
        while (sz >= 3 && bad(v[sz - 3], v[sz - 2], v[sz - 1])) {
            v.erase(v.end() - 2);
            sz--;
        }
    }

    inline ll val(int ind, ll x) {
        return v[ind].m * x + v[ind].c;
    }

    // ternary search (minimum)
    ll query(ll x) {
        int l = 0, r = (int)v.size() - 1;
        ll ans = LLONG_MAX;

        while (l <= r) {
            int mid1 = l + (r - l) / 3;
            int mid2 = r - (r - l) / 3;

            ll v1 = val(mid1, x);
            ll v2 = val(mid2, x);

            if (v1 <= v2) {
                ans = min(ans, v1);
                r = mid2 - 1;
            } else {
                ans = min(ans, v2);
                l = mid1 + 1;
            }
        }
        return ans;
    }
};

ll n, c, h[mxn], dp[mxn];

int main() {
    fastio;

    cin >> n >> c;
    for (int i = 1; i <= n; i++) cin >> h[i];

    CHT C;
    dp[1] = 0;

    C.add({-2 * h[1], h[1] * h[1] + dp[1]});

    for (int i = 2; i <= n; i++) {
        dp[i] = c + h[i] * h[i] + C.query(h[i]);
        C.add({-2 * h[i], h[i] * h[i] + dp[i]});
    }

    cout << dp[n] << nl;
    return 0;
}

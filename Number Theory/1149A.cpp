// Problem Link :- https://codeforces.com/problemset/problem/1149/A
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,a,b) for(int i=(a); i<(b); ++i) // from a to b-1
using ll = long long;
using P = pair<int,int>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt1 = 0;
    int cnt2 = 0;

    int n;
    cin >> n;

    while(n--) {
        int x;
        cin >> x;
        if(x == 1)      cnt1++;
        else     cnt2++;
    }

    vector<int> ans;
    if(cnt2) {
        ans.push_back(2);
        cnt2--;
    }
    if(cnt1) {
        ans.push_back(1);
        cnt1--;
    }
    while(cnt2) {
        ans.push_back(2);
        cnt2--;
    }
    while(cnt1) {
        ans.push_back(1);
        cnt1--;
    }

    for(auto ele : ans)     cout << ele << " ";

    return 0;
}
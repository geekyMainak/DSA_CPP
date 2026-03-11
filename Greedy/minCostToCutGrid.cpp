// Minimum cost to cut the grid
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int

using namespace std;

ll minCostToBreakGrid(int n ,int m, vector<ll> &vertical, vector<ll> &horizontal) {
    sort(begin(horizontal), end(horizontal), greater<int>());
    sort(begin(vertical), end(vertical), greater<int>());

    int h_blocks = 1, v_blocks = 1;
    int h = 0, v = 0;
    ll ans = 0;

    while(h < horizontal.size() && v < vertical.size()) {
        if(vertical[v] > horizontal[h]) {
            ans += vertical[v++] * v_blocks;
            h_blocks++;
        } else {
            ans += horizontal[h++] * h_blocks;
            v_blocks++;
        }
    }
    while(h < horizontal.size()) {
        ans += horizontal[h++] * h_blocks;
        v_blocks++;
    }
    while(v < vertical.size()) {
        ans += vertical[v++] * v_blocks;
        h_blocks++;
    }
    return ans;
}

int main () {
    vector<ll> vertical = {2,1,3,1,4};
    vector<ll> horizontal = {4,1,2};
    int m = 6, n = 4;

    cout << minCostToBreakGrid(n , m, horizontal, vertical) << endl;

    return 0;
}
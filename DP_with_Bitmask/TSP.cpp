#include <bits/stdc++.h>
using namespace std;

int n = 4;
int grid[4][4] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}
};

int dp[10][1 << 10];

// T.C. :- O(n^2 * 2^n)
int tsp(int curr, int mask) {
    // base case
    if(mask == ((1 << n) - 1))      return grid[curr][0];

    if(dp[curr][mask] != -1)    return dp[curr][mask];

    int ans = INT_MAX;
    for(int nbr = 0; nbr < n; nbr++) {
        if((mask & (1 << nbr)) == 0) {      // neighbour is unvisited
            ans = min(ans, grid[curr][nbr] + tsp(nbr, mask | (1 << nbr)));
        }
    }
    return dp[curr][mask] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));

    cout << tsp(0, 1) << "\n";

    return 0;
}
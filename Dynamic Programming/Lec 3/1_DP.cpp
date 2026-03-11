/* You are given an integer n. On each step, you may subtract one of the digits from the number.
How many steps are required to make the number equal to 0?
Input
The only input line has an integer n.
Output
Print one integer: the minimum number of steps. */

// DP Solution
#include <bits/stdc++.h>
using namespace std;

vector<int> getDigits(int n) {
    vector<int> digits;
    while (n > 0) {
        int d = n % 10;
        if (d != 0) digits.push_back(d);
        n /= 10;
    }
    return digits;
}

int dp[1000001]; 

int f(int n) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];

    int ans = INT_MAX;
    for (int d : getDigits(n)) {
        ans = min(ans, 1 + f(n - d));
    }
    return dp[n] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));
    cout << f(n) << "\n";

    return 0;
}

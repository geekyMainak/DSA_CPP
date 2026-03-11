/* Find the minimum number of operations so that n (a given number) becomes 1 ?
1) Reduce n to n-1
2) if(n % 2 == 0)   n /= 2
3) if(n % 3 == 0)   n /= 3 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> dp;

int minSteps(int n) {
    if(n == 1)  return 0;
    if(n == 2 || n == 3)    return 1;

    if(dp[n] != -1)     return dp[n];

    int pro1 = (n % 2 == 0) ? minSteps(n/2) : INT_MAX;
    int pro2 = (n % 3 == 0) ? minSteps(n/3) : INT_MAX;
    int pro3 = minSteps(n-1);

    return dp[n] = 1 + min(pro1, min(pro2, pro3));
}

int iterativeSol(int n) {
    vector<int> dp(n+1, INT_MAX);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for(int i = 4; i <= n; i++) {
        int pro1 = (i % 2 == 0) ? dp[i/2] : INT_MAX;
        int pro2 = (i % 3 == 0) ? dp[i/3] : INT_MAX;
        int pro3 = dp[i-1];
        dp[i] = 1 + min(pro1, min(pro2, pro3));
    }
    return dp[n];
}

int main () {
    int n;
    cin >> n;

    dp.clear();
    dp.resize(n+1, -1);

    cout << minSteps(n) << endl;
    cout << iterativeSol(n) << endl;

    return 0;
}

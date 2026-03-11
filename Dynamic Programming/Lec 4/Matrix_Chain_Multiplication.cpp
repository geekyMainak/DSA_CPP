#include <cstdlib>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int>> dp;

int f(int i, int j, vector<int> arr) {
    if(i == j || i+1 == j)      return 0;
    if(dp[i][j] != -1)     return dp[i][j];

    int ans = INT_MAX;
    for(int k = i+1; k < j; k++) {
        ans = min(ans, f(i,k,arr) + f(k,j,arr) + arr[i]*arr[j]*arr[k]);
    }
    return dp[i][j] = ans;
}

int main() {
    int result = system("start image.png");  // open PNG file  question  

    if (result != 0)    cout << "Failed to open image.\n";
    else    cout << "PNG image opened successfully!\n";\

    dp.assign(1005, vector<int>(1000, -1));
    int n;  cin >> n;
    vector<int> v(5);
    for(int i = 0; i < n; i++)  cin >> v[i];
    
    cout << f(0, n-1, v) << "\n";


    // dp[i][j] = minimum cost to multiply matrices from i to j
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // chain length starts from 2 (i.e., at least 2 matrices)
    for (int len = 2; len < n; len++) {
        for (int i = 0; i + len < n; i++) {
            int j = i + len;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++) {
            // Calculate total cost if the last multiplication is split at 'k'
            // Cost = cost of left part + cost of right part + cost of multiplying them together
                dp[i][j] = min(
                    dp[i][j],
                    dp[i][k] + dp[k][j] + arr[i] * arr[j] * arr[k]
                );
            }
        }
    }

    cout << dp[0][n - 1] << "\n";

    return 0;
}
 
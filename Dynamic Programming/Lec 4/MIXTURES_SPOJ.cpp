// /* Harry Potter has n mixtures in front of him, arranged in a row. Each mixture has one of 100 different colors (colors have numbers from 0 to 99).
// He wants to mix all these mixtures together. At each step, he is going to take two mixtures that stand next to each other and mix them together, and put the resulting mixture in their place.
// When mixing two mixtures of colors a and b, the resulting mixture will have the color (a+b) mod 100.
// Also, there will be some smoke in the process. The amount of smoke generated when mixing two mixtures of colors a and b is a × b.
// Find out what is the minimum amount of smoke that Harry can get when mixing all the mixtures together.

// Input
// There will be a number of test cases in the input.
// The first line of each test case will contain n, the number of mixtures, 1 ≤ n ≤ 100.
// The second line will contain n integers between 0 and 99 - the initial colors of the mixtures.

// Output
// For each test case, output the minimum amount of smoke. */

// for n <= 100
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll dp[105][105];
vector<ll> colors;

ll g(int i, int j) {
    ll result = 0;
    for(int k = i; k <= j; k++)     result = (result % 100 + colors[k] % 100) % 100;

    return result;
}

ll f(int i, int j) {
    if(i == j)  return 0;
    if(dp[i][j] != -1)      return dp[i][j];

    ll result = LLONG_MAX;
    for(int k = i; k < j; k++) {
        result = min(result, f(i, k) + f(k+1, j) + g(i, k) * g(k+1, j));
    }
    return dp[i][j] = result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    int n;      cin >> n;
    colors.resize(n);
    for(int i = 0; i < n; i++)     cin >> colors[i];

    cout << f(0, n-1) << "\n";

    return 0;
}


//for n > 100
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[105][105];
vector<ll> colors;
ll pref[105]; // prefix sum mod 100

ll g(int i, int j) {
    // Compute sum of colors[i..j] % 100 in O(1)
    return (pref[j+1] - pref[i] + 100) % 100;
}

ll f(int i, int j) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    ll result = LLONG_MAX;
    for (int k = i; k < j; k++) {  // ✅ FIXED: k < j
        result = min(result, f(i, k) + f(k+1, j) + g(i, k) * g(k+1, j));
    }
    return dp[i][j] = result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    int n;
    cin >> n;
    colors.resize(n);
    for (int i = 0; i < n; i++) cin >> colors[i];

    // ✅ Precompute prefix sums mod 100
    pref[0] = 0;
    for (int i = 0; i < n; i++) {
        pref[i+1] = (pref[i] + colors[i]) % 100;
    }

    cout << f(0, n-1) << "\n";

    return 0;
}


// For the submission in SPOJ
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll dp[105][105];
vector<ll> colors;

ll g(int i, int j) {
    ll result = 0;
    for (int k = i; k <= j; k++) 
        result = (result + colors[k]) % 100;
    return result;
}

ll f(int i, int j) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    ll result = LLONG_MAX;
    for (int k = i; k < j; k++) {   
        result = min(result, f(i, k) + f(k + 1, j) + g(i, k) * g(k + 1, j));
    }
    return dp[i][j] = result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        colors.resize(n);
        for (int i = 0; i < n; i++) cin >> colors[i];

        memset(dp, -1, sizeof(dp));  
        cout << f(0, n - 1) << "\n"; 
    }

    return 0;
}


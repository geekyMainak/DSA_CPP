/* Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.

The vacation consists of N days. 
For each i (1≤i≤N), Taro will choose one of the following activities and do it on the i-th day:

A: Swim in the sea. Gain ai points of happiness.
B: Catch bugs in the mountains. Gain bi points of happiness.
C: Do homework at home. Gain ci points of happiness.
As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

Find the maximum possible total points of happiness that Taro gains. */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> dp(n, vector<int> (3, 0));
    
    // base cases
    int a, b, c;
    cin >> a >> b >> c;     // a -> 0 , b -> 1 ,  c -> 2

    dp[0][0] = a;
    dp[0][1] = b;
    dp[0][2] = c;

    for(int i = 1; i < n; i++) {
        // input of happiness for ith day
        cin >> a >> b >> c;

        dp[i][0] = a + max(dp[i-1][1], dp[i-1][2]);     // if in ith day activity a is done
        dp[i][1] = b + max(dp[i-1][0], dp[i-1][2]);     // if in ith day activity b is done
        dp[i][2] = c + max(dp[i-1][0], dp[i-1][1]);     // if in ith day activity c is done
    }

    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});

    return 0;    
}


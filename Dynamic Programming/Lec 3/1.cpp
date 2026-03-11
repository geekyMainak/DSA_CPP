/* You are given an integer n. On each step, you may subtract one of the digits from the number.
How many steps are required to make the number equal to 0?
Input
The only input line has an integer n.
Output
Print one integer: the minimum number of steps. */

// Greedy Solution
#include <bits/stdc++.h>
using namespace std;

int maxDigit(int n) {
    int maxDig = -1;
    while(n) {
        int last = n % 10;
        maxDig = max(maxDig, last);
        n /= 10;
    }
    return maxDig;
}

int main () {
    int n;
    cin >> n;

    int minSteps = 0;

    while(n) {
        int maxDig = maxDigit(n);
        n -= maxDig;
        minSteps++;
    }

    cout << minSteps << "\n";
    return 0;
}


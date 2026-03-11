#include <bits/stdc++.h>
using namespace std;

// ------------------ Global for Recursive + Memoized version ------------------
int dp_rec[1000][1000];  // Renamed from dp to dp_rec
vector<int> weights, values;
int n, W;

// ------------------ Recursive + Memoization ------------------
int knapsack(int i, int w) {
    if (i == n || w == 0)
        return 0;
    if (dp_rec[i][w] != -1)
        return dp_rec[i][w];

    int include = 0;
    if (weights[i] <= w)
        include = values[i] + knapsack(i + 1, w - weights[i]);

    int exclude = knapsack(i + 1, w);

    return dp_rec[i][w] = max(include, exclude);
}

// ------------------ Bottom-Up (2D Rolling Array / O(2W)) ------------------
int knapsack_1() {
    vector<int> prev(W + 1, 0), curr(W + 1, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int w = 0; w <= W; w++) {
            int include = 0;
            if (weights[i] <= w)
                include = values[i] + prev[w - weights[i]];
            int exclude = prev[w];
            curr[w] = max(include, exclude);
        }
        prev = curr; // move up one level
    }
    return prev[W];
}

// ------------------ Bottom-Up (1D Optimized / O(W)) ------------------
int knapsack_2() {
    vector<int> dp_iter(W + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weights[i]; w--) {
            dp_iter[w] = max(dp_iter[w], values[i] + dp_iter[w - weights[i]]);
        }
    }
    return dp_iter[W];
}

// ------------------ Print Selected Items (for dp_rec version only) ------------------
void findSelectedItems() {
    int w = W;
    cout << "Selected items (index starting from 0): ";
    for (int i = 0; i < n - 1; i++) {
        if (dp_rec[i][w] != dp_rec[i + 1][w]) {
            cout << i << " ";
            w -= weights[i];
        }
    }
    cout << endl;
}

// ------------------ main() ------------------
int main() {
    memset(dp_rec, -1, sizeof(dp_rec));

    cout << "Enter number of items: ";
    cin >> n;
    weights.resize(n);
    values.resize(n);

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; ++i) cin >> weights[i];

    cout << "Enter values of items: ";
    for (int i = 0; i < n; ++i) cin >> values[i];

    cout << "Enter maximum weight capacity of knapsack: ";
    cin >> W;

    cout << "\n--- Running All Versions ---\n";

    // Recursive + Memoization
    int maxValue1 = knapsack(0, W);
    cout << "\n1️⃣ Recursive + Memoization Result = " << maxValue1 << endl;
    findSelectedItems();

    // Iterative (2 arrays)
    int maxValue2 = knapsack_1();
    cout << "\n2️⃣ Iterative (2 arrays) Result     = " << maxValue2 << endl;

    // Iterative (1 array)
    int maxValue3 = knapsack_2();
    cout << "\n3️⃣ Iterative (1 array optimized) Result = " << maxValue3 << endl;

    // Verification
    if (maxValue1 == maxValue2 && maxValue2 == maxValue3)
        cout << "\n✅ All versions give the SAME answer.\n";
    else
        cout << "\n❌ Mismatch detected! Check implementation.\n";

    return 0;
}

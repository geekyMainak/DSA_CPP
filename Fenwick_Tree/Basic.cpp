// Point Update + Prefix Sum

#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    vector<int> bit;
    int n;

public:
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);   // 1-based indexing
    }

    // Add value 'val' at index 'idx'
    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }

    // Prefix sum from 1 to idx
    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }

    // Range sum [l, r]
    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    int n = 5;
    FenwickTree ft(n);

    vector<int> arr = {0, 1, 2, 3, 4, 5}; // dummy 0 index

    // Build Fenwick Tree
    for (int i = 1; i <= n; i++) {
        ft.update(i, arr[i]);
    }

    cout << "Prefix sum up to index 3: " << ft.query(3) << "\n";
    cout << "Range sum [2, 5]: " << ft.rangeQuery(2, 5) << "\n";

    // Update index 3 by +5
    ft.update(3, 5);
    cout << "After update, prefix sum up to index 3: "
         << ft.query(3) << "\n";

    return 0;
}

// Inversion Count Using Fenwick Tree (Count pairs (i,j) where i<j and a[i]>a[j])

#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    // add v at index i
    void update(int i, long long v) {
        for (; i <= n; i += i & -i)
            bit[i] += v;
    }

    // sum from 1 to i
    long long query(int i) {
        long long s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }
};

long long inversionCount(vector<int>& a) {
    int n = a.size();

    // 1) Coordinate Compression
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    Fenwick ft(b.size());
    long long inv = 0;

    // 2) Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        inv += ft.query(pos - 1);  // count smaller elements
        ft.update(pos, 1);         // insert current element
    }

    return inv;
}

int main() {
    vector<int> a = {8, 4, 2, 1};
    cout << inversionCount(a) << "\n"; // Output: 6
    return 0;
}



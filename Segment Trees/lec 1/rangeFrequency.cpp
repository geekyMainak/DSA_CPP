#include <bits/stdc++.h>
using namespace std;

class RangeFreqQuery {
public:
    int n;
    vector<int> nums;
    vector<unordered_map<int,int>> st;

    unordered_map<int, int> addMaps(unordered_map<int, int> mp1, unordered_map<int, int> mp2) {
        for (auto &p : mp2) {
            int ele = p.first;
            int freq = p.second;
            mp1[ele] += freq;
        }
        return mp1;
    }

    void buildTree(vector<int>& arr, int i, int low, int high) {
        if (low == high) {
            st[i][arr[low]] = 1;
            return;
        }

        int mid = low + (high - low) / 2;
        buildTree(arr, 2*i + 1, low, mid);
        buildTree(arr, 2*i + 2, mid + 1, high);

        st[i] = addMaps(st[2*i + 1], st[2*i + 2]);
    }

    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        nums = arr;
        st.resize(4 * n);
        buildTree(arr, 0, 0, n - 1);
    }

    int getCount(int i, int low, int high,
                 int l, int r, int val) {
        if (l > high || r < low)
            return 0;

        if (l <= low && high <= r)
            return st[i][val];

        int mid = low + (high - low) / 2;
        return getCount(2*i + 1, low, mid, l, r, val) +
               getCount(2*i + 2, mid + 1, high, l, r, val);
    }

    int query(int left, int right, int value) {
        return getCount(0, 0, n - 1, left, right, value);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    RangeFreqQuery rfq(arr);

    int q;
    cin >> q;
    while (q--) {
        int l, r, val;
        cin >> l >> r >> val;
        cout << rfq.query(l, r, val) << "\n";
    }

    return 0;
}

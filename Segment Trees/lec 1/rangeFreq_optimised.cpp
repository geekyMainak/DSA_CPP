#include <bits/stdc++.h>
using namespace std;

class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> pos;

    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            pos[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        if (!pos.count(value)) return 0;

        auto &v = pos[value];

        // first index >= left
        int l = lower_bound(v.begin(), v.end(), left) - v.begin();
        // first index > right
        int r = upper_bound(v.begin(), v.end(), right) - v.begin();

        return r - l;
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

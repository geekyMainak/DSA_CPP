#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> st;
    int n;

    void buildTree(vector<int>& nums, int i, int low, int high) {
        // base case
        if (low == high) {
            st[i] = nums[low];
            return;
        }

        int mid = low + (high - low) / 2;
        buildTree(nums, 2*i + 1, low, mid);
        buildTree(nums, 2*i + 2, mid + 1, high);

        st[i] = st[2*i + 1] + st[2*i + 2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        st.resize(4 * n);
        if (n > 0)
            buildTree(nums, 0, 0, n - 1);
    }

    void getUpdated(int i, int low, int high, int &val, int &idx) {
        if (low == high) {
            st[i] = val;
            return;
        }

        int mid = low + (high - low) / 2;
        if (idx <= mid)
            getUpdated(2*i + 1, low, mid, val, idx);
        else
            getUpdated(2*i + 2, mid + 1, high, val, idx);

        st[i] = st[2*i + 1] + st[2*i + 2];
    }

    void update(int index, int val) {
        if (n == 0) return;
        getUpdated(0, 0, n - 1, val, index);
    }

    int getSum(int i, int low, int high, int l, int r) {
        if (low > r || high < l)
            return 0;

        if (l <= low && high <= r)
            return st[i];

        int mid = low + (high - low) / 2;
        return getSum(2*i + 1, low, mid, l, r) +
               getSum(2*i + 2, mid + 1, high, l, r);
    }

    int sumRange(int left, int right) {
        if (n == 0) return 0;
        return getSum(0, 0, n - 1, left, right);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    NumArray obj(nums);

    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            // update
            int idx, val;
            cin >> idx >> val;
            obj.update(idx, val);
        } else if (type == 2) {
            // sumRange
            int l, r;
            cin >> l >> r;
            cout << obj.sumRange(l, r) << "\n";
        }
    }

    return 0;
}

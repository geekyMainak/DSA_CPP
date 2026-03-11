// Lower Bound on Prefix Sum  (Find smallest index where prefix sum ≥ K)

int findKth(long long k) {
    int pos = 0;
    for (int i = 20; i >= 0; i--) {
        if (pos + (1<<i) <= n && bit[pos + (1<<i)] < k) {
            k -= bit[pos + (1<<i)];
            pos += (1<<i);
        }
    }
    return pos + 1;
}



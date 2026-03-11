// Range Update + Range Query (Most Important Uses TWO Fenwick Trees)


struct Fenwick {
    int n;
    vector<long long> B1, B2;

    Fenwick(int n) : n(n), B1(n+1,0), B2(n+1,0) {}

    void update(vector<long long>& B, int i, long long v) {
        while (i <= n) {
            B[i] += v;
            i += i & -i;
        }
    }

    long long query(vector<long long>& B, int i) {
        long long s = 0;
        while (i > 0) {
            s += B[i];
            i -= i & -i;
        }
        return s;
    }

    void rangeAdd(int l, int r, long long v) {
        update(B1, l, v);
        update(B1, r+1, -v);
        update(B2, l, v*(l-1));
        update(B2, r+1, -v*r);
    }

    long long prefixSum(int x) {
        return x * query(B1, x) - query(B2, x);
    }

    long long rangeSum(int l, int r) {
        return prefixSum(r) - prefixSum(l-1);
    }
};

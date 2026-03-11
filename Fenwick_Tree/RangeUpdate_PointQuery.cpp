// Range Update + Point Query  (KEY IDEA :-  Use difference array idea)

struct Fenwick {
    int n;
    vector<long long> bit;

    Fenwick(int n) : n(n), bit(n+1, 0) {}

    void update(int i, long long v) {
        while (i <= n) {
            bit[i] += v;
            i += i & -i;
        }
    }

    void rangeAdd(int l, int r, long long v) {
        update(l, v);
        update(r + 1, -v);
    }

    long long pointQuery(int i) {
        long long s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
};

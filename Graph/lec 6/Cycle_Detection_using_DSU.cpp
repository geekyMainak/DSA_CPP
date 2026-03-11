#include <bits/stdc++.h>
using namespace std;

// T.C. = O(log * n)
int find(vector<int> &parent, int x) {
    if(parent[x] == x)      return x;
    return parent[x] = find(parent, parent[x]);
}

// T.C. = O(log * n)
bool Union(vector<int> &parent, vector<int> &rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);

    if(a == b)  return true;

    if(rank[a] >= rank[b]) {
        rank[a]++;
        parent[b] = a;
    } else {
        rank[b]++;
        parent[a] = b;
    }
    
    return false;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;   // n -> elements and m -> edges  graph in edgelist
    cin >> n >> m;
    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);

    for(int i = 0; i <= n; i++)     parent[i] = i;

    bool flag = false;
    while(m--) {
        int x, y;
        cin >> x >> y;
        flag |= Union(parent, rank, x, y);
    }

    if(flag)    cout << "Cycle Detected\n";
    else    cout << "No Cycle Detected\n";

    return 0;
}
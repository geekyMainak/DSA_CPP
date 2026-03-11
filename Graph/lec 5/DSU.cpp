#include <bits/stdc++.h>
using namespace std;

// T.C. = O(log * n)
int find(vector<int> &parent, int x) {
    if(parent[x] == x)      return x;
    return parent[x] = find(parent, parent[x]);
}

// T.C. = O(log * n)
void Union(vector<int> &parent, vector<int> &rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);

    if(a == b)  return;

    if(rank[a] >= rank[b]) {
        rank[a]++;
        parent[b] = a;
    } else {
        rank[b]++;
        parent[a] = b;
    }
}

int main () {
    int n, m;   // n -> elements and m -> queries
    cin >> n >> m;
    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);

    for(int i = 0; i <= n; i++)     parent[i] = i;

    while(m--) {
        string s;
        cin >> s;

        if(s == "union") {
            int x, y;
            cin >> x >> y;
            Union(parent, rank, x, y);
        } else {
            int x;
            cin >> x;
            cout << find(parent, x) << "\n"; 
        }
    }

    return 0;
}
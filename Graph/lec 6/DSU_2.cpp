#include <bits\stdc++.h>
using namespace std;

int find(vector<int> &parent, int x) {
    if(parent[x] == x)      return x;
    return  parent[x] = find(parent, parent[x]);
}

void Union(vector<int> &parent, vector<int> &size, vector<int> &minimal, vector<int> &maximal, vector<int> &rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);

    if(a == b)  return;

    if(rank[a] >= rank[b]) {
        rank[a]++;
        parent[b] = a;
        size[a] += size[b];
        maximal[a] = max(maximal[a], maximal[b]);
        minimal[a] = min(minimal[a], minimal[b]);
    } else {
        rank[b]++;
        parent[a] = b;
        size[b] += size[a];
        maximal[b] = max(maximal[a], maximal[b]);
        minimal[b] = min(minimal[a], minimal[b]);
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);

    vector<int> size(n+1, 1);
    vector<int> minimal(n+1);
    vector<int> maximal(n+1);

    for(int i = 0; i <= n; i++)     parent[i] = minimal[i] = maximal[i] = i;

    while(m--) {
        string s;
        cin >> s;

        if(s == "union") {
            int u, v;
            cin >> u >> v;
           Union(parent, size, minimal, maximal, rank, u, v);
        } else if(s == "get") {
            int v;
            cin >> v;
            v = find(parent, v);
            cout << minimal[v] << " " << maximal[v] << " " << size[v] << "\n";
        }
    }

    return 0;
}
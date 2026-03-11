#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,a,b) for(int i=(a); i<(b); ++i) // from a to b-1
using ll = long long;
using P = pair<int,int>;


// DSU for cycle Detection
int find(vector<int> &parent, int x) {
    return      parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
}

void Union(vector<int> &parent, vector<int> &rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);

    if(a == b)      return;

    if(rank[a] >= rank[b]) {
        parent[b] = a;
        rank[a]++;
    } else {
        parent[a] = b;
        rank[b]++;
    }
}


void kruskal(vector<tuple<int, int, int>> &graph, int v) {
    // Sort the graph w.r.t. its weight
    sort(graph.begin(), graph.end(), [](auto &A, auto &B) {   return get<2>(A) < get<2>(B);   });

    vector<int> parent(v), rank(v, 0);
    rep(i,v)     parent[i] = i;

    int mstCost = 0;
    vector<tuple<int,int,int>> mstEdges;

    for(auto &e : graph) {
        int x, y, w;
        tie(x, y, w) = e;

        if(find(parent, x) != find(parent, y)) {
            Union(parent, rank, x, y);
            mstCost += w;
            mstEdges.push_back(e);
        }
    }

    cout << "MST Cost = " << mstCost << "\n";
    cout << "Edges in MST:\n";

    for (auto &e : mstEdges) {
        int u, v, w;
        tie(u, v, w) = e;
        cout << u << " -- " << v << "  weight = " << w << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int e, v;
    cin >> v >> e;

    vector<tuple<int, int, int>> graph;

    for(int i = 0; i < e; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        
        graph.push_back({x, y, w});
    }

    kruskal(graph, v);

    return 0;
}

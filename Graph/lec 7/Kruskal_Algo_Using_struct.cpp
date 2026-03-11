#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;    // endpoints and weight
};

// ------------------ DSU (Union-Find) ------------------

int findSet(vector<int> &parent, int x) {
    return parent[x] = (parent[x] == x) ? x : findSet(parent, parent[x]);
}

void Union(vector<int> &parent, vector<int> &rank, int a, int b) {
    a = findSet(parent, a);
    b = findSet(parent, b);

    if (a == b) return;

    if (rank[a] >= rank[b]) {
        parent[b] = a;
        rank[a]++;
    } else {
        parent[a] = b;
        rank[b]++;
    }
}

// ---------------------- KRUSKAL ------------------------

void kruskal(vector<Edge> &graph, int v) {
    // Sort edges by weight
    sort(graph.begin(), graph.end(), [](const Edge &A, const Edge &B) {
        return A.w < B.w;
    });

    vector<int> parent(v), rank(v, 0);
    for (int i = 0; i < v; i++) parent[i] = i;

    int mstCost = 0;
    vector<Edge> mstEdges;

    for (auto &e : graph) {
        int x = e.u, y = e.v, w = e.w;

        if (findSet(parent, x) != findSet(parent, y)) {
            Union(parent, rank, x, y);
            mstCost += w;
            mstEdges.push_back(e);
        }
    }

    cout << "MST Cost = " << mstCost << "\n";
    cout << "Edges in MST:\n";

    for (auto &e : mstEdges) {
        cout << e.u << " -- " << e.v << "  weight = " << e.w << "\n";
    }
}

// ------------------------- MAIN -------------------------

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int e, v;
    cin >> v >> e;

    vector<Edge> graph(e);

    for (int i = 0; i < e; i++) {
        cin >> graph[i].u >> graph[i].v >> graph[i].w;
    }

    kruskal(graph, v);

    return 0;
}

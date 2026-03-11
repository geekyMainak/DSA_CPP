#include <bits/stdc++.h>
using namespace std;

vector<list<int>> graph;   // adjacency list using list<int>
set<int> visited;
int v, e;

void add_edge(int u, int v, bool bi_dir = true) {
    graph[u].push_back(v);
    if (bi_dir) graph[v].push_back(u);
}

void dfs(int node) {
    visited.insert(node);
    cout << node << " ";

    for (int nbr : graph[node]) {
        if (!visited.count(nbr)) {   // not visited
            dfs(nbr);
        }
    }
}

int main() {

    cin >> v >> e;
    graph.assign(v, list<int>());   // initialize vector of lists

    while (e--) {
        int u, v2;
        cin >> u >> v2;
        add_edge(u, v2);
    }

    int start;
    cin >> start;

    cout << "DFS Traversal: ";
    dfs(start);

    return 0;
}

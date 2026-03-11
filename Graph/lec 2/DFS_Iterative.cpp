#include <bits/stdc++.h>
using namespace std;

vector<list<int>> graph;   // adjacency list using list<int>
set<int> visited;
int v, e;

void add_edge(int u, int v, bool bi_dir = true) {
    graph[u].push_back(v);
    if (bi_dir) graph[v].push_back(u);
}

void dfs_iterative(int start) {
    stack<int> stk;

    stk.push(start);
    visited.insert(start);

    while (!stk.empty()) {
        int node = stk.top();
        stk.pop();

        cout << node << " ";

        // Push neighbours
        // Using list<int> as adjacency list
        for (int nbr : graph[node]) {
            if (!visited.count(nbr)) {
                visited.insert(nbr);
                stk.push(nbr);
            }
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

    cout << endl;
    int start;
    cin >> start;

    cout << "Iterative DFS Traversal: ";
    dfs_iterative(start);

    return 0;
}

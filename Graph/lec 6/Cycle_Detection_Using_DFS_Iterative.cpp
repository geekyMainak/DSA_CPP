#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

bool dfs_iterative(int start) {
    stack<pair<int,int>> st;  // (node, parent)
    st.push({start, -1});
    visited[start] = true;

    while (!st.empty()) {
        auto [node, parent] = st.top();
        st.pop();

        for (int nbr : graph[node]) {
            if (!visited[nbr]) {
                visited[nbr] = true;
                st.push({nbr, node});
            }
            else if (nbr != parent) {
                return true;  // cycle found
            }
        }
    }
    return false;
}

bool has_cycle(int n) {
    visited.assign(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs_iterative(i))
                return true;
        }
    }
    return false;
}

int main() {
    int n, e;
    cin >> n >> e;

    graph.assign(n, {});
    while (e--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // undirected
    }

    if (has_cycle(n))
        cout << "Cycle exists\n";
    else
        cout << "No cycle\n";
}
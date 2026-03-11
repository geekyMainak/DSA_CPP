#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

bool dfs(int node, int parent) {
    visited[node] = true;

    for (int nbr : graph[node]) {
        if (!visited[nbr]) {
            if (dfs(nbr, node))     return true;
        }
        else if (nbr != parent)     return true; // back-edge found → cycle
    }
    
    return false;
}

bool has_Cycle(int n) {
    visited.assign(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))     return true;
        }
    }
    return false;
}

int main() {
    int n, e;
    cin >> n >> e;

    graph.assign(n, {});

    while(e--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (has_Cycle(n))  
        cout << "Cycle exists\n";
    else    
        cout << "No cycle\n";
}

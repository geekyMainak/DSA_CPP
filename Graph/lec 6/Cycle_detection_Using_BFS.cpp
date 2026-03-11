#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

bool bfs(int start) {
    queue<pair<int,int>> q;  // (node, parent)
    visited[start] = true;
    q.push({start, -1});

    while(!q.empty()) {
        auto [node, parent] = q.front();
        q.pop();

        for (int nbr : graph[node]) {
            if (!visited[nbr]) {
                visited[nbr] = true;
                q.push({nbr, node});
            }
            else if (nbr != parent) {
                return true;   // visited & not parent => cycle
            }
        }
    }
    return false;
}

bool has_cycle(int n) {
    visited.assign(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (bfs(i))
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




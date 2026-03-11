#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

void shortest_path(int n, int src) {
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int nbr : graph[node]) {
            if(dist[nbr] == INT_MAX) {   // not visited
                dist[nbr] = dist[node] + 1;
                parent[nbr] = node;
                q.push(nbr);
            }
        }
    }

    // ⭐ Print distances
    cout << "Distances from source " << src << ":\n";
    for(int i = 0; i < n; i++) {
        cout << "Node " << i << " : " << dist[i] << "\n";
    }

    // ⭐ Print shortest paths
    cout << "\nPaths from source " << src << ":\n";
    for(int i = 0; i < n; i++) {
        if(dist[i] == INT_MAX) {
            cout << "No path to " << i << "\n";
            continue;
        }

        vector<int> path;
        for(int v = i; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        cout << "Path to " << i << " : ";
        for(int v : path) cout << v << " ";
        cout << "\n";
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n);

    while(m--) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);   // undirected
    }

    int src;
    cin >> src;

    shortest_path(n, src);
}

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

int n, m;
vector<list<P>> graph;      // {vertex, wt}

void dijkstra(int src) {
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);     // to reconstruct path

    priority_queue<P, vector<P>, greater<P>> pq;   // {dist, vertex}
    pq.emplace(0, src);
    dist[src] = 0;

    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (d != dist[v]) continue;   // skip stale entries

        for (auto &nbr : graph[v]) {
            int nbr_v  = nbr.first;
            int nbr_wt = nbr.second;

            if (d + nbr_wt < dist[nbr_v]) {
                dist[nbr_v] = d + nbr_wt;
                parent[nbr_v] = v;                // store parent
                pq.emplace(dist[nbr_v], nbr_v);
            }
        }
    }

    // PRINT SHORTEST DISTANCES
    cout << "\nShortest distances from source " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " : " << dist[i] << "\n";
    }

    // PRINT SHORTEST PATHS
    cout << "\nShortest paths from source:\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            cout << "No path to node " << i << "\n";
            continue;
        }

        vector<int> path;
        for (int v = i; v != -1; v = parent[v])
            path.push_back(v);
        reverse(path.begin(), path.end());

        cout << "Path to " << i << " : ";
        for (int v : path) cout << v << " ";
        cout << "\n";
    }
}

int main() {
    cin >> n >> m;
    graph.resize(n);

    while (m--) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].emplace_back(y, w);
        graph[y].emplace_back(x, w);   // undirected graph
    }

    int src;
    cin >> src;

    dijkstra(src);
}

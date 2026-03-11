#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;      // {dist, vertex}

int n, m;
vector<list<pair<int,int>>> graph;   // {neighbor, weight}

void dijkstra_set(int src) {
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);

    set<P> st;          // {distance, node}
    dist[src] = 0;
    st.insert({0, src});

    while(!st.empty()) {

        // Get the best (distance, node)
        auto it = st.begin();
        int d = it->first;
        int v = it->second;
        st.erase(it);

        // Relax edges
        for(auto &nbr : graph[v]) {
            int nbr_v  = nbr.first;
            int nbr_wt = nbr.second;

            if(d + nbr_wt < dist[nbr_v]) {

                // remove the previous entry if it exists
                if(dist[nbr_v] != INT_MAX) {
                    st.erase({dist[nbr_v], nbr_v});
                }

                dist[nbr_v] = d + nbr_wt;
                parent[nbr_v] = v;

                st.insert({dist[nbr_v], nbr_v});
            }
        }
    }

    // PRINT SHORTEST DISTANCES
    cout << "Shortest Distances from " << src << ":\n";
    for(int i = 0; i < n; i++)
        cout << "Node " << i << " : " << dist[i] << "\n";

    // PRINT PATHS
    cout << "\nShortest Paths from " << src << ":\n";
    for(int i = 0; i < n; i++) {
        if(dist[i] == INT_MAX) {
            cout << "No path to node " << i << "\n";
            continue;
        }

        vector<int> path;
        for(int v = i; v != -1; v = parent[v])
            path.push_back(v);
        reverse(path.begin(), path.end());

        cout << "Path to " << i << " : ";
        for(int x : path) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    cin >> n >> m;
    graph.resize(n);

    while(m--) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }

    int src;
    cin >> src;

    dijkstra_set(src);
}

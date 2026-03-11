/* ✅ 1. Kahn's Algorithm (Topological Sort + Cycle Detection)
   ✅ 2. DFS-Based Topological Sort */

#include <bits/stdc++.h>
using namespace std;

int v;
vector<vector<int>> graph;

bool topo_sort_kahn() {
    vector<int> indegree(v, 0);

    for(int i = 0; i < v; i++)
        for(int nbr : graph[i])
            indegree[nbr]++;

    queue<int> q;
    for(int i = 0; i < v; i++)
        if(indegree[i] == 0)
            q.push(i);

    vector<int> topo;
    int count = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        count++;

        for(int nbr : graph[node]) {
            indegree[nbr]--;
            if(indegree[nbr] == 0)
                q.push(nbr);
        }
    }

    if(count != v) {
        cout << "Cycle detected! Topological order not possible.\n";
        return false;
    }

    cout << "Topological Order (Kahn): ";
    for(int x : topo) cout << x << " ";
    cout << "\n";

    return true;
}

vector<int> visited; 
vector<int> result;

void dfs(int node) {
    visited[node] = 1;

    for(int nbr : graph[node]) {
        if(!visited[nbr]) {
            dfs(nbr);
        }
    }

    result.push_back(node);
}

void topo_sort_dfs() {
    visited.assign(v, 0);
    result.clear();

    for(int i = 0; i < v; i++) {
        if(!visited[i])
            dfs(i);
    }

    reverse(result.begin(), result.end());

    cout << "Topological Order (DFS): ";
    for(int x : result) cout << x << " ";
    cout << "\n";
}

int main() {
    int e;
    cin >> v >> e;
    graph.resize(v);

    while(e--) {
        int u, w;
        cin >> u >> w;
        graph[u].push_back(w);
    }

    topo_sort_kahn();
    topo_sort_dfs();

    return 0;
}

// Topological Sort (Kahn's Algorithm)
#include <bits\stdc++.h>
using namespace std;

int v;
vector<list<int>> graph;

void topo_sort() {
    // Kahn's Algorithm
    vector<int> indegree(v, 0);

    // Forming the indegree array
    for(int i = 0; i < v; i++) {
        for(auto nbr : graph[i]) {
            indegree[nbr]++;       // i -----> nbr
        }
    }

    queue<int> q;
    unordered_set<int> visited;

    // pushing the node whose indegree = 0 in the queue
    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0) {
            q.push(i);
            visited.insert(i);
        }
    }

    // MultiSource BFS 
    while(!q.empty()) {
        auto node = q.front();
        q.pop();

        cout << node << " ";

        for(auto nbr : graph[node]) {
            if(!visited.count(nbr)) {
                indegree[nbr]--;

                if(indegree[nbr] == 0) {
                    visited.insert(nbr);
                    q.push(nbr);
                }
            }
        }
    }
}

int main () {
    int e;
    cin >> v >> e;

    graph.resize(v, list<int> ());

    while(e--) {
        int x,y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    topo_sort();

    return 0;
}
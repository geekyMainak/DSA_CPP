#include <bits\stdc++.h>
using namespace std;

vector<list<int>> graph;
int v, e;

void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if(bi_dir)     graph[dest].push_back(src);
}

unordered_set<int> visited;
void bfs(int start, vector<int> &dist) {
    visited.clear();                     
    dist.assign(v, INT_MAX);             

    queue<int> q;
    q.push(start);
    visited.insert(start);
    dist[start] = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";
        
        for(auto nbr : graph[node]) {
            if(!visited.count(nbr)) {
                q.push(nbr);
                visited.insert(nbr);
                dist[nbr] = dist[node] + 1;
            }
        }
    }
}

int main () {
    cin >> v;
    graph.resize(v, list<int> ());

    int e;
    cin >> e;
    while(e--) {
        int s,d;
        cin >> s >> d;

        add_edge(s,d);
    }
    cout << endl;
    
    cout << "BFS: ";
    int start;  cin >> start;
    vector<int> dist;
    bfs(start, dist);

    cout << endl << "Shortest Distance array: ";
    for(auto ele : dist) {
        cout << ele << " ";
    }
    return 0;
}
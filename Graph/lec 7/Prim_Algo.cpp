// Prim's Algoritnm (here  we have start the bfs with vertex 0)

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef tuple<int,int,int> T;

int n, m;
vector<list<P>> graph;      // {vertex, wt}

int prim_algo() {
    priority_queue<T, vector<T>, greater<T>> pq;        // {wt, node, parent}
    vector<bool> inMST(n, false);       // Visited Array
    vector<int> parent(n, -1);

    pq.emplace(0, 0, -1); 

    int mstCost = 0;

    while(!pq.empty()) {
        int wt,node,par;
        tie(wt, node, par) = pq.top();
        pq.pop();

        if(inMST[node])     continue;

        inMST[node] = true;     // Mark Visited or include the node in the MST
        mstCost += wt;
        parent[node] = par;

        for(auto &m : graph[node]) {
            int nbr_v = m.first;
            int nbr_w = m.second;

            if(!inMST[nbr_v]) {
                pq.emplace(nbr_w, nbr_v, node);
            }    
        }
    }

    // PRINT MST EDGES SAFELY
    cout << "MST Edges:\n";
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1)        // important for disconnected graphs
            cout << parent[i] << " -- " << i << "\n";
    }

    return mstCost;
}

int main () {
    cin >> n >> m;
    graph.resize(n);

    while(m--) {
        int x, y, w;
        cin >> x >> y >> w;

        graph[x].emplace_back(y, w);
        graph[y].emplace_back(x,w);
    }

    cout << "MST Cost: " << prim_algo() << "\n";

    return 0;
}
// Existence of any path between any vertices 'u' and 'v'
#include <bits\stdc++.h>
using namespace std;

vector<list<int>> graph;
int v;

void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if(bi_dir)  graph[dest].push_back(src);
}

void display () {
    for(int i = 0; i < graph.size(); i++) {
        cout << i << " -> ";
        for(auto ele : graph[i]) {
            cout << ele << " -> ";
        }
        cout << "NULL\n";
    }
}

unordered_set<int> visited;
bool dfs(int curr, int end) {
    if(curr == end)     return true;
    visited.insert(curr);   // mark visited

    for(auto neighbour : graph[curr]) {
        if(!visited.count(neighbour)) {
            bool result = dfs(neighbour, end);
            if(result)      return true;
        }
    }
    return false;
}

bool anyPath(int start, int end) {
    return dfs(start, end);
}  

int main () {
    cin >> v;
    graph.resize(v, list<int> ());
    int e;  cin >> e;
    while(e--) {
        int s,d;
        cin >> s >> d;

        add_edge(s, d);
    }
    cout << "\n";
    display();

    cout << "\n";
    int x,y;
    cin >> x >> y;
    if(anyPath(x,y))    cout << "TRUE\n";
    else    cout << "FALSE\n";

    return 0;
}
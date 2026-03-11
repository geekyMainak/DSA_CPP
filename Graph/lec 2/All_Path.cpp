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
// ========================  ALL PATH   =============================
vector<vector<int>> allpath;
unordered_set<int> visited;
void dfs(int curr, int end, vector<int> &path) {
    if(curr == end) {
        path.push_back(curr);
        allpath.push_back(path);
        path.pop_back();
        return;
    }

    visited.insert(curr);   // mark visited
    path.push_back(curr);
    for(auto neighbour : graph[curr]) {
        if(!visited.count(neighbour)) {
            dfs(neighbour, end, path);
        }
    }

    path.pop_back();
    visited.erase(curr);
    return;
}

void allPath(int start, int end) {
    vector<int> v;
    return dfs(start, end, v);
}  

//  ==============================  MAIN  ==============================
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
    allPath(x,y);

    cout << "All Paths from " << x << " to " << y << " are:\n";
    for(auto path : allpath) {
        for(auto ele : path) {
            cout << ele << " - ";
        }
        cout << "\n";
    } 

    return 0;
}
#include <bits\stdc++.h>
using namespace std;

vector<list<int>> graph;
int v,e;

unordered_set<int> visited;
void dfs(int start) {
    stack<int> st;
    st.push(start);
    visited.insert(start);

    while(!st.empty()) {
        int node = st.top();
        st.pop();

        for(auto nbr : graph[node]) {
            if(!visited.count(nbr)) {
                visited.insert(nbr);
                st.push(nbr);
            }
        }
    }
}

int connected_components() {
    visited.clear(); 
    int result = 0;

    for(int i = 0; i < v; i++) {
        if(visited.count(i) == 0) {
            result++;
            dfs(i);
        }
    }
    return result;
}

int main () {
    cin >> v >> e;
    graph.assign(v, list<int>());

    while(e--) {
        int u1,v1;
        cin >> u1 >> v1;

        graph[u1].push_back(v1);
        graph[v1].push_back(u1);
    }
    cout << endl;
    cout << "Number of connected components are : " << connected_components() << endl;

    return 0;
}
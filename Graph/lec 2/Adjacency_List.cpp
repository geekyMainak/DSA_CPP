#include <bits\stdc++.h>
using namespace std;

// Unweighted Graph
vector<list<int>> graph;
int v;

void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if(bi_dir)     graph[dest].push_back(src);
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

// Weighted Graph
vector<list<pair<int, int>>> w_graph;
int w_v;

void add_w_edge(int src, int dest, int wt, bool bi_dir = true) {
    w_graph[src].push_back({dest, wt});
    if(bi_dir)     w_graph[dest].push_back({src, wt});
}

void w_display () {
    for(int i = 0; i < w_graph.size(); i++) {
        cout << i << " -> ";
        for(auto ele : w_graph[i]) {
            cout << "(" << ele.first << ","  << ele.second << ")" << " -> ";
        }
        cout << "NULL\n";
    }
}


int main () {

    // Unweighted Graph
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
    display();


    // Weighted Graph
    cin >> w_v;
    w_graph.resize(w_v, list<pair<int,int>> ());

    int w_e;
    cin >> w_e;
    while(w_e--) {
        int s,d, wt;
        cin >> s >> d >> wt;

        add_w_edge(s,d, wt);
    }
    cout << endl;
    w_display();


    return 0;
}
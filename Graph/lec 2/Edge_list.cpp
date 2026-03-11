#include <bits/stdc++.h>
using namespace std;

// Unweighted Edge List
vector<pair<int,int>> edgeList;

// Weighted Edge List
struct Edge {
    int u, v, w;
};
vector<Edge> w_edgeList;

// Functions
void add_edge(int u, int v) {
    edgeList.push_back({u, v});
}

void add_w_edge(int u, int v, int w) {
    w_edgeList.push_back({u, v, w});
}

void display_edgeList() {
    cout << "\nUnweighted Edge List:\n";
    for (auto &p : edgeList)
        cout << "(" << p.first << "," << p.second << ")\n";
}

void display_w_edgeList() {
    cout << "\nWeighted Edge List:\n";
    for (auto &edge : w_edgeList)
        cout << "(" << edge.u << "," << edge.v << "," << edge.w << ")\n";
}

int main() {

    // ---- Unweighted ----
    int v, e;
    cin >> v >> e;
    while (e--) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }
    display_edgeList();

    // ---- Weighted ----
    int wv, we;
    cin >> wv >> we;
    while (we--) {
        int u, v, w;
        cin >> u >> v >> w;
        add_w_edge(u, v, w);
    }
    display_w_edgeList();

    return 0;
}

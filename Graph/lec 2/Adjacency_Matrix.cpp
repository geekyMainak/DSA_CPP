#include <bits/stdc++.h>
using namespace std;

// -------------------- Unweighted Adjacency Matrix --------------------
vector<vector<int>> adjMat;   // 0/1 matrix
int v;

void add_edge(int u, int v, bool bi_dir = true) {
    adjMat[u][v] = 1;
    if (bi_dir) adjMat[v][u] = 1;
}

void display_adjMat() {
    cout << "\nUnweighted Adjacency Matrix:\n";
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++)
            cout << adjMat[i][j] << " ";
        cout << "\n";
    }
}

// -------------------- Weighted Adjacency Matrix --------------------
vector<vector<int>> w_adjMat;   // weight matrix
int w_v;

void add_w_edge(int u, int v, int wt, bool bi_dir = true) {
    w_adjMat[u][v] = wt;
    if (bi_dir) w_adjMat[v][u] = wt;
}

void display_w_adjMat() {
    cout << "\nWeighted Adjacency Matrix:\n";
    for (int i = 0; i < w_v; i++) {
        for (int j = 0; j < w_v; j++)
            cout << w_adjMat[i][j] << " ";
        cout << "\n";
    }
}

// ------------------------------- MAIN ----------------------------------
int main() {

    // -------- UNWEIGHTED MATRIX --------
    cin >> v;
    adjMat.assign(v, vector<int>(v, 0));

    int e;
    cin >> e;
    while (e--) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }

    display_adjMat();


    // -------- WEIGHTED MATRIX --------
    cin >> w_v;
    w_adjMat.assign(w_v, vector<int>(w_v, 0));   // 0 means no edge

    int w_e;
    cin >> w_e;
    while (w_e--) {
        int u, v, wt;
        cin >> u >> v >> wt;
        add_w_edge(u, v, wt);
    }

    display_w_adjMat();


    return 0;
}

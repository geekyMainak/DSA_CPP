#include <bits/stdc++.h>
using namespace std;

// --------------------- UNWEIGHTED INCIDENCE MATRIX ---------------------
vector<vector<int>> incMat;
int v, e;

void build_incidence_matrix(vector<pair<int,int>>& edges) {
    incMat.assign(v, vector<int>(e, 0));

    for (int j = 0; j < e; j++) {
        int u = edges[j].first;
        int v = edges[j].second;

        incMat[u][j] = 1;
        incMat[v][j] = 1;
    }
}

void display_incidence_matrix() {
    cout << "\nUnweighted Incidence Matrix (V x E):\n";
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < e; j++)
            cout << incMat[i][j] << " ";
        cout << endl;
    }
}

// ----------------------- WEIGHTED INCIDENCE MATRIX ---------------------
vector<vector<int>> w_incMat;
int w_v, w_e;

void build_weighted_incidence_matrix(vector<tuple<int,int,int>>& edges) {
    w_incMat.assign(w_v, vector<int>(w_e, 0));

    for (int j = 0; j < w_e; j++) {
        int u, v, w;
        tie(u, v, w) = edges[j];

        w_incMat[u][j] = w;
        w_incMat[v][j] = w;
    }
}

void display_weighted_incidence_matrix() {
    cout << "\nWeighted Incidence Matrix (V x E):\n";
    for (int i = 0; i < w_v; i++) {
        for (int j = 0; j < w_e; j++)
            cout << w_incMat[i][j] << " ";
        cout << endl;
    }
}

// -------------------------------- MAIN ---------------------------------
int main() {

    // ---------------- UNWEIGHTED ----------------
    cin >> v >> e;

    vector<pair<int,int>> edges;

    for (int i = 0; i < e; i++) {
        int u, v2;
        cin >> u >> v2;
        edges.push_back({u, v2});
    }

    build_incidence_matrix(edges);
    display_incidence_matrix();


    // ---------------- WEIGHTED ----------------
    cin >> w_v >> w_e;

    vector<tuple<int,int,int>> w_edges;

    for (int i = 0; i < w_e; i++) {
        int u, v2, w;
        cin >> u >> v2 >> w;
        w_edges.push_back({u, v2, w});
    }

    build_weighted_incidence_matrix(w_edges);
    display_weighted_incidence_matrix();


    return 0;
}

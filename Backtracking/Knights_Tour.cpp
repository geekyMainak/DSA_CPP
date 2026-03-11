// Using Recursion + Backtracking - O(8^(n*n)) Time and O(n^2) Space starting from (0,0)
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,a,b) for(int i=(a); i<(b); ++i) // from a to b-1
using ll = long long;
using P = pair<int,int>;

int n;
vector<vector<int>> board;
vector<P> dirs = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

bool knights_tour(int r, int c, int step) {
    // base case
    if(step == n*n) {
        return true;
    }

    for(auto &d : dirs) {
        int nr = r + d.first;
        int nc = c + d.second;

        if(nr < 0 || nc < 0 || nr >= n || nc >= n)      continue;
        if(board[nr][nc] != -1)     continue;

        board[nr][nc] = step;
        if(knights_tour(nr, nc, step + 1))    return true;
        board[nr][nc] = -1;
    }
    
    return false;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    board.resize(n, vector<int> (n, -1));
    board[0][0] = 0;

    if(knights_tour(0, 0, 1)) {
        for(auto &i : board) {
            for(auto &j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    } else {
        cout << -1 << "\n";
    }



    return 0;
}
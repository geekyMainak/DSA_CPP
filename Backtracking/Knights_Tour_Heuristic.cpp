#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,a,b) for (int i = (a); i < (b); ++i)

using ll = long long;
using P  = pair<int,int>;

int n;
vector<vector<int>> board;

vector<P> movesKnight = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

// Count onward moves from (r, c)
int degree(int r, int c) {
    int cnt = 0;
    for(auto &m : movesKnight) {
        int nr = r + m.first;
        int nc = c + m.second;
        if(nr >= 0 && nr < n && nc >= 0 && nc < n && board[nr][nc] == -1)
            cnt++;
    }
    return cnt;
}

bool solveKT(int r, int c, int moveNo) {
    if(moveNo == n * n)
        return true;

    // (degree, row, col)
    vector< tuple<int,int,int> > nextMoves;

    for(auto &m : movesKnight) {
        int nr = r + m.first;
        int nc = c + m.second;
        if(nr >= 0 && nr < n && nc >= 0 && nc < n && board[nr][nc] == -1) {
            nextMoves.push_back(
                make_tuple(degree(nr, nc), nr, nc)
            );
        }
    }

    sort(nextMoves.begin(), nextMoves.end());

    // ❌ No structured binding (C++17)
    // ✅ Old-style access
    for(size_t i = 0; i < nextMoves.size(); i++) {
        int nr = get<1>(nextMoves[i]);
        int nc = get<2>(nextMoves[i]);

        board[nr][nc] = moveNo;
        if(solveKT(nr, nc, moveNo + 1))
            return true;

        board[nr][nc] = -1; // backtrack
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int sr, sc;
    cin >> sr >> sc;

    board.assign(n, vector<int>(n, -1));
    board[sr][sc] = 0;

    if(solveKT(sr, sc, 1)) {
        rep(i, n) {
            rep(j, n) {
                cout << setw(3) << board[i][j] << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "No solution exists\n";
    }

    return 0;
} 

// Only feasible for n < 6 (because number of tours is HUGE for 7×7+)
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> board;
vector<pair<int,int>> movesKnight = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1},{-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
long long totalTours = 0;

void printBoard() {
    cout << "Tour #" << (++totalTours) << "\n";
    for(auto &row : board) {
        for(int x : row) cout << setw(3) << x << " ";
        cout << "\n";
    }
    cout << "\n";
}

void solveKT(int r, int c, int moveNo) {
    if(moveNo == n*n) {
        printBoard();
        return;
    }

    for(auto &m : movesKnight) {
        int nr = r + m.first;
        int nc = c + m.second;

        if(nr >= 0 && nr < n && nc >= 0 && nc < n && board[nr][nc] == -1) {
            board[nr][nc] = moveNo;
            solveKT(nr, nc, moveNo + 1);
            board[nr][nc] = -1; // backtrack
        }
    }
}

int main() {
    cin >> n;

    board.assign(n, vector<int>(n, -1));
    board[0][0] = 0; // start top-left

    solveKT(0, 0, 1);

    cout << "Total Tours = " << totalTours << "\n";
}

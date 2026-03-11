#include <bits/stdc++.h>
using namespace std;

int r, c;
vector<vector<int>> grid;
vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int cnt = 0;

// 0 -> Open Cells      1 -> Block Cells      2 -> Visited
void ratInMaze(int row, int col) {
    // Boundary checks
    if(row < 0 || col < 0 || row >= r || col >= c)      return;

    // if blocked or already visited
    if(grid[row][col] != 0)     return;

    // base case
    if(row == r-1 && col == c-1) {
        cnt++;
        return;
    }

    // mark visited
    grid[row][col] = 2;

    for(auto &d : dirs) {
        int nr = row + d.first;
        int nc = col + d.second;

        ratInMaze(nr, nc);
    }

    // Backtrack
    grid[row][col] = 0;
}

int main() {
    cin >> r >> c;
    grid.assign(r, vector<int>(c));

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++)
            cin >> grid[i][j];
    }

    ratInMaze(0, 0);
    cout << cnt;

    return 0;
}



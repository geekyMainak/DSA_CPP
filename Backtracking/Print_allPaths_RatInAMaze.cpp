#include <bits/stdc++.h>
using namespace std;

int r, c;
vector<vector<int>> grid;
vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
vector<char> moves = {'D','U','R','L'};   // corresponding to dirs[]
vector<string> allPaths;
string path = "";

// 0 -> Open Cells, 1 -> Blocked, 2 -> Visited
void ratInMaze(int row, int col) {

    // boundary check
    if(row < 0 || col < 0 || row >= r || col >= c) 
        return;

    // block or visited
    if(grid[row][col] != 0) 
        return;

    // base case (destination)
    if(row == r-1 && col == c-1) {
        allPaths.push_back(path);
        return;
    }

    // mark visited
    grid[row][col] = 2;

    // explore all 4 directions
    for(int i = 0; i < 4; i++) {
        int nr = row + dirs[i].first;
        int nc = col + dirs[i].second;

        path.push_back(moves[i]);
        ratInMaze(nr, nc);
        path.pop_back();
    }

    // backtrack
    grid[row][col] = 0;
}

int main() {
    cin >> r >> c;
    grid.assign(r, vector<int>(c));

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> grid[i][j];

    ratInMaze(0, 0);

    // printing all paths
    if(allPaths.empty()) {
        cout << "No paths found\n";
    } else {
        for(string &p : allPaths)
            cout << p << "\n";

        cout << "Total Paths = " << allPaths.size() << "\n";
    }

    return 0;
}

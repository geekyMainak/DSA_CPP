#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int cc = 0;     // Number of connected components = Number of islands

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {

                if(grid[r][c] == '0') {     // Skip water body
                    continue;
                }
                
                if(grid[r][c] == '-1') {    // Skip visited land piece
                    continue;
                }

                // Found a new unvisited land piece i.e. new connected components
                cc++;

                queue<pair<int, int>> q;
                q.push({r, c});
                grid[r][c] = '-1';   // mark visited

                while(!q.empty()) {
                    auto curr = q.front();
                    q.pop();

                    int currRow = curr.first;
                    int currCol = curr.second;

                    // Up
                    if(currRow - 1 >= 0 && grid[currRow - 1][currCol] == '1') {
                        q.push({currRow - 1, currCol});
                        grid[currRow - 1][currCol] = '-1';
                    }

                    // Down
                    if(currRow + 1 < rows && grid[currRow + 1][currCol] == '1') {
                        q.push({currRow + 1, currCol});
                        grid[currRow + 1][currCol] = '-1';
                    }

                    // Left
                    if(currCol - 1 >= 0 && grid[currRow][currCol - 1] == '1') {
                        q.push({currRow, currCol - 1});
                        grid[currRow][currCol - 1] = '-1';
                    }

                    // Right
                    if(currCol + 1 < cols && grid[currRow][currCol + 1] == '1') {
                        q.push({currRow, currCol + 1});
                        grid[currRow][currCol + 1] = '-1';
                    }
                }
            }
        }

        return cc;
    }
};

int main() {

    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<char>> grid(rows, vector<char>(cols));

    cout << "Enter grid values (0 or 1):\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    Solution s;
    int ans = s.numIslands(grid);

    cout << "Number of islands = " << ans << endl;

    return 0;
}

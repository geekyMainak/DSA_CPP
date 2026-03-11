#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> image;
int n, m;

void dfs(int r, int c, int oldColor, int newColor) {
    // Boundary check
    if (r < 0 || r >= n || c < 0 || c >= m) return;

    // Different color → stop
    if (image[r][c] != oldColor) return;

    // Already colored → stop
    if (image[r][c] == newColor) return;

    image[r][c] = newColor;   // Fill current cell

    // Move in 4 directions
    dfs(r+1, c, oldColor, newColor);
    dfs(r-1, c, oldColor, newColor);
    dfs(r, c+1, oldColor, newColor);
    dfs(r, c-1, oldColor, newColor);
}

int main() {
    cin >> n >> m;
    image.assign(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> image[i][j];

    int sr, sc, newColor;
    cin >> sr >> sc >> newColor;

    int oldColor = image[sr][sc];
    if (oldColor != newColor)
        dfs(sr, sc, oldColor, newColor);

    // Output final matrix
    for (auto &row : image) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
}

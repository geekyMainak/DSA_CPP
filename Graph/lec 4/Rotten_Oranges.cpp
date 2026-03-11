// Method 1
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        // Step 1: Push all rotten oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        // No fresh oranges → 0 minutes
        if (fresh == 0) return 0;

        // Push sentinel to mark the first "minute boundary"
        q.push({-1, -1});

        int time = 0;

        // BFS begins
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            // If sentinel reached → end of this minute
            if (r == -1 && c == -1) {

                // If no more oranges to process → break
                if (q.empty()) break;

                // Otherwise minute finished → increment
                time++;

                // Push another sentinel for next minute
                q.push({-1, -1});
                continue;
            }

            // Explore neighbors
            for (auto &d : dirs) {
                int nr = r + d.first;
                int nc = c + d.second;

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                if (grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;      // rot it
                    fresh--;
                    q.push({nr, nc});
                }
            }
        }

        return (fresh > 0) ? -1 : time;
    }
};



// Method 2
class Solution {
public:
    // 0 representing an empty cell,
    // 1 representing a fresh orange, or
    // 2 representing a rotten orange.

    int time = 0;
    int m,n;
    vector<vector<int>> matrix;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void multiSourceBFS(queue<pair<int,int>> &q) {
        while(!q.empty()) {
            bool rot = false;
            int size = q.size();

            while(size--) {
                auto [i, j] = q.front();
                q.pop();
                for(auto &d : dirs) {
                    int nr = i + d.first;
                    int nc = j + d.second;

                    if(nr < 0 || nr >= m || nc < 0 || nc >= n)      continue;
                    if(matrix[nr][nc] == 2 || matrix[nr][nc] == 0)      continue;


                    matrix[nr][nc] = 2;
                    q.push({nr, nc}); 
                    rot = true;            
                }
            }
            if(rot)     time++;
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        matrix = grid;
        m = grid.size();
        n = grid[0].size();

        queue<pair<int,int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2)     q.push({i, j});
            }
        }

        multiSourceBFS(q);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1)     return -1;
            }
        }

        return time;        
    }
};
/* 286. Walls and Gates — Problem StatementYou are given a 2D grid (rooms) where:
-1 represents a wall or an obstacle 0 represents a gate INF represents an empty room
(In LeetCode, INF = 2^31 - 1 = 2147483647)Your task is to fill each empty room with 
the distance to its nearest gate. If a room cannot reach any gate, leave it as INF.
Rules:  You can move up, down, left, right (4 directions) */

/* 1197. Minimum Knight Moves

A chess knight can move in 8 possible directions (like in standard chess).
You are given two integers x and y representing a target position on an infinite 2D chessboard, 
where the knight starts from (0, 0).

Return the minimum number of moves required for the knight to reach (x, y). */

#include <bits/stdc++.h>
using namespace std;

int m,n;
static const int INF = 2147483647;

class Solution {
public:
    vector<vector<int>> dist;
    vector<pair<int,int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void multiSourceBFS(queue<pair<int, int>> &q) {
        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            int i = node.first;
            int j = node.second;

            for(auto &d : dirs) {
                int nr = i + d.first;
                int nc = j + d.second;

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && dist[nr][nc] == INF) {
                    dist[nr][nc] = 1 + dist[i][j];
                    q.emplace(nr, nc);
                }
            }
        }
    }

    void wallsAndGates(vector<vector<int>> &rooms) {
        m = rooms.size();
        n = rooms[0].size();

        dist.assign(m, vector<int> (n, INF));

        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(rooms[i][j] == 0)  {
                    dist[i][j] = 0;
                    q.emplace(i, j);
                } else if(rooms[i][j] == -1)    dist[i][j] = -1;   
            }
        }

        multiSourceBFS(q);


        rooms = dist;
    }
};

int main() {
    cin >> m >> n;

    vector<vector<int>> rooms(m, vector<int>(n));

    // Input the grid
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> rooms[i][j];
        }
    }

    Solution obj;
    obj.wallsAndGates(rooms);

    // Print output grid
    cout << "\nOutput:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << rooms[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
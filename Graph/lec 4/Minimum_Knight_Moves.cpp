/* 1197. Minimum Knight Moves

A chess knight can move in 8 possible directions (like in standard chess).
You are given two integers x and y representing a target position on an infinite 2D chessboard, 
where the knight starts from (0, 0).

Return the minimum number of moves required for the knight to reach (x, y). */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    int minKnightMoves(int x, int y) {
        queue<pair<int,int>> q;
        set<pair<int,int>> visited;

        q.emplace(0,0);
        visited.emplace(0,0);

        x = abs(x);
        y = abs(y);

        vector<pair<int,int>> dirs =  {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};

        int moves = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {

                auto node = q.front();
                q.pop();

                int i = node.first;
                int j = node.second;

                // Check HERE, not in neighbor loop
                if (i == x && j == y)       return moves;

                for (auto &d : dirs) {
                    int nr = i + d.first;
                    int nc = j + d.second;

                    if (nr < -2 || nc < -2) continue;

                    if (!visited.count({nr, nc})) {
                        visited.emplace(nr, nc);
                        q.emplace(nr, nc);
                    }
                }
            }
            moves++; // increment AFTER finishing level
        }

        return -1;
    }
};

int main() {
    Solution sol;

    int x, y;
    cout << "Enter target position (x y): ";
    cin >> x >> y;

    int moves = sol.minKnightMoves(x, y);
    cout << "Minimum knight moves = " << moves << endl;

    return 0;
}
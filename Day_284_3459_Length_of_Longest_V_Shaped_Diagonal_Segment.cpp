#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the length of longest V-shaped diagonal segment
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // Define directions: down-right, down-left, up-left, up-right
        int dirs[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        // Memoization array to store computed results
        int memo[m][n][4][2];
        memset(memo, -1, sizeof(memo));

        // DFS function to explore diagonal paths
        // cx, cy: current coordinates
        // direction: current direction of movement
        // turn: whether we can make a turn
        // target: target value we're looking for (alternates between 1 and 2)
        function<int(int, int, int, bool, int)> dfs =
            [&](int cx, int cy, int direction, bool turn, int target) -> int {
            int nx = cx + dirs[direction][0];
            int ny = cy + dirs[direction][1];
            /* If it goes beyond the boundary or the next node's value is not
             * the target value, then return */
            if (nx < 0 || ny < 0 || nx >= m || ny >= n ||
                grid[nx][ny] != target) {
                return 0;
            }
            // Return memoized result if available
            if (memo[nx][ny][direction][turn] != -1) {
                return memo[nx][ny][direction][turn];
            }

            // Try continuing in the same direction
            int maxStep = dfs(nx, ny, direction, turn, 2 - target);
            if (turn) {
                // If turn is allowed, try making a 90-degree clockwise turn
                maxStep = fmax(maxStep, dfs(nx, ny, (direction + 1) % 4, false,
                                            2 - target));
            }
            // Store and return result
            memo[nx][ny][direction][turn] = maxStep + 1;
            return maxStep + 1;
        };

        // Find maximum V-shaped path length
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {  // Start from cells with value 1
                    for (int direction = 0; direction < 4; ++direction) {
                        res = fmax(res, dfs(i, j, direction, true, 2) + 1);
                    }
                }
            }
        }

        return res;
    }
};
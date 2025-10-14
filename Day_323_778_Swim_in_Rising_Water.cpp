#include <bits/stdc++.h>
using namespace std;

// Problem: 778. Swim in Rising Water
// Approach: Dijkstra's algorithm to find the minimum time to reach the bottom-right cell

// Steps:
// 1. Use a priority queue to explore the grid, starting from the top-left cell.
// 2. Keep track of the maximum elevation encountered on the path to ensure the water level is sufficient.
// 3. Explore all four possible directions from the current cell and add unvisited cells to the priority queue.
// 4. Continue until the bottom-right cell is reached, returning the maximum elevation on the path.
// 5. Return the maximum elevation encountered on the path to the bottom-right cell.

// Time Complexity: O(n^2 log(n^2)) due to the priority queue operations.
// Space Complexity: O(n^2) for the visited array and the priority queue.

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<int> route;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        int maxElevation = 0;
        vector<int> dir = {-1, 0, 1, 0, -1};

        while (!pq.empty()) {
            auto [elev, i, j] = pq.top();
            pq.pop();
            maxElevation = max(maxElevation, elev);
            route.push_back(elev);

            if (i == n - 1 && j == n - 1)
                return maxElevation;

            for (int d = 0; d < 4; ++d) {
                int ni = i + dir[d];
                int nj = j + dir[d + 1];
                if (ni >= 0 && nj >= 0 && ni < n && nj < n && !visited[ni][nj]) {
                    visited[ni][nj] = true;
                    pq.push({grid[ni][nj], ni, nj});
                }
            }
        }

        return maxElevation;
    }
};
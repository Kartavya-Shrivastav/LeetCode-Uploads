#include <bits/stdc++.h>
using namespace std;

// Problem: 407. Trapping Rain Water II
// Approach: Min-Heap (Priority Queue) and BFS

// Steps:
// 1. Use a min-heap to always expand from the lowest boundary.
// 2. Initialize the heap with all the boundary cells and mark them as visited.
// 3. While the heap is not empty, pop the cell with the lowest height.
// 4. For each of its unvisited neighbors, calculate the trapped water (if any) and update the neighbor's height.
// 5. Push the neighbor into the heap and mark it as visited.
// 6. Continue until all cells are processed.
// 7. Return the total amount of trapped water.

// Time Complexity: O(m * n * log(m + n)), where m and n are the dimensions of the height map.
// Space Complexity: O(m * n) for the visited array and the heap.

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
    using HeightAndCoordinates = tuple<int, int, int>;
        priority_queue<HeightAndCoordinates, vector<HeightAndCoordinates>, greater<HeightAndCoordinates>> min_heap;

        int rows = heightMap.size(), cols = heightMap[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                    min_heap.emplace(heightMap[i][j], i, j);
                    visited[i][j] = true;
                }
            }
        }

        int trapped_water = 0;

        const int directions[5] = {-1, 0, 1, 0, -1};

        while (!min_heap.empty()) {
            auto [current_height, row, col] = min_heap.top();
            min_heap.pop();

            for (int k = 0; k < 4; ++k) {
                int new_row = row + directions[k];
                int new_col = col + directions[k + 1];

                if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols && !visited[new_row][new_col]) {
                   trapped_water += max(0, current_height - heightMap[new_row][new_col]);

                   visited[new_row][new_col] = true;

                    min_heap.emplace(max(heightMap[new_row][new_col], current_height), new_row, new_col);
                }
            }
        }

        return trapped_water;       
    }
};_
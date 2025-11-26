#include <bits/stdc++.h>
using namespace std;

// Problem: Paths in Matrix Whose Sum Is Divisible by K
// Approach: Dynamic Programming with Space Optimization

// Steps:
// 1. Initialize two 2D vectors `prev` and `curr` to store the number of paths to each cell with sums modulo k.
// 2. Fill the first row of the `prev` array based on the cumulative sums modulo k.
// 3. Iterate through each cell in the matrix starting from the second row.
// 4. For each cell, update the `curr` array based on the values from the `prev` array and the left cell in the `curr` array.
// 5. After processing each row, swap `prev` and `curr` to save space.
// 6. Finally, return the number of paths to the bottom-right cell with sum modulo k equal to 0.

// Time Complexity: O(m * n * k)
// Space Complexity: O(n * k) due to the two 2D vectors used for dynamic programming

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1000000007;
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> prev(n, vector<int>(k)), curr(n, vector<int>(k));
        int sum = 0;

        for (int j = 0; j < n; j++) {
            sum = (sum + grid[0][j]) % k;
            prev[j][sum] = 1;
        }

        sum = grid[0][0] % k;

        for (int i = 1; i < m; i++) {
            sum = (sum + grid[i][0]) % k;
            fill(curr[0].begin(), curr[0].end(), 0);
            curr[0][sum] = 1;

            for (int j = 1; j < n; j++) {
                fill(curr[j].begin(), curr[j].end(), 0);
                int val = grid[i][j];
                for (int r = 0; r < k; r++) {
                    int nr = (r + val) % k;
                    curr[j][nr] = (prev[j][r] + curr[j - 1][r]) % MOD;
                }
            }

            swap(prev, curr);
        }

        return prev[n - 1][0];
    }
};
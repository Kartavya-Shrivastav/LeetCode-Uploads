#include <bits/stdc++.h>
using namespace std;

// Problem: Number of Ways to Paint N × 3 Grid
// Approach: We use a recursive function with memoization (top-down dynamic programming) to count the number of valid ways to paint the grid. The function considers each row and ensures that no two adjacent cells (horizontally or vertically) have the same color. We use a 4D DP array to store results for subproblems defined by the current row index and the colors of the previous row.

// Steps:
// 1. Define a recursive function `solve` that takes the current row index, the number of rows, the colors of the previous row, and a DP array for memoization.
// 2. If the current row index equals the total number of rows, return 1 as a valid configuration is found.
// 3. If the result for the current state is already computed, return it from the DP array.
// 4. Iterate through all possible color combinations for the current row, ensuring that no two adjacent cells have the same color and that they differ from the colors of the previous row.
// 5. Accumulate the count of valid configurations and store it in the DP array before returning.
// 6. The main function `numOfWays` initializes the DP array and calls the recursive function starting from the first row with no previous colors.

// Time Complexity: O(n), where n is the number of rows in the grid, since each state is computed once.
// Space Complexity: O(n), due to the DP array used for memoization.

class Solution {
public:
    int solve(int i, int n, int prev1, int prev2, int prev3, int mod,
              vector<vector<vector<vector<int>>>>& dp) {
        if (i == n) {
            return 1;
        }
        if (dp[i][prev1][prev2][prev3] != -1) {
            return dp[i][prev1][prev2][prev3];
        }
        int ans = 0;
        for (int col1 = 1; col1 <= 3; col1++) {
            if (col1 == prev1) {
                continue;
            }
            for (int col2 = 1; col2 <= 3; col2++) {
                if (col2 == prev2 || col2 == col1) {
                    continue;
                }
                for (int col3 = 1; col3 <= 3; col3++) {
                    if (col3 == prev3 || col3 == col2) {
                        continue;
                    }
                    ans = (ans + solve(i + 1, n, col1, col2, col3, mod, dp)) %
                          mod;
                }
            }
        }
        return dp[i][prev1][prev2][prev3] = ans;
    }
    int numOfWays(int n) {
        int mod = 1e9 + 7;
        vector<vector<vector<vector<int>>>> dp(
            n, vector<vector<vector<int>>>(
                   4, vector<vector<int>>(4, vector<int>(4, -1))));
        return solve(0, n, 0, 0, 0, mod, dp);
    }
};
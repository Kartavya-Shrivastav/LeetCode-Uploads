#include <bits/stdc++.h>
using namespace std;

/*
Problem: We have a grid of coins, and a robot starts at the top-left corner. The robot can move right or down, and it can also skip one cell in either direction at most once. We need to find the maximum amount of money the robot can earn by collecting coins.
Approach: We can use dynamic programming to solve this problem. We will maintain a 3D DP array where dp[i][j][k] represents the maximum amount of money the robot can earn when it is at cell (i, j) and has used k skips (0, 1, or 2).

Steps:
1. Initialize the DP array with a very small value (e.g., -1e9) to represent impossible states.
2. Set the base case for the starting cell (0, 0) where dp[0][0][0] is the value of the coin at (0, 0), and dp[0][0][1] and dp[0][0][2] are 0 since we can skip the starting cell.
3. Iterate through each cell in the grid and update the DP values based on the possible moves:
   - If we move down from (i-1, j), we can add the coin value at (i, j) to dp[i-1][j][k] for k = 0, 1, 2.
   - If we move right from (i, j-1), we can add the coin value at (i, j) to dp[i][j-1][k] for k = 0, 1, 2.
   - If we skip down from (i-2, j), we can take dp[i-2][j][k-1] for k = 1, 2.
   - If we skip right from (i, j-2), we can take dp[i][j-2][k-1] for k = 1, 2.
4. After filling the DP array, the answer will be the maximum value in dp[n-1][m-1] for k = 0, 1, 2.

Time Complexity: O(n * m * 3) = O(n * m) since we are iterating through each cell and each state of k.
Space Complexity: O(n * m * 3) = O(n * m) for the DP array.
*/

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        vector dp(n, vector(m, vector<int>(3, -1e9)));
        dp[0][0][1] = dp[0][0][2] = 0, dp[0][0][0] = coins[0][0];
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < 3; k++) {
                    if (i) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + coins[i][j]);
                    if (i && k) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1]);
                    if (j) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + coins[i][j]);
                    if (j && k) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1]);
                }
        int ans = *max_element(dp[n - 1][m - 1].begin(), dp[n - 1][m - 1].end());
        return ans;
    }
};
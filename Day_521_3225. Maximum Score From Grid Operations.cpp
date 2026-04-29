#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a 2D grid of integers, you can perform operations to maximize the score. The score is calculated based on the values in the grid and the operations performed. You can choose to either take the value from the current cell or skip it and move to the next cell. The goal is to maximize the total score by choosing the optimal path through the grid.
Approach: We can use dynamic programming to solve this problem. We will maintain two arrays, dp0 and dp1, where dp0[i] represents the maximum score we can achieve by skipping the current cell at row i, and dp1[i] represents the maximum score we can achieve by taking the value from the current cell at row i. We will iterate through each column of the grid and update these arrays based on the values in the grid and the previous scores.

Steps:
1. Initialize two arrays, dp0 and dp1, of size n + 1 with all values set to 0, where n is the number of rows in the grid.
2. Iterate through each column of the grid starting from the second column (index 1).
3. For each column, create two new arrays, new_dp0 and new_dp1, to store the updated scores for the current column.
4. For each row index i from 0 to n, calculate the current score by summing the values in the current column for the first i rows. This represents the score if we choose to take the value from the current cell.
5. For each row index y from 0 to n, update the new_dp0 and new_dp1 arrays based on the previous scores in dp0 and dp1, and the current score calculated in step 4. The new_dp0[y] will be the maximum of the previous dp0[i] and dp1[i] plus any additional score from skipping or taking the current cell. The new_dp1[y] will be the maximum of the current score plus the previous dp1[i] or the current score plus the previous dp0[i].
6. After processing all rows for the current column, update dp0 and dp1 with new_dp0 and new_dp1 respectively.
7. Finally, return the maximum value in dp1, which represents the maximum score we can achieve by taking values from the grid.

Time Complexity: O(n^2), where n is the number of rows in the grid, since we are iterating through each column and for each column, we are iterating through all rows to update the dp arrays.
Space Complexity: O(n), where n is the number of rows in the grid, since we are using two arrays of size n + 1 to store the scores.
*/

class Solution {
using ll = long long;
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) 
            return 0;
        vector<ll> dp0(n + 1, 0), dp1(n + 1, 0);

        for (int j = 1; j < n; j++) {
            vector<ll> new_dp0(n + 1, 0), new_dp1(n + 1, 0);
            for (int i = 0; i <= n; i++) {
                ll prev = 0;
                ll curr = 0;
                for (int x = 0; x < i; x++) 
                    curr += grid[x][j];
                for (int y = 0; y <= n; y++) {
                    if (y > 0 && y <= i) {
                        curr -= grid[y - 1][j];
                    }
                    if (y > i) {
                        prev += grid[y - 1][j - 1];
                    }
                    new_dp0[y] = max({new_dp0[y], prev + dp0[i], dp1[i]});
                    new_dp1[y] = max({new_dp1[y], curr + dp1[i], curr + prev + dp0[i]});
                }
            }
            dp0 = new_dp0;
            dp1 = new_dp1;
        }
        return *max_element(dp1.begin(), dp1.end());
    }
};
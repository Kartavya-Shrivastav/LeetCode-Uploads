#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of binary strings and two integers m and n, find the maximum number of strings that can be formed with at most m 0's and n 1's.
// Approach: Use dynamic programming to keep track of the maximum number of strings that can be formed with given counts of 0's and 1's.

// Steps:
// 1. Initialize a 2D DP array where dp[i][j] represents the maximum number of strings that can be formed with i 0's and j 1's.
// 2. Iterate through each string in the input array.
// 3. For each string, count the number of 0's and 1's.
// 4. Update the DP array in reverse order to avoid overwriting values that are yet to be processed.
// 5. Finally, return the value in dp[m][n] which represents the maximum number of strings that can be formed with m 0's and n 1's.

// Time Complexity: O(l * m * n) where l is the number of strings, m is the maximum number of 0's, and n is the maximum number of 1's.
// Space Complexity: O(m * n) for the DP array.

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (auto& s : strs) {
            int zeros = count(s.begin(), s.end(), '0');
            int ones = s.size() - zeros;
            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
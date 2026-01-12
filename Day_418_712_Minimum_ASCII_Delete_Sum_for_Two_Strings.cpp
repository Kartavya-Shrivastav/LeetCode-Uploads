#include <bits/stdc++.h>
using namespace std;

// Problem: 712. Minimum ASCII Delete Sum for Two Strings
// Approach: Dynamic Programming to find the minimum ASCII delete sum to make two strings equal.

// Steps:
// 1. Create a 2D DP array where dp[i][j] represents the minimum ASCII delete sum to make s1[0..i-1] and s2[0..j-1] equal.
// 2. Initialize the first row and first column based on the ASCII values of the characters.
// 3. Fill the DP table using the following logic:
//    - If characters match, carry forward the value from dp[i-1][j-1].
//    - If characters do not match, take the minimum of deleting a character from either string.
// 4. The value at dp[m][n] will be the result, where m and n are the lengths of s1 and s2 respectively.

// Time Complexity: O(m*n), where m and n are the lengths of the two strings.
// Space Complexity: O(m*n) for the DP table.

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));

        for (int i = 1; i <= m; ++i) 
            dp[i][0] = dp[i-1][0] + s1[i-1];
        for (int j = 1; j <= n; ++j) 
            dp[0][j] = dp[0][j-1] + s2[j-1];

        for (int i = 1; i <= m; ++i){
            for (int j = 1; j <= n; ++j){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] =  dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1]);
            }
        }
        return dp[m][n];
    }
};
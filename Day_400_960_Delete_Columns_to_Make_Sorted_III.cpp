
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Problem: Delete Columns to Make Sorted III
// Approach: Dynamic Programming to find the longest non-decreasing subsequence of columns

// Steps:
// 1. Use a DP array where dp[i] represents the length of the longest valid subsequence ending with column i.   
// 2. For each column i, check all previous columns j < i to see if adding column i maintains the non-decreasing order for all strings.
// 3. If valid, update dp[i] = max(dp[i], dp[j] + 1).
// 4. The answer is the total number of columns minus the length of the longest valid subsequence found in the DP array.
// 5. Return the result.

// Complexity:
// Time: O(n^2 * m) where n is number of columns and m is number of strings
// Space: O(n) for the DP array


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = (int)strs[0].size();
        int m = (int)strs.size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                bool ok = true;
                for (int r = 0; r < m; r++) {
                    if (strs[r][j] > strs[r][i]) { ok = false; break; }
                }
                if (ok) dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        int mx = 0;
        for (int v : dp) mx = max(mx, v);
        return n - mx;
    }
};
#include <bits/stdc++.h>
using namespace std;

// Problem: 1458. Max Dot Product of Two Subsequences
// Approach: We use a recursive dynamic programming approach with memoization to explore all possible subsequences

// Steps:
// 1. Define a recursive function `dp(i, j)` that computes the maximum dot product starting from indices `i` in `nums1` and `j` in `nums2`.
// 2. At each step, we have the option to take the product of `nums1[i]` and `nums2[j]` and either continue or end the subsequence, or skip one of the elements.
// 3. Use memoization to store already computed results for pairs `(i, j)`.
// 4. The base case is when we reach the end of either array, returning a very negative number to indicate no valid subsequence can be formed.
// 5. Finally, return the result of `dp(0, 0)` which gives the maximum dot product for the entire arrays.

// Time Complexity: O(n * m), where n and m are the lengths of nums1 and nums2 respectively, as we compute each state once.
// Space Complexity: O(n * m) for the memoization table.

class Solution {
public:
    vector<int> nums1, nums2;
    vector<vector<int>> memo;
    int n, m;
    const int NEG_INF = -1e9;

    int dp(int i, int j) {
        if (i == n || j == m)
            return NEG_INF;

        if (memo[i][j] != INT_MIN)
            return memo[i][j];

        int take = nums1[i] * nums2[j];

        int res = max({
            take + dp(i + 1, j + 1), // take both and continue
            take,                   // take and end here
            dp(i + 1, j),            // skip nums1[i]
            dp(i, j + 1)             // skip nums2[j]
        });

        return memo[i][j] = res;
    }

    int maxDotProduct(vector<int>& a, vector<int>& b) {
        nums1 = a;
        nums2 = b;
        n = nums1.size();
        m = nums2.size();

        memo.assign(n, vector<int>(m, INT_MIN));
        return dp(0, 0);
    }
};
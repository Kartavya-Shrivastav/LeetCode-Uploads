#include <bits/stdc++.h>
using namespace std;

/*
Problems: Find the number of stable binary arrays of length zero + one with exactly zero 0s and one 1s, where no more than limit consecutive elements are the same.
Approach:   
1. We can use dynamic programming to solve this problem. We will define a 3D DP array dp[i][j][k] where:
   - i: number of 0s used
   - j: number of 1s used
   - k: the last element added (0 or 1)
   The value of dp[i][j][k] will represent the number of ways to form a stable binary array using i 0s and j 1s, ending with the element k.
2. We will initialize the base cases for dp when we have only 0s or only 1s, ensuring that we do not exceed the limit of consecutive elements.
3. We will fill the DP table iteratively, ensuring that we do not add more than limit consecutive elements of the same type.
4. Finally, the answer will be the sum of dp[zero][one][0] and dp[zero][one][1], which will give us the total number of stable binary arrays of the required length and composition.    

// Time Complexity: O(zero * one) due to the nested loops filling the DP table.
// Space Complexity: O(zero * one) for the DP table.
*/

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;
        vector<vector<array<long,2>>> dp(
            zero+1, vector<array<long,2>>(one+1, {0LL,0LL}));

        for (int i = 1; i <= min(zero,limit); i++) dp[i][0][0] = 1;
        for (int j = 1; j <= min(one, limit); j++) dp[0][j][1] = 1;

        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                long over0 = (i-limit >= 1) ? dp[i-limit-1][j][1] : 0;
                long over1 = (j-limit >= 1) ? dp[i][j-limit-1][0] : 0;
                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1] - over0 + MOD) % MOD;
                dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1] - over1 + MOD) % MOD;
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};
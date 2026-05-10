#include <bits/stdc++.h>
using namespace std;

/*
Problem: You are given a 0-indexed integer array nums and an integer target. You are initially positioned at index 0. In one jump, you can jump from index i to index j if the following conditions are fulfilled:
- 0 <= i < j < nums.length
- abs(nums[i] - nums[j]) <= target

Approach: We can solve this problem using dynamic programming. We will create a dp array where dp[i] represents the maximum number of jumps required to reach index i. We will initialize the dp array with -1, indicating that the index is not reachable, except for dp[0] which will be set to 0 since we are already at the starting position. We will then iterate through the nums array and for each index i, we will check all previous indices j (where j < i) to see if we can jump from index j to index i based on the given conditions. If we can jump, we will update dp[i] to be the maximum of its current value and 1 + dp[j], which represents one jump from index j plus the jumps required to reach index j.

Steps:
1. Initialize a dp array of the same length as nums with all values set to -1, except for dp[0] which is set to 0.
2. Iterate through the nums array starting from index 1 to n-1 (where n is the length of nums).
3. For each index i, iterate through all previous indices j (where j < i) and check if the absolute difference between nums[i] and nums[j] is less than or equal to target and if dp[j] is not -1 (indicating that index j is reachable).
4. If the conditions are satisfied, update dp[i] to be the maximum of its current value and 1 + dp[j].
5. Finally, return the value at dp[n-1], which represents the maximum number of jumps required to reach the last index. If dp[n-1] is still -1, it means the last index is not reachable, and we can return -1.

Time Complexity: O(n^2), where n is the length of the nums array, since we are using two nested loops to fill the dp array.
Space Complexity: O(n), since we are using a dp array of the same length as nums to store the maximum number of jumps required to reach each index.
*/


class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        // dp array to store max jumps till index i
        vector<int> dp(n, -1);

        // First index is reachable with 0 jumps
        dp[0]=0;

        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                // Check if the condition holds true and prev index was visited
                if(abs(nums[i]-nums[j]) <= target && dp[j]>-1) {
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
        }

        return dp[n-1];
    }
};
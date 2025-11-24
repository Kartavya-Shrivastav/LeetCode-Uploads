#include <bits/stdc++.h>
using namespace std;

// Problem: Greatest Sum Divisible by Three
// Approach: Dynamic Programming with Modulo States

// Steps:
// 1. Initialize a DP array to keep track of maximum sums for each modulo state (0, 1, 2).
// 2. Iterate through each number in the input array.
// 3. For each number, update the DP states based on the current number's modulo with 3.
// 4. The result will be the maximum sum that is divisible by 3, which is stored in dp[0].

// Time Complexity: O(n) where n is the number of elements in the array
// Space Complexity: O(1) since we are using a fixed amount of extra space

class Solution {
public:
    static int maxSumDivThree(vector<int>& nums) {
        const int n=nums.size(), minus=-1e9;
        int dp[2][3]={ {0, 0, 0}, {0, minus, minus}};
        for(int i=0; i<n; i++){
            const int x=nums[i];
            for(int mod=0; mod<3; mod++){
                int modPrev=mod-x%3; modPrev+=(-(modPrev<0)) & 3;
                const int take=x+dp[(i+1)&1][modPrev];
                const int skip=dp[(i+1)&1][mod];
                dp[i&1][mod]=max(take, skip);
            }
        }
        return max(0, dp[(n-1)&1][0]);
    }
};
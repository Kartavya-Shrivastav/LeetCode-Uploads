#include <bits/stdc++.h>
using namespace std;

// Problem: Given n days, a person shares a secret starting from 'delay' days after learning it and forgets it after 'forget' days. Find how many people know the secret on the nth day.
// Approach: Use dynamic programming to track the number of people who learn the secret each day and adjust for those who forget it.

// Steps:
// 1. Create a dp array where dp[i] represents the number of people who learn the secret on day i.
// 2. Initialize dp[1] = 1 since one person knows the secret on day 1.
// 3. For each day from 2 to n, calculate the number of new people who learn the secret based on those who can share it (i.e., those who learned it 'delay' days ago) and subtract those who forget it (i.e., those who learned it 'forget' days ago).
// 4. Finally, sum up the number of people who still remember the secret on day n (i.e., those who learned it from day n-forget+1 to day n).

// Time Complexity: O(n) since we iterate through each day up to n.
// Space Complexity: O(n) for the dp array.

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        long long share = 0, MOD = 1000000007;
        for (int t = 2; t <= n; t++) {
            if (t - delay > 0)
                share = (share + dp[t - delay] + MOD) % MOD;
            if (t - forget > 0)
                share = (share - dp[t - forget] + MOD) % MOD;
            dp[t] = share;
        }
        long long know = 0;
        for (int i = n - forget + 1; i <= n; i++)
            know = (know + dp[i]) % MOD;
        return (int)know;
    }
};
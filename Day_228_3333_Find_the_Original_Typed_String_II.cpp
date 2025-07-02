#include<bits/stdc++.h>
using namespace std;

// Problem: Given a string `word` and an integer `k`, return the number of possible original strings that could have been typed to produce `word` with at most `k` adjacent characters being the same.
// Approach: The number of possible original strings is determined by the number of groups of adjacent characters in `word`. We can use dynamic programming to count the valid combinations while ensuring that no more than `k` adjacent characters are the same.

// Steps:
// 1. Count the groups of adjacent characters in `word`.
// 2. Calculate the total number of combinations of these groups.
// 3. Use dynamic programming to count the valid combinations while respecting the constraint of `k`.
// 4. Return the total count of valid combinations modulo 1e9 + 7.

// Time Complexity: O(n * k), where n is the length of the string and k is the maximum number of adjacent characters allowed.
// Space Complexity: O(k), for the dynamic programming array.

class Solution {
public:
    const int MOD = 1e9 + 7;

    // Returns the number of possible original strings that could have produced `word`
    // with at most `k` adjacent characters being the same.
    int possibleStringCount(string word, int k) {
        if (word.empty()) return 0;

        vector<int> groups; // Stores the lengths of consecutive character groups
        int count = 1;

        // Count the size of each group of consecutive same characters
        for (int i = 1; i < word.size(); i++) {
            if (word[i] == word[i - 1])
                count++;
            else {
                groups.push_back(count);
                count = 1;
            }
        }
        groups.push_back(count); // Add the last group

        long total = 1;
        // Multiply the sizes of all groups to get the total combinations
        for (int g : groups)
            total = (total * g) % MOD;

        // If k is less than or equal to the number of groups, return total
        if (k <= groups.size()) return total;

        // Dynamic programming to count invalid combinations (with more than k adjacent same chars)
        vector<int> dp(k, 0);
        dp[0] = 1;

        for (int g : groups) {
            vector<int> new_dp(k, 0);
            long sum = 0;
            for (int s = 0; s < k; s++) {
                if (s > 0)
                    sum = (sum + dp[s - 1]) % MOD;
                if (s > g)
                    sum = (sum - dp[s - g - 1] + MOD) % MOD;
                new_dp[s] = sum;
            }
            dp = new_dp;
        }

        // Count the number of invalid combinations
        long invalid = 0;
        for (int s = groups.size(); s < k; s++)
            invalid = (invalid + dp[s]) % MOD;

        // Subtract invalid from total and return the result modulo MOD
        return (total - invalid + MOD) % MOD;
    }
};
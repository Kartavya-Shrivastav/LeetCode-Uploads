#include <bits/stdc++.h>
using namespace std;

// Problem: 3494. Find the Minimum Amount of Time to Brew Potions
// Approach: Dynamic Programming to calculate minimum time to brew all potions

// Steps:
// 1. Initialize a DP array where dp[i] represents the minimum time to brew the first i potions.
// 2. Iterate through each potion and for each potion, iterate through each spell.
// 3. Update the DP array by considering the time taken to brew the current potion with the current spell.
// 4. The time taken to brew a potion is the maximum of the time taken to brew the previous potions and the time taken to brew the current potion with the current spell.
// 5. Return the value in dp[n], which represents the minimum time to brew all potions.
// 6. Return the minimum time to brew all potions.

// Time Complexity: O(n * m), where n is the number of potions and m is the number of spells.
// Space Complexity: O(n) for the DP array.

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> done(n + 1, 0);
        
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                done[i + 1] = max(done[i + 1], done[i]) + 1LL * mana[j] * skill[i];
            }
            for (int i = n - 1; i > 0; --i) {
                done[i] = done[i + 1] - 1LL * mana[j] * skill[i];
            }
        }
        
        return done[n];
    }
};
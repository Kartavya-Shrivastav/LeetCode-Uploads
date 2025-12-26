#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Penalty for a Shop
// Approach: Prefix Sum Calculation

// Steps:
// 1. Initialize variables to track the best closing time, minimum penalty, and prefix sum.
// 2. Iterate through each character in the customers string.
// 3. Update the prefix sum based on whether the customer is 'Y' (yes) or 'N' (no).
// 4. If the current prefix sum is less than the minimum penalty, update the best closing time and minimum penalty.
// 5. Return the best closing time.

// Complexity:
// Time: O(n) where n is the length of the customers string
// Space: O(1) additional space

class Solution {
public:
    int bestClosingTime(string customers) {
        int bestTime = 0;
        int minPenalty = 0;
        int prefix = 0;
        
        for (int i = 0; i < customers.length(); i++) {
            prefix += customers[i] == 'Y' ? -1 : 1;
            
            if (prefix < minPenalty) {
                bestTime = i + 1;
                minPenalty = prefix;
            }
        }
        
        return bestTime;
    }
};
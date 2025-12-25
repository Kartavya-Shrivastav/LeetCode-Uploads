#include <bits/stdc++.h>
using namespace std;

// Problem: Maximize Happiness of Selected Children
// Approach: Greedy Selection with Sorting

// Steps:
// 1. Sort the children's happiness values in descending order.
// 2. Iterate through the sorted list, selecting children for gifts.
// 3. For each selected child, calculate the happiness contribution as (happiness - turn).
// 4. Stop when the happiness contribution becomes non-positive.
// 5. Sum the positive contributions to get the maximum happiness sum.

// Complexity:
// Time: O(n log n) due to sorting the happiness values 
// Space: O(1) additional space

class Solution {
public:
    long long maximumHappinessSum(vector<int>& christmasJoy, int gifts) {
        // Santa gives gifts to the happiest children first
        sort(christmasJoy.begin(), christmasJoy.end(), greater<int>());
        
        long long totalJoy = 0;
        for (int turn = 0; turn < gifts; ++turn) {
            int currentJoy = christmasJoy[turn] - turn;
            if (currentJoy <= 0)
                break;
            totalJoy += currentJoy;
        }
        
        return totalJoy;
    }
};
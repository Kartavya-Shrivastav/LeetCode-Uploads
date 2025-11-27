#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum Subarray Sum With Length Divisible by K
// Approach: Prefix Sums with Modular Arithmetic

// Steps:
// 1. Initialize a prefix sum variable and a variable to track the maximum subarray sum.
// 2. Create a vector to store the minimum prefix sums for each modulo class.
// 3. Iterate through the array, updating the prefix sum and checking for potential maximum subarray sums.
// 4. Update the minimum prefix sum for the current modulo class.
// 5. Return the maximum subarray sum found.

// Time Complexity: O(n)
// Space Complexity: O(k) due to the vector storing minimum prefix sums for each modulo class


using ll = long long;
class Solution {
public:
    ll maxSubarraySum(vector<int>& nums, int k) {       
        ll prefSum = 0;
        ll subMax = LLONG_MIN;
        vector<ll> minSoFar(k, LLONG_MAX / 2);
        minSoFar[(k - 1) % k] = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefSum += nums[i];
            subMax = max(subMax, prefSum - minSoFar[i % k]);
            minSoFar[i % k] = min(minSoFar[i % k], prefSum);
        }

        return subMax;
    }
};

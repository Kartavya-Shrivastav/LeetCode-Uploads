#include <bits/stdc++.h>
using namespace std;

// Problem: Make Sum Divisible by P
// Approach: Prefix Sum with Hash Map

// Steps:
// 1. Calculate the total sum of the array and determine the target remainder when divided by p.
// 2. If the total sum is already divisible by p, return 0.
// 3. Use a hash map to store the earliest occurrence of each prefix sum modulo p.
// 4. Iterate through the array, updating the prefix sum and checking if there exists a previous prefix sum that can form a subarray with the required remainder.
// 5. Update the minimum length of such a subarray found during the iteration.
// 6. Return the minimum length found, or -1 if no such subarray exists.

// Time Complexity: O(n) where n is the number of elements in the array
// Space Complexity: O(n) for the hash map storing prefix sums

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long total = 0;
        for (int x : nums) total += x;

        long target = total % p;
        if (target == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        long prefix = 0;
        int res = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i]) % p;
            int need = (prefix - target + p) % p;

            if (mp.count(need))
                res = min(res, i - mp[need]);

            mp[(int)prefix] = i;
        }

        return res == nums.size() ? -1 : res;
    }
};
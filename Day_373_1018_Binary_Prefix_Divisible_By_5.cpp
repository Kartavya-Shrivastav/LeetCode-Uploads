#include <bits/stdc++.h>
using namespace std;

// Problem: Binary Prefix Divisible By 5
// Approach: Iterative Prefix Calculation with Modulo

// Steps:
// 1. Initialize a variable to keep track of the current prefix value modulo 5.
// 2. Iterate through each bit in the input array.
// 3. For each bit, update the prefix value by shifting left (multiplying by 2) and adding the current bit, then take modulo 5.
// 4. Check if the current prefix value is divisible by 5 and store the result.
// 5. Return the result array containing boolean values for each prefix.

// Time Complexity: O(n) where n is the number of bits in the input array
// Space Complexity: O(n) for storing the result array

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int val = 0;
        vector<bool> res;

        for (auto& n : nums) {
            val = ((val << 1) + n) % 5;
            res.push_back(val == 0);
        }

        return res;
    }
};

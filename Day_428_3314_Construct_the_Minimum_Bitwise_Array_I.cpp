#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array 'nums', construct a new array where for each odd element in 'nums', we replace it with the result of clearing its least significant set bit, and for each even element, we replace it with -1.
// Approach: We will iterate through each element in the input array. For odd elements, we will compute the value by identifying the least significant set bit and clearing it. For even elements, we will directly append -1 to the result array.

// Steps:
// 1. Initialize an empty result array.
// 2. Iterate through each element in the input array 'nums'.
// 3. For each odd element, compute the value by clearing its least significant set bit.
// 4. For each even element, append -1 to the result array.
// 5. Return the result array.

// Time Complexity: O(n), where n is the number of elements in the input array, as we process each element once.
// Space Complexity: O(n), for storing the result array.

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for (auto& n : nums) {
            if (n & 1) {
                auto z = ((n + 1) & ~n) >> 1;
                res.push_back(n & ~z);
            } else
                res.push_back(-1);
        }
        return res;
    }
};
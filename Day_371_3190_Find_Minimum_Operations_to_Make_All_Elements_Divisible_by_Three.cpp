#include <bits/stdc++.h>
using namespace std;

// Problem: Find Minimum Operations to Make All Elements Divisible by Three
// Approach: Simple Iteration and Modulo Check

// Steps:
// 1. Initialize a counter to zero. 
// 2. Iterate through each element and check if it is not divisible by 3.
// 3. If it is not divisible, increment the counter.
// 4. Return the counter as the result.

// Time Complexity: O(n) where n is the number of elements in the array
// Space Complexity: O(1) since we are using only a constant amount of extra space

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            if (num % 3 != 0) res++;
        }
        return res;
    }
};
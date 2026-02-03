#include <bits/stdc++.h>
using namespace std;

// Problem Statement: A trionic array is defined as an array that first strictly increases, then strictly decreases, and finally strictly increases again.
// Given an array of integers, determine if it is a trionic array.  

// Approach: We can use a three-phase approach to validate the trionic property of the array.

// Steps:
// 1. Traverse the array from the start to find the first increasing sequence.
// 2. Once the increasing sequence ends, check for a strictly decreasing sequence.
// 3. After the decreasing sequence ends, check for a final strictly increasing sequence.
// 4. Ensure that each phase has at least one element and that the entire array is covered by these three phases.
// 5. If all conditions are met, return true; otherwise, return false.

// Time Complexity: O(N), where N is the number of elements in the array, as we traverse the array at most once.
// Space Complexity: O(1), as we use a constant amount of extra space.

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size(), i = 0;
        // Phase 1: Up
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
        if (i == 0 || i == n - 1) return false;
        
        int p = i;
        // Phase 2: Down
        while (i + 1 < n && nums[i] > nums[i + 1]) i++;
        if (i == p || i == n - 1) return false;
        
        // Phase 3: Up
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
        return i == n - 1;
    }
};   
#include <bits/stdc++.h>
using namespace std;

// Problem: Given a binary array nums and an integer k, return true if all 1's are at least length k places away from each other.
// Approach: Iterate through the array, tracking the index of the last seen '1' and checking the distance to the current '1'.

// Steps:
// 1. Initialize a variable to store the index of the last seen '1' and a flag to indicate the first '1'.
// 2. Traverse the array, updating the index and checking distances as needed.
// 3. Return true if all '1's are at least k places apart, otherwise return false.

// Time Complexity: O(n) where n is the length of the array.
// Space Complexity: O(1) as we are using only a few extra variables.

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {

        int n = nums.size();
        int pre_index;
        bool f = true;

        for (int i = 0; i < n; i++) {
            if (f && nums[i] == 1) {
                f = false;
                pre_index = i;
                continue;
            }
            if (nums[i] == 1) {
                if (i - pre_index - 1 >= k)
                    pre_index = i;
                else
                    return false;
            }
        }

        return true;
    }
};
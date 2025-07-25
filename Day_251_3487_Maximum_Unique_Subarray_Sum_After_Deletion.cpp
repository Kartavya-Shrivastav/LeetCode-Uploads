#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array of integers, find the maximum sum of a subarray after deleting at most one element.
// Approach: Use a set to track unique elements and calculate the sum of positive elements.

// Steps:
// 1. Check if all elements are negative; if so, return the maximum element.
// 2. Use a set to store unique elements from the array.
// 3. Iterate through the set and sum up all positive elements.
// 4. Return the calculated sum.

// Time Complexity: O(N), where N is the number of elements in the array.
// Space Complexity: O(N), for storing unique elements in the set.

class Solution {
public:
    int maxSum(vector<int>& nums) {
        bool allNegative = true;
        int maxVal = INT_MIN;

        for (int n : nums) {
            if (n >= 0) allNegative = false;
            if (n > maxVal) maxVal = n;
        }
        if (allNegative) return maxVal;

        unordered_set<int> unique(nums.begin(), nums.end());

        int sum = 0;
        for (int val : unique) {
            if (val > 0) sum += val;
        }

        return sum;
    }
};

#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of integers, find the maximum difference between two elements such that the larger element comes after the smaller one.
// Approach: Use two pointers to traverse the array from both ends, keeping track of the minimum and maximum values seen so far, and calculate the maximum difference.

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxD = -1;           // Stores the maximum difference found
        int xMinL = 1e9;         // Tracks the minimum value from the left
        int xMaxR = -1;          // Tracks the maximum value from the right
        for (int l = 0, r = n - 1; l < r; l++) {
            xMinL = min(nums[l], xMinL); // Update minimum from the left
            // Move left pointer forward while the sequence is increasing
            while (l < r && nums[l + 1] > nums[l]) {
                l++;
                maxD = max(maxD, nums[l] - xMinL); // Update max difference
            }
            xMaxR = max(nums[r], xMaxR); // Update maximum from the right
            // Move right pointer backward while the sequence is decreasing
            while (l < r && nums[r - 1] < nums[r]) {
                r--;
                maxD = max(maxD, nums[r] - xMaxR); // Update max difference
            }
            maxD = max(maxD, xMaxR - xMinL); // Update max difference with current min and max
        }
        // If no valid difference found, return -1
        return maxD == 0 ? -1 : maxD;
    }
};
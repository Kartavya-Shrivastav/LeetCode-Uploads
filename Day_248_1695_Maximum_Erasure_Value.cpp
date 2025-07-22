#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array of integers, find the maximum sum of a subarray with all unique elements.
// Approach: Use a sliding window technique to maintain a window of unique elements and calculate the maximum sum.

// Steps:
// 1. Initialize a set to keep track of unique elements and two pointers for the sliding
//    window (left and right).
// 2. Traverse the array with the right pointer, adding elements to the current sum.
// 3. If a duplicate element is found, move the left pointer to the right until the duplicate is removed.
// 4. Update the maximum sum whenever a new unique element is added to the current sum.

// Time Complexity: O(N), where N is the length of the array.
// Space Complexity: O(N), for storing unique elements in the set.

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;
        int left = 0;
        int currentSum = 0;
        int maxSum = 0;
        
        for (int right = 0; right < n; ++right) {
            while (seen.find(nums[right]) != seen.end()) {
                currentSum -= nums[left];
                seen.erase(nums[left]);
                ++left;
            }
            currentSum += nums[right];
            seen.insert(nums[right]);
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};
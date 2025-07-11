#include <bits/stdc++.h>
using namespace std;

// Problem: Partition an array into the minimum number of subarrays such that the maximum difference between the smallest and largest number in each subarray is at most k.
// Approach: Sort the array and then iterate through it, counting how many partitions are needed based on the difference condition.

// Steps:
// 1. Sort the array.
// 2. Initialize a counter for partitions and a variable to track the minimum value in the current partition.
// 3. Iterate through the sorted array, checking if the current number exceeds the minimum value plus k.
// 4. If it does, increment the partition counter and update the minimum value to the current number.
// 5. Return the total number of partitions.

// Time Complexity: O(n log n) for sorting, O(n) for the iteration, where n is the size of the array.
// Space Complexity: O(1) for the partition count and minimum value tracking.

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        // Sort the array to bring close values together
        ranges::sort(nums);

        int ans = 1; // At least one partition is needed
        int mn = nums[0]; // Minimum value in the current partition

        // Iterate through the sorted array
        for (int i = 1; i < nums.size(); ++i)
            // If the current number exceeds the allowed difference from mn
            if (mn + k < nums[i]) {
                ++ans; // Start a new partition
                mn = nums[i]; // Update mn to the new partition's minimum
            }

        return ans; // Return the total number of partitions
    }
};
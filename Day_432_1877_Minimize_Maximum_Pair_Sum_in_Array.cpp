#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of integers, pair the elements such that the maximum sum of any pair is minimized. Return this minimized maximum pair sum.
// Approach: The optimal strategy is to sort the array and pair the smallest element with the largest, the second smallest with the second largest, and so on. This ensures that the largest sums are kept as low as possible.

// Steps:
// 1. Sort the input array.
// 2. Initialize a variable to track the maximum pair sum.
// 3. Use two pointers: one starting at the beginning (smallest element) and the other at the end (largest element) of the sorted array.
// 4. Iterate through the array, pairing elements from the start and end, updating the maximum pair sum accordingly.
// 5. Return the maximum pair sum after all pairs have been considered.

// Time Complexity: O(n log n) due to the sorting step.
// Space Complexity: O(1) if the sorting is done in place, otherwise O(n) for the sorted copy.

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int n = nums.size();

        for (int i = 0; i < n >> 1; i++)
            res = max(res, nums[n - 1 - i] + nums[i]);

        return res;
    }
};
#include <bits/stdc++.h>
using namespace std;

// Problem: 1984. Minimum Difference Between Highest and Lowest of K Scores
// You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student. You are also given an integer k.
// Pick the scores of any k students from the array so that the difference between the highest and the lowest of the k scores is minimized.
//Return the minimum possible difference.

// Approach: Sort the array and use a sliding window of size k to find the minimum difference between the highest and lowest scores in each window.

// Steps:
// 1. Sort the input array nums.
// 2. Initialize a variable ans to store the minimum difference, set it to a large value (INT_MAX).
// 3. Iterate through the sorted array using a loop, where the loop variable i goes from 0 to n - k (inclusive).
// 4. For each iteration, calculate the difference between the element at index i + k - 1 and the element at index i.
// 5. Update ans with the minimum value between the current ans and the calculated difference.
// 6. After the loop, return ans as the result.

// Time Complexity: O(n log n) due to sorting the array.
// Space Complexity: O(1) if we ignore the space used for sorting.

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for (int i = 0; i + k - 1 < n; ++i) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
};
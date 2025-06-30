#include <bits/stdc++.h>
using namespace std;

// Problem: Longest Harmonious Subsequence
// Approach: Use two pointers to find the longest subsequence where the difference between the maximum and minimum is exactly 1.

// Steps:
// 1. Sort the input array to facilitate the two-pointer technique.
// 2. Initialize two pointers: one at the start (j) and one that iterates through the array (i).
// 3. For each element at index i, move the second pointer j until the difference between the elements at i and j is more than 1.
// 4. If the difference is exactly 1, calculate the length of the subsequence from j to i and update the maximum length found.
// 5. Return the maximum length of the harmonious subsequence found.

// Time Complexity: O(n log n) for sorting, where n is the size of the input array.
// Space Complexity: O(1) for the two pointers, as we are not using any additional data structures that grow with input size.

class Solution {
public:
    int findLHS(vector<int>& nums) {
        // Sort the array to bring equal and consecutive numbers together
        sort(nums.begin(), nums.end());
        int j = 0, maxLength = 0;

        // Iterate through the array with i as the right pointer
        for (int i = 0; i < nums.size(); ++i) {
            // Move the left pointer j forward if the difference is greater than 1
            while (nums[i] - nums[j] > 1) {
                ++j;
            }
            // If the difference is exactly 1, update the maximum length
            if (nums[i] - nums[j] == 1) {
                maxLength = max(maxLength, i - j + 1);
            }
        }
        // Return the length of the longest harmonious subsequence found
        return maxLength;
    }
};
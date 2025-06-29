#include <bits/stdc++.h>
using namespace std;

// Problem: Number of Subsequences That Satisfy the Given Sum Condition
// Approach: Use two pointers to find valid subsequences and calculate their count using precomputed powers of 2.

// Steps:
// 1. Sort the input array to facilitate the two-pointer technique.
// 2. Precompute powers of 2 up to the size of the array to quickly calculate the number of valid subsequences.
// 3. Initialize two pointers: one at the start (left) and one at the end (right) of the sorted array.
// 4. While the left pointer is less than or equal to the right pointer:
//    - If the sum of the elements at the left and right pointers is less than or equal to the target,
//      calculate the number of valid subsequences that can be formed with the elements between the left and right pointers.
//      This is done by using the precomputed powers of 2.
//    - If the sum exceeds the target, move the right pointer to the left to reduce the sum.
// 5. Return the total count of valid subsequences modulo 10^9 + 7.

// Time Complexity: O(n log n) for sorting, where n is the size of the input array.
// Space Complexity: O(n) for storing the precomputed powers of 2.

class Solution {
public:
    // Function to count the number of subsequences where the sum of the minimum and maximum is <= target
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7, n = nums.size();
        // Sort the array to use two-pointer technique
        sort(nums.begin(), nums.end());

        // Precompute powers of 2 up to n for subsequence counting
        vector<int> power(n, 1);
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % mod;
        }

        int left = 0, right = n - 1, result = 0;

        // Use two pointers to find valid subsequences
        while (left <= right) {
            // If the sum of the smallest and largest is within target
            if (nums[left] + nums[right] <= target) {
                // Add the number of subsequences between left and right
                result = (result + power[right - left]) % mod;
                ++left; // Move left pointer to the right
            } else {
                --right; // Move right pointer to the left to reduce sum
            }
        }
        return result; // Return the total count modulo 1e9+7
    }
};
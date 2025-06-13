#include <bits/stdc++.h>
using namespace std;
// This code minimizes the maximum difference of pairs in an array
// It uses a binary search approach to find the minimum possible maximum difference 
// between pairs formed from the sorted array elements

class Solution {
public:
    // Function to minimize the maximum difference among p pairs in the array
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0; // If no pairs needed, return 0
        sort(nums.begin(), nums.end()); // Sort the array to make pairing easier
        int n = nums.size();
        int left = 0, right = nums[n - 1] - nums[0]; // Possible range for max difference

        // Binary search for the minimum possible maximum difference
        while (left < right) {
            int mid = left + (right - left) / 2; // Current candidate for max difference
            int pairs = 0; // Count of valid pairs formed

            // Try to form as many pairs as possible with difference <= mid
            for (int i = 1; i < n; ++i) {
                if (mid >= nums[i] - nums[i - 1]) {
                    ++pairs; // Pair formed
                    ++i; // Skip the next element as it's already paired
                }
            }

            // If enough pairs can be formed, try a smaller max difference
            if (pairs >= p) right = mid;
            else left = mid + 1; // Otherwise, increase the allowed difference
        }
        return left; // The minimum possible maximum difference
    }
};
#include <bits/stdc++.h>
using namespace std;

// Problem: Kth Smallest Product of Two Sorted Arrays
// Approach: Use binary search to find the k-th smallest product of two sorted arrays.

// Steps:
// 1. Define a binary search range for the product, from -1e10 to 1e10.
// 2. For each mid value in the binary search, count how many products are less than or equal to mid.
// 3. If the count is less than k, move the left boundary up; otherwise, move the right boundary down.      
// 4. Continue until the left boundary meets the right boundary, which will be the k-th smallest product.       
// 5. Use a helper function to count the number of products less than or equal to a given target.
// 6. Handle the case where one of the arrays contains zero, as it can affect the product count.

// Time Complexity: O(n log m), where n is the size of nums1 and m is the size of nums2.
// Space Complexity: O(1) for the binary search and counting operations.

class Solution {
public:
    // Main function to find the k-th smallest product
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -1e10, right = 1e10;
        // Binary search for the answer in the product range
        while (left < right) {
            long long mid = left + (right - left) / 2;
            // Count how many products are <= mid
            if (countProducts(nums1, nums2, mid) < k) 
                left = mid + 1;
            else 
                right = mid;
        }
        return left;
    }

    // Helper function to count number of products <= target
    long long countProducts(vector<int>& nums1, vector<int>& nums2, long long target) {
        long long count = 0;
        for (int num1 : nums1) {
            // If num1 is zero, all products are zero
            if (num1 == 0) {
                if (target >= 0) count += nums2.size();
                continue;
            }

            int low = 0, high = nums2.size();
            // Binary search in nums2 for each num1
            while (low < high) {
                int mid = (low + high) / 2;
                long long prod = 1LL * num1 * nums2[mid];
                if (prod <= target) {
                    // For positive num1, move right; for negative, move left
                    if (num1 > 0) low = mid + 1;
                    else high = mid;
                } else {
                    // For positive num1, move left; for negative, move right
                    if (num1 > 0) high = mid;
                    else low = mid + 1;
                }
            }
            // Add the count for this num1
            count += (num1 > 0) ? low : (nums2.size() - low);
        }
        return count;
    }
};
#include <bits/stdc++.h>
using namespace std;

// Problem Statement: A trionic array is defined as an array that first strictly increases, then strictly decreases, and finally strictly increases again.
// Given an array of integers, find the maximum sum of elements that can form a trionic subarray.

// Approach: We can iterate through the array to identify potential trionic subarrays and calculate their sums. 
// Steps:
// 1. Iterate through the array to find segments that first increase, then decrease, and finally increase again.
// 2. For each valid trionic segment, calculate the sum of its elements.
// 3. Keep track of the maximum sum encountered during the iterations.
// 4. Return the maximum sum found.

// Time Complexity: O(N), where N is the number of elements in the array, as we traverse the array at most once.
// Space Complexity: O(1), as we use a constant amount of extra space.

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        long long res = -2e18;
        for (int i = 1; i < n - 2; ) {
            int a = i, b = i;
            long long net = nums[a];
            while (b + 1 < n && nums[b + 1] < nums[b]) {
                net += nums[++b];
            }
            if (b == a) { i++; continue; }
            int c = b;
            long long left = 0, right = 0, lx = -2e18, rx = -2e18;
            while (a - 1 >= 0 && nums[a - 1] < nums[a]) {
                left += nums[--a];
                lx = max(lx, left);
            }
            if (a == i) { i++; continue; }
            while (b + 1 < n && nums[b + 1] > nums[b]) {
                right += nums[++b];
                rx = max(rx, right);
            }
            if (b == c) { i++; continue; }
            res = max(res, lx + rx + net);
            i = b;
        }
        return res;
    }
};
#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of integers, find the minimum number of operations required to make all elements equal to 1.
// An operation consists of choosing a subarray and replacing it with its GCD (Greatest Common Divisor).

// Approach: First, count how many elements are already 1. If there are any, the answer is simply the size of the array minus this count.
// If there are no 1's, we need to find the shortest subarray with GCD equal to 1.
// We can do this by iterating through all possible subarrays, computing their GCD, and checking if it equals 1.


// Steps:
// 1. Count the number of elements that are already 1. If there are any, the answer is simply the size of the array minus this count.
// 2. If there are no 1's, we need to find the shortest subarray with GCD equal to 1.
// 3. Iterate through all possible subarrays, compute their GCD, and if it equals 1, update the result with the minimum length found.
// 4. The final result will be the length of the shortest subarray with GCD 1 plus the size of the array minus 1 (to account for the operations needed to convert the rest of the elements).

// Time Complexity: O(n^3) in the worst case due to the nested loops for subarray GCD calculation.
// Space Complexity: O(1) as we are using only a few extra variables.

class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int n = nums.size();
        int res = INT_MAX, cnt1 = 0;
        for (int i = 0; i < n; ++i)
            cnt1 += (nums[i] == 1);
        if (cnt1)
            return n - cnt1;
        for (int i = 0; i < n; ++i) {
            int g = nums[i];
            for (int j = i + 1; j < n; ++j) {
                g = __gcd(g, nums[j]);
                if (g == 1) {
                    res = min(res, j - i + n - 1);
                    break;
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
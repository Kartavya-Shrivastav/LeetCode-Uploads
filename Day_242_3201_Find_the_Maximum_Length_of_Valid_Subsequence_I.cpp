#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of integers, find the maximum length of a subsequence where the elements alternate between even and odd numbers.
// Approach: Use dynamic programming to keep track of the longest subsequence ending with an even or odd number.

// Steps:
// 1. Count the number of even and odd numbers in the array.
// 2. Use two variables to track the maximum length of subsequences ending with an even or odd number.
// 3. Iterate through the array, updating the lengths based on whether the current number is even or odd.
// 4. Return the maximum of the counts and the lengths of the subsequences.

// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as we are using a constant amount of space for the counters and lengths.

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int count_even = 0, count_odd = 0;
        for (int num : nums) {
            if (num % 2 == 0) count_even++;
            else count_odd++;
        }

        int even_dp = 0, odd_dp = 0;
        for (int num : nums) {
            if (num % 2 == 0)
                even_dp = max(even_dp, odd_dp + 1);
            else
                odd_dp = max(odd_dp, even_dp + 1);
        }

        return max({count_even, count_odd, even_dp, odd_dp});
    }
};
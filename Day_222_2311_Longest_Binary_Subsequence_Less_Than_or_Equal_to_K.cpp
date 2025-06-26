#include <bits/stdc++.h>
using namespace std;

// Problem: Longest Binary Subsequence Less Than or Equal to K
// Approach: Count the number of '0's and '1's in the string, and calculate the value of '1's from the end.

// Steps:
// 1. Count the number of '0's in the string.
// 2. Traverse the string from the end to the start, calculating the value of '1's as powers of 2.
// 3. If adding a '1' exceeds k, skip it.
// 4. Continue until all bits are processed or the power exceeds k.
// 5. Return the total count of '0's and valid '1's.

// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(1), as we are using a constant amount of extra space.


class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int zeros = 0, ones = 0;
        long long value = 0, pow = 1;

        for (char c : s) {
            if (c == '0') zeros++;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                if (value + pow > k) {
                    continue; // Skip this '1' as it would exceed k
                }
                value += pow;
                ones++;
            }
            pow <<= 1;
            if (pow > k) break; // Further bits would exceed k
        }

        return zeros + ones;
    }
};
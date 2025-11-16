#include <bits/stdc++.h>
using namespace std;

// Problem: Given a binary string s, return the number of substrings with all characters equal to '1'.
// Approach: Iterate through the string, counting consecutive '1's and calculating the number of substrings formed by these '1's.

// Steps:
// 1. Initialize a counter for consecutive '1's and a total count for substrings.
// 2. Traverse the string, updating the counter and total count accordingly.
// 3. Return the total count modulo 10^9 + 7.

// Time Complexity: O(n) where n is the length of the string.
// Space Complexity: O(1) as we are using only a few extra variables.

class Solution {
public:
    int numSub(string s) {
        int cnt = 0, total = 0, mod = 1e9 + 7;
        for (char a : s) {
            if (a == '1') {
                cnt++;
            } else {
                cnt = 0;
            }
            total = (total + cnt) % mod;
        }
        return total;
    }
};
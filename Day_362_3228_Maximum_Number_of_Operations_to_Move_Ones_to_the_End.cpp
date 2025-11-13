#include <bits/stdc++.h>
using namespace std;

// Problem: Given a binary string, find the maximum number of operations to move all '1's to the end of the string.
// An operation consists of choosing an index i such that s[i] = '0' and s[i-1] = '1', and swapping s[i] and s[i-1].

// Approach: Iterate through the string while counting the number of '1's encountered so far.
// Each time a '0' is encountered, the number of '1's counted so far indicates how many swaps can be made to move those '1's past this '0'.

// Steps:
// 1. Initialize a counter for '1's and a result variable to store the number of operations.
// 2. Loop through each character in the string.
// 3. If the character is '1', increment the '1's counter.
// 4. If the character is '0' and the previous character was '1', add the count of '1's to the result.
// 5. Return the result after processing the entire string.

// Time Complexity: O(n) where n is the length of the string.
// Space Complexity: O(1) as we are using only a few extra variables.

class Solution {
public:
    int maxOperations(string s) {
        int ones = 0, res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1')
                ones++;
            else if ((i > 0) && s[i - 1] == '1')
                res += ones;
        }

        return res;
    }
};  
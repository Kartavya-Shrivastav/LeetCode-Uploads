#include <bits/stdc++.h>
using namespace std;

// Problem: Given two binary strings, return their sum (also a binary string). The input strings are both non-empty and contain only characters '1' or '0'.
// Approach: We can simulate the addition process similar to how we would add two numbers manually. We start from the least significant bit (the end of the strings) and add corresponding bits along with any carry from the previous addition. We continue this process until we have processed all bits from both strings and any remaining carry. Finally, we reverse the result string to get the correct order of the binary sum.

// Steps:
// 1. Initialize an empty result string and a carry variable set to 0.  
// 2. Use two pointers to iterate through the binary strings from the end to the beginning.
// 3. For each pair of bits (and the carry), calculate the sum and determine the resulting bit and the new carry.
// 4. Append the resulting bit to the result string.
// 5. After processing all bits and the carry, reverse the result string to get the final binary sum.
// 6. Handle edge cases where one string is shorter than the other by treating missing bits as '0'.

// Time Complexity: O(max(n, m)) where n and m are the lengths of the two binary strings, since we need to process each bit.
// Space Complexity: O(max(n, m)) for the result string that holds the sum of the two binary strings.

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) carry += a[i--] - '0';
            if (j >= 0) carry += b[j--] - '0';

            res += carry % 2 + '0';
            carry /= 2;
        }

        reverse(begin(res), end(res));
        return res;        
    }
};
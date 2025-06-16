#include <bits/stdc++.h>
using namespace std;
// Problem: Given two binary strings a and b, return their sum as a binary string.
// Approach: Use two pointers to traverse both strings from the end, keeping track of carry, and build the result string in reverse order.

class Solution {
public:
    // Function to add two binary strings and return the result as a binary string
    string addBinary(string a, string b) {
        string res; // Resultant binary string
        int carry = 0; // Initialize carry to 0
        int i = a.length() - 1; // Pointer for string a (from end)
        int j = b.length() - 1; // Pointer for string b (from end)

        // Loop until both strings are processed and no carry remains
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) carry += a[i--] - '0'; // Add bit from a if available
            if (j >= 0) carry += b[j--] - '0'; // Add bit from b if available

            res += carry % 2 + '0'; // Append current bit to result
            carry /= 2; // Update carry for next iteration
        }

        reverse(begin(res), end(res)); // Reverse the result to get correct order
        return res;        
    }
};
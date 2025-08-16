#include <bits/stdc++.h>
using namespace std;

// Problem: Maximize a number by changing at most one '6' to '9'
// Approach: Convert the number to a string, replace the first occurrence of '6' with '9', and convert it back to integer

// Steps:
// 1. Convert the integer to its string representation.
// 2. Iterate through the string to find the first digit '6'.
// 3. Replace that '6' with '9'.
// 4. Convert the modified string back to an integer.
// 5. If no '6' is found, return the original number as it is already maximal.

// Time Complexity: O(d) — where d is the number of digits in the input number, since we scan through the digits once.
// Space Complexity: O(d) — for storing the string representation of the number.

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        while (n % 4 == 0) n /= 4;
        return n == 1;
    }
};
#include <bits/stdc++.h>
using namespace std;

// Problem: Power of Two
// Approach: Use bit manipulation to determine if a number is a power of two.

// Steps:
// 1. Check if the number is greater than zero.
// 2. Use the property that a power of two has only one bit set in its binary representation.
// 3. The expression (n & (n - 1)) will be zero if n is a power of two, since it clears the lowest set bit.
// 4. Return true if both conditions are satisfied, otherwise return false.

// Time Complexity: O(1) since it involves a constant number of operations.
// Space Complexity: O(1) as no additional space is used.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && (n & n-1) == 0 ;
    }
};
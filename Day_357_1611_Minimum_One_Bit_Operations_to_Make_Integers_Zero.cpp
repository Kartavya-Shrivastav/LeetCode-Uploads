#include <iostream>
using namespace std;

// Problem: Given an integer n, find the minimum number of operations required to convert n to 0 using only the allowed operation of flipping the rightmost set bit.
// Approach: Use bit manipulation to determine the minimum operations by leveraging the properties of Gray codes.

// Steps:
// 1. Initialize a result variable to 0.
// 2. While n is not zero, XOR the result with n and right shift n by 1.
// 3. Return the result as the minimum number of operations.

// Time Complexity: O(log n) where n is the input integer.
// Space Complexity: O(1) for the result variable.

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int res = 0;
        while (n) {
            res ^= n;
            n >>= 1;
        }
        return res;
    }
};
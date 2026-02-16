#include <bits/stdc++.h>
using namespace std;

// Problem: Reverse bits of a given 32 bits unsigned integer.
// Approach: We can iterate through each bit of the input number, starting from the least significant bit. For each bit, we shift the result to the left to make room for the new bit, then we add the current bit of the input number to the result. After processing all 32 bits, we will have the reversed bits in the result variable.

// Steps:
// 1. Initialize a result variable to 0.
// 2. Loop through each of the 32 bits of the input number.
// 3. In each iteration, shift the result to the left by 1 to make room for the new bit.
// 4. Add the least significant bit of the input number to the result using bitwise OR.
// 5. Shift the input number to the right by 1 to process the next bit in the next iteration.
// 6. After the loop, return the result which now contains the reversed bits.

// Time Complexity: O(1) since we are always processing a fixed number of bits (32).
// Space Complexity: O(1) since we are using a constant amount of space for the result variable.

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            res <<= 1;
            res |= (n & 1);
            n >>= 1;
        }
        return res;
    }
};
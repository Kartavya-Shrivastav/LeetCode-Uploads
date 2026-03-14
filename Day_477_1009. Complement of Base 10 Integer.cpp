#include <bits/stdc++.h>
using namespace std;

/*
Problems: Given a positive integer n, return its complement. The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.
Approach:
1. We can find the complement of the integer by first creating a mask that has all bits set to 1 up to the most 
significant bit of n. This can be done by starting with a mask equal to n and repeatedly right-shifting it until it 
becomes 0, while also left-shifting a separate variable to keep track of the position of the bits.

2. Once we have the mask, we can simply XOR n with the mask to get the complement. The XOR operation will flip all the 
bits of n where the mask has a bit set to 1, effectively giving us the complement.   

Time Complexity: O(log n) due to the right-shifting of the mask.
Space Complexity: O(1) as we are using a constant amount of space.
*/

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int mask = n;
        for (int i = 0; i <= 4; i++)
            mask |= mask >> (1 << i);
        return ~n & mask;
    }
};
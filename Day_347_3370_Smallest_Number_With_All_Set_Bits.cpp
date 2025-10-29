#include <bits/stdc++.h>
using namespace std;

// Program to find the smallest number with all set bits for a given n
// Approach: Use bit_ceil to find the next power of two greater than n, then subtract 1

// Steps:
// 1. Increment n by 1 to find the next power of two
// 2. Use bit_ceil to get the smallest power of two greater than or equal to n+1
// 3. Subtract 1 from the result to get a number with all bits set

// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    int smallestNumber(unsigned n) {
        return bit_ceil(n+1)-1;
    }
};
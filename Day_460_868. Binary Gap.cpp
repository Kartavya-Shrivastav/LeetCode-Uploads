#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a positive integer n, return the longest distance between two consecutive 1's in the binary representation of n. If there are no two consecutive 1's, return 0.
Approach: We can use bit manipulation to solve this problem. We can right shift the number until we find the first 1, and then keep counting the number of zeros until we find the next 1. We can keep track of the maximum gap between two 1's.

Steps:
1. Right shift n until we find the first 1 (this will ignore any trailing zeros).
2. If n becomes 1 after the right shift, it means there is only one 1 in the binary representation, so we return 0.
3. Initialize two variables, maxGap and gap, to keep track of the maximum gap and the current gap between two 1's.
4. While n is not zero:
    a. If the least significant bit of n is 1, update maxGap with the maximum of maxGap and gap, and reset gap to 0.
    b. If the least significant bit of n is 0, increment the gap.
    c. Right shift n to check the next bit.
5. After the loop, return maxGap + 1 (since the gap counts the zeros between two 1's, we add 1 to get the distance).    

Time Complexity: O(log n) since we are right shifting the number until it becomes zero, which takes log n steps.
Space Complexity: O(1) since we are using only a constant amount of extra space.

*/

class Solution {
public:
    int binaryGap(int n) {
        n >>= __builtin_ctz(n);
        if (n == 1) return 0;
        int maxGap = 0, gap = 0;

        while (n) {
            if (n & 1) {
                maxGap = max(maxGap, gap);
                gap = 0;
            } else
                gap++;
            n >>= 1;
        }

        return maxGap + 1;
    }
};
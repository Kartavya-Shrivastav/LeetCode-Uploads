#include <iostream>
using namespace std;

// Problem: Smallest Integer Divisible by K
// Approach: Iterative Remainder Calculation

// Steps:
// 1. Check if k is divisible by 2 or 5, in which case return -1 since no number made up of only 1s can be divisible by these.
// 2. Initialize a variable to keep track of the current remainder when forming numbers made up of only 1s.
// 3. Iterate from 1 to k, updating the remainder by appending a '1' to the current number.
// 4. If at any point the remainder becomes 0, return the current length of the number.
// 5. If no such number is found within k iterations, return -1.

// Time Complexity: O(k) in the worst case
// Space Complexity: O(1) since we are using a fixed amount of extra space

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k == 1) return 1;

        // Numbers made of only 1s can never be divisible by 2 or 5
        if (k % 2 == 0 || k % 5 == 0) return -1;

        int rem = 0;
        for (int i = 1; i <= k; i++) {
            rem = (rem * 10 + 1) % k;
            if (rem == 0) return i;
        }
        return -1;
    }
};
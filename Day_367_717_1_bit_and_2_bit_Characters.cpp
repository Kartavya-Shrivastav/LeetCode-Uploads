#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of bits where each character is represented by either one bit (0) or two bits (10 or 11), determine if the last character is a one-bit character.
// Approach: Iterate through the bits array, using the value of each bit to determine how many bits to skip, and check if we end on the last bit as a one-bit character.

// Steps:
// 1. Initialize an index to traverse the bits array.
// 2. While the index is less than the second last index, increment the index by 1 if the current bit is 0, or by 2 if it is 1.
// 3. After the loop, check if the index is at the last position of the array.

// Time Complexity: O(n) where n is the length of the bits array.
// Space Complexity: O(1) as we are using only a few extra variables.

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;        
        while (i < n - 1)
            i += bits[i] + 1;

        return i == n - 1;
    }
};
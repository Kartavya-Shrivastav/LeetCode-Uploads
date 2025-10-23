#include <bits/stdc++.h>
using namespace std;

// Problem: Check If Digits Are Equal in String After Operations I
// Approach: Iteratively reduce the string by summing adjacent digits modulo 10 until only two digits remain, then check if they are equal.

// Steps:
// 1. Initialize an iteration counter to track the number of reductions.
// 2. While the length of the string minus the iteration counter is greater than 2:
//    a. For each character in the string up to the length minus the iteration counter:
//       i. Replace the character with the sum of itself and the next character modulo 10.
//    b. Increment the iteration counter.
// 3. After the loop, check if the first two characters of the reduced string are equal and return the result.

// Time Complexity: O(n^2) in the worst case due to repeated reductions
// Space Complexity: O(1) as we are modifying the string in place
class Solution {
public:
    bool hasSameDigits(string s) {
        int iteration = 0; // Tracks how many layers of reduction have been done

        // Continue reducing until only two digits remain
        while (s.size() - iteration != 2) {
            // Replace each character with the sum of adjacent digits (mod 10)
            for (int i = 0; i < s.size() - 1 - iteration; i++) {
                s[i] = ((s[i] - '0') + (s[i + 1] - '0')) % 10 + '0';
            }
            iteration++;
        }

        // Return true if the final two digits are equal
        return s[0] == s[1];
    }
};
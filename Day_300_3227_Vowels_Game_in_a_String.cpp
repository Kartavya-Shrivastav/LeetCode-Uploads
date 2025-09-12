#include <bits/stdc++.h>
using namespace std;

// Problem: Given a string consisting of lowercase letters, determine if Alice wins the game by checking if there is at least one vowel in the string.
// Approach: Use a bitmask to represent vowels and check if any character in the string is a vowel.

// Steps:
// 1. Define a bitmask where each bit represents a vowel (a, e, i, o, u).
// 2. Traverse the string and for each character, check if it is a vowel using the bitmask.
// 3. If a vowel is found, return true (Alice wins). If no vowels are found after checking all characters, return false (Bob wins).
// 4. Return the result.

// Time Complexity: O(n) where n is the length of the string.
// Space Complexity: O(1) since we are using a fixed amount of extra space.


class Solution {
public:
    bool doesAliceWin(string s) {
        for (int i = 0; i < s.size(); i++)
            if ((0x104111 >> (s[i] - 97)) & 1)
                return 1;                                
        return 0;
    }
};
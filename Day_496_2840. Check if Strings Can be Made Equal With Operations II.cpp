#include <bits/stdc++.h>    
using namespace std;

/*
Problem: Given two strings s1 and s2 of equal length, determine if it is possible to make the two strings equal by performing a series of operations. The allowed operation is to choose any even index i (0-based) in the string and swap the characters at indices i and i + 1. The goal is to check if we can transform s1 into s2 using these operations.
Approach: We can use a frequency array to count the occurrences of characters at even and odd indices separately for both strings. Since we can only swap characters at even indices, the characters at even indices in s1 must match the characters at even indices in s2, and similarly for odd indices. Therefore, we can maintain two separate frequency counts for even and odd indexed characters and compare them.

Steps:
1. Initialize a frequency array of size 52 (26 for lowercase letters at even indices and 26 for lowercase letters at odd indices).
2. Iterate through the characters of both strings simultaneously:
    a. For each character at index i in s1, determine if it is at an even or odd index and update the corresponding frequency count.
    b. For each character at index i in s2, determine if it is at an even or odd index and update the corresponding frequency count (decrementing for s2).
3. After processing both strings, check if all frequency counts are zero. If they are, it means that the characters at even and odd indices match between s1 and s2, and we can return true. Otherwise, return false.
4. Return true if all frequency counts are zero, indicating that the strings can be made equal, otherwise return false.

Time Complexity: O(n) where n is the length of the strings. We need to iterate through both strings once to populate the frequency array and then check the frequency counts.
Space Complexity: O(1) since the frequency array has a fixed size of 52, regardless of the input size.

*/

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int freq[52] = {};

        for (int i = 0; i < s1.length(); i++) {
            int off = (i & 1) * 26;
            freq[s1[i] - 'a' + off]++;
            freq[s2[i] - 'a' + off]--;
        }

        for (int i = 0; i < 52; i++)
            if (freq[i] != 0) return false;

        return true;
    }
};
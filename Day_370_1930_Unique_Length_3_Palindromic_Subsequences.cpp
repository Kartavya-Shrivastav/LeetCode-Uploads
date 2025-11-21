#include <bits/stdc++.h>
using namespace std;

// Problem: Unique Length 3 Palindromic Subsequences
// Approach: Character Indexing + Set

// Steps:
// 1. Iterate through each character from 'a' to 'z'.
// 2. For each character, find its first and last occurrence in the string.
// 3. Collect all unique characters that appear between these two occurrences.
// 4. The count of these unique characters gives the number of unique palindromic subsequences of length 3 for that character.
// 5. Sum these counts for all characters to get the final result.  

// Time Complexity: O(n) where n is the length of the string
// Space Complexity: O(1) since the size of the alphabet is constant (26 letters

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int countPaliSubseq = 0;

        for (char c = 'a'; c <= 'z'; ++c) {
            int firstIndex = s.find_first_of(c);
            int lastIndex = s.find_last_of(c);

            unordered_set<char> uniqueChars;

            for (int i = firstIndex + 1; i < lastIndex; ++i) {
               uniqueChars.insert(s[i]);
            }

            countPaliSubseq += uniqueChars.size();
        }

       return countPaliSubseq;    
    }
};
#include <bits/stdc++.h>
using namespace std;

// Problem: Given a string consisting of lowercase letters, find the sum of the frequencies of the most frequent vowel and the most frequent consonant.
// Approach: Use an array to count the frequency of each letter, then determine the maximum frequencies for vowels and consonants separately.

// Steps:
// 1. Initialize an array of size 26 to count the frequency of each letter.
// 2. Traverse the string and update the frequency count for each character.
// 3. Maintain two variables to track the maximum frequency of vowels and consonants.
// 4. Return the sum of the maximum vowel frequency and maximum consonant frequency.
// 5. If there are no vowels or no consonants, their respective maximum frequency will be 0.
// 6. Return the result.

// Time Complexity: O(n) where n is the length of the string.
// Space Complexity: O(1) since we are using a fixed amount of extra space.

class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26], maxVowel = 0, maxConso = 0;
        for (char c : s) {
            int i = c - 'a';
            freq[i]++;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                maxVowel = max(maxVowel, freq[i]);
            }
            else {
                maxConso = max(maxConso, freq[i]);
            }
        }
        return maxVowel + maxConso;
    }
};
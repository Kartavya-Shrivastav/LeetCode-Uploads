#include <bits/stdc++.h>
using namespace std;

// Problem: Check if a string is a valid word based on vowel and consonant rules
// Approach: Count the number of vowels and consonants in the string and check the conditions

// Steps:
// 1. Initialize counters for vowels and consonants.
// 2. Traverse the string character by character:
//    - If the character is a vowel, increment the vowel counter.
//    - If the character is a consonant, increment the consonant counter.
// 3. If the string contains any non-alphabetic characters, return false.
// 4. Check if there is at least one vowel and one consonant.
// 5. Return true if both conditions are met, otherwise return false.

// Time Complexity: O(n) where n is the length of the string.
// Space Complexity: O(1) since we are using a constant amount of space.

class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if (n < 3) return false;

        int vowels = 0, consonants = 0;
        string vowelList = "aeiouAEIOU";

        for (char c : s) {
            if (isalpha(c)) {
                if (vowelList.find(c) != string::npos) {
                    vowels++;
                } else {
                    consonants++;
                }
            } else if (!isdigit(c)) {
                return false; // invalid character
            }
        }

        return vowels >= 1 && consonants >= 1;
    }
};
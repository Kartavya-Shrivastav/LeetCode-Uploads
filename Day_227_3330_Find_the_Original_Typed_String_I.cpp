#include <bits/stdc++.h>
using namespace std;

// Problem: Given a string `word`, return the number of possible original strings that could have been typed to produce `word`.
// Approach: The number of possible original strings is equal to the length of the string minus the number of adjacent characters that are the same. This is because each time two adjacent characters are the same, it indicates that they could have been typed as a single character in the original string.

// Steps:
// 1. Initialize a count variable to the length of the string.
// 2. Iterate through the string from the second character to the end.
// 3. For each character, check if it is different from the previous character.
// 4. If it is different, decrement the count.
// 5. Return the count as the result.

// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(1), as we are using a constant amount of extra space.

class Solution {
public:
    // Function to calculate the number of possible original strings
    int possibleStringCount(string word) {
        int n = word.length(); // Get the length of the input string
        int count = n; // Initialize count to the length of the string

        // Iterate through the string starting from the second character
        for (int i = 1; i < n; i++) {
            // If the current character is different from the previous one
            if (word[i] != word[i - 1]) {
                count--; // Decrement count as this indicates a new character in the original string
            }
        }
        return count; // Return the final count
    }
};
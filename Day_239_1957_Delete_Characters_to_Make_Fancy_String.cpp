#include<bits/stdc++.h>
using namespace std;

// Problem Statement: Given a string, delete characters such that no character appears more than twice consecutively.
// Approach: Iterate through the string, maintaining a count of consecutive characters, and build a new
// string with the allowed number of consecutive characters.

// Steps:
// 1. Initialize a vector to hold characters from the input string.
// 2. Use a loop to traverse the string, counting consecutive occurrences of each character.
// 3. If a character appears more than twice consecutively, skip adding it to the result.
// 4. Construct the final string from the vector of characters.

// Time Complexity: O(N), where N is the length of the string.
// Space Complexity: O(N), for storing the characters in a vector.

class Solution {
public:
    string makeFancyString(string s) {
         vector<char> chars(s.begin(), s.end());
        char last = chars[0];
        int count = 1;
        int pos = 1;

        for (int i = 1; i < chars.size(); ++i) {
            if (chars[i] != last) {
                last = chars[i];
                count = 0;
            }

            if (++count > 2) continue;

            chars[pos++] = chars[i];
        }

        return string(chars.begin(), chars.begin() + pos);
    }
};
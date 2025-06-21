#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Deletions to Make String K-Special
// Approach: Count the frequency of each character and determine the minimum deletions needed to make the string k-special.

// Steps:
// 1. Count the frequency of each character in the string.
// 2. For each unique frequency, calculate the number of deletions required to make all characters have that frequency or less.
// 3. The minimum deletions across all unique frequencies is the answer.

// Time Complexity: O(n + 26^2), where n is the length of the string and 26 is the number of lowercase letters.
// Space Complexity: O(1), since we are using a fixed-size array for character counts.

class Solution {
public:
    int minimumDeletions(string word, int k) {
        int ans = INT_MAX;
        vector<int> count(26); // Count of each lowercase letter

        // Count frequency of each character in the string
        for (const char c : word)
            ++count[c - 'a'];

        // Try each possible minimum frequency as a target
        for (const int minFreq : count) {
            int deletions = 0;
            for (const int freq : count) {
                if (freq < minFreq)  // Delete all the letters with smaller frequency
                    deletions += freq;
                else  // Delete letters with exceeding frequency
                    deletions += max(0, freq - (minFreq + k));
            }
            ans = min(ans, deletions); // Update answer with the minimum deletions found
        }

        return ans;
    }
};

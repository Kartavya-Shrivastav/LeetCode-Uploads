#include <bits/stdc++.h>
using namespace std;
// This code defines a function to clear stars from a string and return the lexicographically smallest string
// by replacing stars with the last character in the corresponding bucket of characters.

class Solution {
public:
    // Function to remove stars and return the lexicographically smallest string
    string clearStars(string s) {
        string ans = s; // Copy of the input string to modify
        vector<vector<int>> buckets(26); // Buckets to store indices of each character

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '*') {
                ans[i] = ' '; // Mark the star for removal
                int j = 0;
                // Find the smallest character bucket that is not empty
                while (buckets[j].empty())
                    ++j;
                // Remove the last occurrence of the smallest character
                ans[buckets[j].back()] = ' ';
                buckets[j].pop_back();
            } else {
                // Store the index of the character in its corresponding bucket
                buckets[s[i] - 'a'].push_back(i);
            }
        }

        std::erase(ans, ' '); // Remove all marked characters (spaces)
        return ans; // Return the resulting string
    }
};
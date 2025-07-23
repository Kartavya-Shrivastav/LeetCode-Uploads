#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given a string, calculate the maximum score by removing "ab" or "ba" substrings based on given scores.
// Approach: Use a greedy strategy to remove the substrings with the highest score first.

// Steps:
// 1. Initialize variables to keep track of scores and counts of characters.
// 2. Iterate through the string, counting occurrences of 'a' and 'b'.
// 3. If the score for removing "ab" is greater than "ba", prioritize removing "ab" first, and vice versa.
// 4. Calculate the score based on the number of pairs removed.
// 5. Return the total score.

// Time Complexity: O(N), where N is the length of the string.
// Space Complexity: O(1), as we are using a constant amount of extra space.

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score = 0;
        char ch1 = 'a', ch2 = 'b';
        int cnt1 = 0, cnt2 = 0;

        if (x < y) {
            swap(x, y);
            ch1 = 'b';
            ch2 = 'a';
        }

        for (char ch : s) {
            if (ch == ch1) {
                cnt1++;
            } else if (ch == ch2) {
                if (cnt1 > 0) {
                    cnt1--;
                    score += x;
                } else {
                    cnt2++;
                }
            } else {
                score += min(cnt1, cnt2) * y;
                cnt1 = 0;
                cnt2 = 0;
            }
        }

        if (cnt1 != 0) {
            score += min(cnt1, cnt2) * y;
        }

        return score;
    }
};
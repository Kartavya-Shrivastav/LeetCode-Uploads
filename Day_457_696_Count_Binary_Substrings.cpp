#include <bits/stdc++.h>
using namespace std;

// Problem: Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 
//          1's in these substrings are grouped consecutively.
// Approach: We can use a two-pointer technique to count the number of valid substrings. We will keep track of the length of the current streak of 
//           characters (either '0' or '1') and the length of the previous streak. Whenever we encounter a change in character, we will update the previous streak length and reset the current streak length. If the current streak length is less than or equal to the previous streak length, it means we can form a valid substring by taking characters from both streaks.

// Steps:
// 1. Initialize a variable res to store the count of valid substrings, prev to store the length of the previous streak, and strk to store the length
//    of the current streak. Set res and prev to 0, and strk to 1.
// 2. Iterate through the string s starting from the second character (index 1).
// 3. For each character, check if it is the same as the previous character. If it is, increment the current streak length (strk). If it is different, 
//    update prev to the current streak length and reset strk to 1.
// 4. After updating the streak lengths, check if the current streak length is less than or equal to the previous streak length. If it is, increment
//    the result count (res) by 1, since we can form a valid substring using characters from both streaks.
// 5. After the loop, return the result count (res) which contains the number of valid substrings.

// Time Complexity: O(n) where n is the length of the input string s, since we are iterating through the string once.
// Space Complexity: O(1) since we are using only a constant amount of extra space for the variables.

class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0, prev = 0, strk = 1;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) strk++;
            else {
                prev = strk;
                strk = 1;
            }
            if (strk <= prev) res++;
        }
        return res;
    }
};

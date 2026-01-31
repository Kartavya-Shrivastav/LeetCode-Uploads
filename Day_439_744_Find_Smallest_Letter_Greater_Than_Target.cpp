#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given a list of sorted characters letters containing only lowercase letters, and a target letter target,
// find the smallest letter in the list that is greater than the target. The letters wrap around if necessary.

// Approach: Linear search through the list to find the smallest letter greater than the target.

// Steps:
// 1. Initialize the result with the first letter in the list.
// 2. Iterate through the list of letters.
// 3. For each letter, check if it is greater than the target.
// 4. If it is, check if it is smaller than the current result and update the result accordingly.
// 5. Return the result.

// Time Complexity: O(N), where N is the number of letters in the list.
// Space Complexity: O(1), as we are using a constant amount of extra space.

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res = letters[0];
        bool flag = false;

        for (char ch : letters) {
            if (!flag) {
                if (ch > target) {
                    res = ch;
                    flag = !flag;
                }
            } else {
                if (ch > target && ch < res) res = ch;
            }
        }

        return res;
    }
};
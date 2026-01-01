#include <bits/stdc++.h>
using namespace std;

// LeetCode Problem: Plus One
// Approach: Traverse the digits from the last to the first. If the digit is less than 9, increment it and return the result. If the digit is 9, set it to 0 and continue to the next digit. If all digits are 9, insert a 1 at the beginning of the vector.

// Steps:
// 1. Start from the last digit of the array.
// 2. If the digit is less than 9, increment it by 1 and return the array.
// 3. If the digit is 9, set it to 0 and move to the next digit.
// 4. If all digits are processed and are 9, insert 1 at the beginning of the array.
// 5. Return the modified array.

// Time Complexity: O(n), where n is the number of digits.
// Space Complexity: O(1) if we don't consider the output space.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;     
    }
};
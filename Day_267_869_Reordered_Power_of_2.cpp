#include <bits/stdc++.h>
using namespace std;

// Problem: Check if a number can be reordered to form a power of 2
// Approach: Count the digits of the number and compare with the digits of powers of 2

// Steps:
// 1. Convert the number to a string and sort its digits.
// 2. For each power of 2 from 1 to 2^30,
//    convert it to a string, sort its digits, and compare with the sorted digits of the input number.
// 3. If any match is found, return true; otherwise, return false.
// 4. The maximum power of 2 we check is 2^30 since 2^31 exceeds the range of a 32-bit integer.
// 5. The function uses a lambda to count and sort the digits of a number, which is efficient for this problem.

// Time Complexity: O(log n) for counting digits, O(1) for checking powers of 2
// Space Complexity: O(1) for storing the digit counts

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        auto countDigits = [](int x) {
            string s = to_string(x);
            sort(s.begin(), s.end());
            return s;
        };
        string target = countDigits(n);
        for (int i = 0; i < 31; i++) {
            if (countDigits(1 << i) == target) return true;
        }
        return false;
    }
};
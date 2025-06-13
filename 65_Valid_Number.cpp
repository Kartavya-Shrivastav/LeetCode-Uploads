#include <bits/stdc++.h>
using namespace std;
// This code checks if a given string is a valid number according to the rules of scientific notation
// It handles integers, decimals, and numbers in scientific notation (e.g., "1e10", "2.5E-3")

class Solution {
public:
    // Function to check if a given string is a valid number
    bool isNumber(string s) {
        int n = s.size();
        bool isdot = false; // Flag to check if a decimal point has appeared
        bool nums = false;  // Flag to check if at least one digit has appeared
        bool ise = false;   // Flag to check if 'e' or 'E' has appeared

        for(int i = 0; i < n; i++) {
            if(isdigit(s[i])) {
                // If the character is a digit, set nums to true
                nums = true;
            }
            else if(s[i] == '+' || s[i] == '-') {
                // '+' or '-' is only allowed at the start or just after 'e' or 'E'
                if(i > 0 && (s[i-1] != 'e' && s[i-1] != 'E'))
                    return false;
            }
            else if(s[i] == 'e' || s[i] == 'E') {
                // 'e' or 'E' can only appear once and must follow a number
                if(ise || !nums)
                    return false;
                ise = true;
                nums = false; // Reset nums to ensure digits follow 'e' or 'E'
            }
            else if(s[i] == '.') {
                // '.' can only appear once and not after 'e' or 'E'
                if(isdot || ise)
                    return false;
                isdot = true;
            }
            else {
                // Any other character is invalid
                return false;
            }
        }
        // Return true only if the string ends with a valid number
        return nums;
    }
};
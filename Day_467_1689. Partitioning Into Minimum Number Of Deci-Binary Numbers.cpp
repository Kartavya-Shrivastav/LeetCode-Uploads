#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a string n representing a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n. A deci-binary number is a decimal number that consists of only the digits 0 and 1, and it may contain leading zeros.
Approach: The minimum number of deci-binary numbers needed to sum up to n is equal to the maximum digit in the string n. This is because each deci-binary number can contribute at most 1 to each digit of n, so if the maximum digit in n is d, we need at least d deci-binary numbers to sum up to n.

Steps:
1. Initialize a variable ans to 0 to keep track of the maximum digit found in the string n.
2. Iterate through each character x in the string n:
    a. Convert the character x to its integer value by subtracting '0' from it.
    b. Update ans to be the maximum of ans and the integer value of x.
    c. If ans reaches 9, we can break out of the loop early since 9 is the largest possible digit in a decimal number.
3. Return the value of ans, which represents the minimum number of deci-binary numbers needed to sum up to n.

Time Complexity: O(m), where m is the length of the string n. We need to iterate through the string once to find the maximum digit.
Space Complexity: O(1) extra space, as we are using only a few variables to keep track of the maximum digit found.
*/

class Solution {
public:
    static int minPartitions(string& n) {
        int ans=0;
        for(int x: n){
            ans=max(ans, x-'0');
            if (ans==9) break;
        }
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;
 
/*
Problem: Given a binary string s representing a number, return the number of steps to reduce it to 1. In one step, if the current number is even, you have to divide it by 2, otherwise, you have to add 1 to it.
Approach: We can simulate the process of reducing the number to 1 by iterating through the binary string from the least significant bit to the most significant bit. We keep track of the number of steps and any carry that may occur when adding 1 to an odd number.

Steps:
1. Initialize a variable steps to count the number of steps and a variable carry to keep track of any carry that may occur when adding 1 to an odd number.
2. Iterate through the binary string from the least significant bit to the most significant bit (from right to left).
3. For each bit, calculate the current bit value by adding the carry to the bit value (0 or 1).
4. If the current bit value is 1, it means the number is odd, so we need to add 1 to it, which will result in a carry for the next iteration. In this case, we add 2 steps (one for adding 1 and one for dividing by 2) and set the carry to 1.
5. If the current bit value is 0, it means the number is even, so we can simply divide it by 2, which adds 1 step.
6. After the loop, we need to add any remaining carry to the steps, as it represents the final step of reducing the number to 1.

Time Complexity: O(n), where n is the length of the binary string. We iterate through the string once.
Space Complexity: O(1) extra space, as we are using only a few variables to keep track of the steps and carry.
*/

class Solution {
public:
    int numSteps(string s) {
        int steps = 0, carry = 0;

        for (int i = s.size() - 1; i > 0; i--) {
            int bit = (s[i] - '0') + carry;

            if (bit == 1) {
                steps += 2;
                carry = 1;
            } else {
                steps += 1;
            }
        }

        return steps + carry;
    }
};
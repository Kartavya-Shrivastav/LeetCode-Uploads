#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a positive integer n, count how many numbers from 1 to n are good. A number is good if after rotating each digit individually by 180 degrees, we get a valid number that is different from the original number. The digits 0, 1, and 8 rotate to themselves; the digits 2 and 5 rotate to each other; the digits 6 and 9 rotate to each other; and the digits 3, 4, and 7 do not rotate to any valid digit.
Approach: We can iterate through each number from 1 to n and check if it is a good number. For each number, we can check each digit to see if it is valid (not 3, 4, or 7) and if it has at least one digit that changes (2, 5, 6, or 9). If both conditions are satisfied, we can increment our count of good numbers.

Steps:
1. Initialize a count variable to 0 to keep track of the number of good numbers.
2. Iterate through each number from 1 to n.
3. For each number, initialize a boolean variable isValid to true and hasChange to false.
4. While the number is greater than 0, extract the last digit and check if it is valid. If it is 3, 4, or 7, set isValid to false and break out of the loop. If it is 2, 5, 6, or 9, set hasChange to true.
5. After checking all digits, if isValid is true and hasChange is true, increment the count of good numbers.

Time Complexity: O(n * log n), where n is the input number, since we are iterating through each number from 1 to n and checking each digit takes O(log n) time.
Space Complexity: O(1), since we are using a constant amount of extra space to store variables for the calculations.
*/

class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        
        for (int i = 1; i <= n; i++) {
            int num = i;
            bool isValid = true;
            bool hasChange = false;
            
            while (num > 0) {
                int digit = num % 10;
                
                if (digit == 3 || digit == 4 || digit == 7) {
                    isValid = false;
                    break;
                }
                
                if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                    hasChange = true;
                }
                
                num /= 10;
            }
            
            if (isValid && hasChange) {
                count++;
            }
        }
        
        return count;
    }
};
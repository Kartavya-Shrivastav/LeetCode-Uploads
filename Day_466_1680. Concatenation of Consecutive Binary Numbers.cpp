#include <bits/stdc++.h>
using namespace std;    

/*
Problem: Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 10^9 + 7.
Approach: We can iterate through the numbers from 1 to n, convert each number to its binary representation, and concatenate them together. To avoid dealing with large strings, we can keep track of the length of the binary representation of each number and use bitwise operations to concatenate the binary representations efficiently.

Steps:
1. Initialize a variable result to store the final concatenated value and a variable len to keep track of the length of the binary representation of the current number.
2. Iterate through the numbers from 1 to n: 
    a. Check if the current number is a power of 2 (i.e., if it has only one bit set). If it is, increment the length variable len.
    b. Left shift the result by len bits to make space for the new binary representation.
    c. Use a bitwise OR operation to concatenate the current number's binary representation to the result and take modulo 10^9 + 7 to keep the value manageable.
3. Return the final result modulo 10^9 + 7.

Time Complexity: O(n), where n is the input integer. We iterate through the numbers from 1 to n once.
Space Complexity: O(1) extra space, as we are using only a few variables to keep track of the result and the length of the binary representation.
*/

class Solution {
public:
    const long long MOD = 1e9 + 7;

    int concatenatedBinary(int n) {

        long long result=0;
        int len=0;

        for(int i=1;i<=n;i++){
            if(!(i&(i-1))){
                len++;
            }
            result=(result<<len);
            result=(result | i )%MOD;


        }
        return result %MOD;
        
    }
};
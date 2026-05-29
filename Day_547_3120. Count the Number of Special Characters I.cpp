#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a string word, return the number of special characters in word. A character is special if it is an uppercase letter and its lowercase counterpart also appears in word, or it is a lowercase letter and its uppercase counterpart also appears in word.  
Approach: We can solve this problem by using two bitsets to keep track of the presence of uppercase and lowercase letters in the string. We will iterate through the string and set the corresponding bits for uppercase and lowercase letters. Finally, we will take the bitwise AND of the two bitsets to find the common characters and count the number of set bits in the result.

Steps:
1. Initialize two bitsets of size 27 (to account for 26 letters and an extra bit for indexing) to keep track of uppercase and lowercase letters.
2. Iterate through each character in the string:
   - Determine if the character is uppercase or lowercase using bitwise operations.
   - Set the corresponding bit in the appropriate bitset based on whether the character is uppercase or lowercase.
3. After processing the string, take the bitwise AND of the two bitsets to find the characters that are present in both cases.
4. Count the number of set bits in the resulting bitset, which will give us the number of special characters.

Time Complexity: O(n) where n is the length of the string, since we need to iterate through the string once.
Space Complexity: O(1) since we are using a fixed amount of space for the bitsets regardless of the input size.
*/

class Solution {
public:
    static int numberOfSpecialChars(string& word) {
        bitset<27> A[2];
        for(char c: word){
            bool isLower=c&32;
            A[isLower][31&c]=1;
        }
        return (A[0]&A[1]).count();
    }
};
#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.
Approach: We can use a bitset to keep track of which binary codes of length k we have seen in the string. We can iterate through the string and for each substring of length k, we can convert it to an integer and mark it as seen in the bitset. If we have seen all possible binary codes of length k, we can return true.

Steps:
1. Calculate the total number of binary codes of length k, which is 2^k.
2. Initialize a bitset to keep track of seen binary codes and a variable to count the number of codes we still need to see.
3. Iterate through the string s and for each substring of length k: 
    a. Convert the substring to an integer hash.
    b. If the hash has not been seen before, mark it as seen and decrement the count of required codes.
    c. If the count of required codes reaches zero, return true.    
4. If we finish iterating through the string and still have required codes, return false.   

Time Complexity: O(n) where n is the length of the string s, since we are iterating through the string once.
Space Complexity: O(2^k) since we are using a bitset to keep track of seen binary codes, which can have at most 2^k different codes.
*/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int req = 1 << k;
        bitset<1048576> seen;
        int mask = req - 1;
        int hash = 0;

        for (int i = 0; i < s.length(); ++i) {
            hash = ((hash << 1) & mask) | (s[i] & 1);

            if (i >= k - 1 && !seen[hash]) {
                seen[hash] = 1;
                req--;
                if (req == 0) return true;
            }
        }

        return false;
    }
};
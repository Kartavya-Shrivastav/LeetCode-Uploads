#include <bits/stdc++.h>
using namespace std;
/*
Problem: Given a binary string s consisting of '0' and '1', return the minimum number of
operations required to make the string alternating. An alternating string is one where
no two adjacent characters are the same (e.g., "0101" or "1010").

Approach:
An alternating binary string can only have two possible patterns:
1. Start with '0' → "010101..."
2. Start with '1' → "101010..."

Instead of constructing both patterns, we count how many positions in the given string
do not match the first pattern. The number of mismatches for the second pattern will be
the remaining positions.

The expression `(s[i] ^ i) & 1` helps detect whether the character at index i matches
the expected character of pattern "0101...":
- If i is even, expected character is '0'
- If i is odd, expected character is '1'

Using XOR with the index and checking the last bit determines whether the character
needs to be flipped.

Steps:
1. Let n be the length of the string.
2. Traverse the string from index 0 to n-1.
3. For each index i, check whether the current character matches the expected
   character of pattern "0101..." using `(s[i] ^ i) & 1`.
4. Increment count whenever there is a mismatch.
5. `count` represents the number of changes needed for pattern "0101...".
6. The changes required for pattern "1010..." will be `n - count`.
7. Return the minimum of the two values.

Time Complexity: O(n)
- We traverse the string once.

Space Complexity: O(1)
- Only a few variables are used; no extra space is required.
*/

class Solution {
public:
    int minOperations(string s) {
        int count = 0, n = s.length();
        for (int i = 0; i < n; i++)
            count += (s[i] ^ i) & 1;
          
        return min(count, n - count);
    }
};
#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a binary string s, you can perform two operations:
1. Remove the first character of the string and append it to the end (rotation).
2. Flip any character ('0' → '1' or '1' → '0').

Return the minimum number of flips required to make the string alternating.
An alternating string has no two adjacent characters equal (e.g., "0101" or "1010").

Approach:
If the string is rotated, different positions will align with the alternating pattern.
Instead of explicitly generating all rotations, we simulate them using a sliding window idea.

There are only two valid alternating patterns:
1. "010101..."
2. "101010..."

We count mismatches for both patterns while rotating the string.

The expression `(s[i] ^ i) & 1` determines whether the current character matches
the expected character for pattern "0101...".

We maintain two counters:
- op[0] → mismatches for pattern starting with '0'
- op[1] → mismatches for pattern starting with '1'

Initially we compute mismatches for the original string.
Then we simulate rotations by adjusting the mismatch counts dynamically.

Steps:
1. Let n be the length of the string.
2. Traverse the string and compute mismatches for both alternating patterns.
3. Store mismatches in op[0] and op[1].
4. The minimum flips for the current configuration is min(op[0], op[1]).
5. Simulate rotations:
   - Remove the contribution of the first character.
   - Add it back as if it appeared at the end of the rotated string.
6. Update mismatch counts accordingly.
7. Track the minimum flips required across all rotations.
8. Return the minimum flips.

Time Complexity: O(n)
- We scan the string once and simulate rotations in linear time.

Space Complexity: O(1)
- Only constant extra space is used.
*/

class Solution {
public:
    int minFlips(auto& s) {
        int n = s.length();
        int op[2] = {0, 0};

        for (int i = 0; i < n; i++)
            op[(s[i] ^ i) & 1]++;

        int res = min(op[0], op[1]);

        for (int i = 0; i < n - 1; i++) {
            op[(s[i] ^ i) & 1]--;
            op[(s[i] ^ (n + i)) & 1]++;
            res = min(res, min(op[0], op[1]));
        }

        return res;
    }
};
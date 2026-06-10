#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a string word consisting of uppercase and lowercase English letters, return the number of special characters. A character is considered special if both its lowercase and uppercase forms appear in the string, and the lowercase occurrence appears before any uppercase occurrence of the same character.

Approach: We use two bitsets to efficiently track the presence and validity of lowercase and uppercase characters. The bitset A[0] stores lowercase letters, while A[1] stores uppercase letters that satisfy the required ordering condition. For each character, we determine its alphabet index and whether it is uppercase or lowercase using bit manipulation. Lowercase letters are marked immediately, while uppercase letters are marked only if their corresponding lowercase letter has already been seen. Finally, the intersection of the two bitsets gives all special characters.

Steps:
1. Create two bitsets:
   - A[0] for lowercase letters.
   - A[1] for valid uppercase letters.
2. Traverse each character in the string.
3. Compute:
   - i = character position in the alphabet (1 to 26).
   - Case = 0 for lowercase, 1 for uppercase.
4. If the character is lowercase:
   - Mark its position in A[0].
5. If the character is uppercase:
   - Mark its position in A[1] only if the corresponding lowercase letter has already appeared.
6. After processing the entire string, compute the intersection (A[0] & A[1]).
7. Count the number of set bits in the intersection and return the result.

Time Complexity: O(n), where n is the length of the string. Each character is processed exactly once, and all bitset operations are constant time due to the fixed alphabet size (26 letters).

Space Complexity: O(1), as only two fixed-size bitsets are used regardless of the input size.
*/
class Solution {
public:
    int numberOfSpecialChars(string word) {
        bitset<27> A[2];

        for (auto& ch : word) {
            int i = ch & 31;
            int Case = (ch >> 5) & 1;

            A[Case].set(i, !(Case & A[0][i]));
        }

        return (A[0] & A[1]).count();
    }
};


class Solution {
public:
    int numberOfSpecialChars(string word) {
        bitset<27> A[2];

        for (auto& ch : word) {
            int i = ch & 31;
            int Case = (ch >> 5) & 1;

            A[Case].set(i, !(Case & A[0][i]));
        }

        return (A[0] & A[1]).count();
    }
};
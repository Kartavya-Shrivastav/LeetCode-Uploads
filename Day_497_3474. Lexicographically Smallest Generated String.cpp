#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given two strings s and t, you need to generate a string ans of length n + m - 1 (where n is the length of s and m is the length of t) such that:
Approach: Lexicographically smallest string that satisfies the conditions for 'T' and 'F' in s.

Steps:
1. Initialize ans with '?' to indicate undecided positions.
2. Process each character in s:
   - If it's 'T', ensure the corresponding substring in ans matches t.
   - If it's 'F', ensure the corresponding substring in ans does not match t.
3. For undecided positions, fill them with 'a' initially.
4. After processing 'T', if any 'F' condition is violated, try to change the last undecided position in that substring to 'b' to break the match.
5. If any condition cannot be satisfied, return an empty string.

Time Complexity: O(n * m) due to the nested loops for processing 'T' and 'F'.
Space Complexity: O(n + m) for the ans string and temporary variables.
*/

class Solution {
public:
    string generateString(string s, string t) {
        int n = s.size(), m = t.size();
        string ans(n + m - 1, '?'); // ? indicates an undecided position

        // Process T
        for (int i = 0; i < n; i++) {
            if (s[i] != 'T') {
                continue;
            }
            // The substring must equal t
            for (int j = 0; j < m; j++) {
                char v = ans[i + j];
                if (v != '?' && v != t[j]) {
                    return "";
                }
                ans[i + j] = t[j];
            }
        }

        string old_ans = ans;
        for (char& c : ans) {
            if (c == '?') {
                c = 'a'; // Initial value for undecided positions is a
            }
        }

        // Process F
        for (int i = 0; i < n; i++) {
            if (s[i] != 'F') {
                continue;
            }
            // The substring must not equal t
            if (string(ans.begin() + i, ans.begin() + i + m) != t) {
                continue;
            }
            // Find the last undecided position
            bool ok = false;
            for (int j = i + m - 1; j >= i; j--) {
                if (old_ans[j] == '?') { // Previously filled with a, now change it to b
                    ans[j] = 'b';
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                return "";
            }
        }

        return ans;
    }
};
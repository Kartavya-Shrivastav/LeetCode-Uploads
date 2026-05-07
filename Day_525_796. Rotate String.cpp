#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s. A shift on s consists of moving the leftmost character of s to the rightmost position.
Approach: We can use a deterministic finite automaton (DFA) to check if goal can be obtained by shifting s. We will build a DFA based on the string s, where each state represents the position in the string. The transitions between states will be determined by the characters in s. We will then simulate the process of shifting s and check if we can reach the accepting state (which corresponds to having matched all characters of s) while processing the characters of goal.

Steps:
1. Check if the lengths of s and goal are different. If they are, return false, since they cannot be rotations of each other.
2. Build a DFA based on the string s. The DFA will have n states (where n is the length of s) and 26 possible transitions for each state (corresponding to each letter of the alphabet).
3. Initialize the DFA such that the transition from state 0 on the character s[0] leads to state 1, the transition from state 1 on the character s[1] leads to state 2, and so on, until the transition from state n-1 on the character s[n-1] leads back to state 0.
4. Simulate the process of shifting s by processing the characters of goal. For each character in goal, update the current state of the DFA based on the transition for that character. If at any point we reach the accepting state (state n), return true.
5. If we finish processing all characters of goal without reaching the accepting state, return false.

Time Complexity: O(n), where n is the length of the strings, since we are building the DFA and simulating the process of shifting s.
Space Complexity: O(n * 26), since we are storing the DFA with n states and 26 possible transitions for each state.
*/

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        if (n != goal.length()) return false;

        int dfa[101][26] = {0};
        dfa[0][s[0] - 'a'] = 1;

        int x = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 26; j++)
                dfa[i][j] = dfa[x][j];
            int c = s[i] - 'a';
            dfa[i][c] = i + 1;
            x = dfa[x][c];
        }

        int state = 0;
        for (int i = 0; i < n << 1; i++) {
            state = dfa[state][goal[i % n] - 'a'];
            if (state == n)
                return true;
        }

        return false;
    }
};
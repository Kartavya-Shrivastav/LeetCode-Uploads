#include <bits/stdc++.h>
using namespace std;

/* 
Problem: Given a string s, we need to find the minimum distance to type the word using two fingers on a keyboard. The keyboard is represented as a 6x5 grid of characters from 'A' to 'Z'. The distance between two characters is defined as the Manhattan distance on the grid.
Approach: We can use dynamic programming to solve this problem. We will maintain a 3D DP array where dp[i][j][k] represents the minimum distance to type the first i characters of the string with the left finger on character j and the right finger on character k. We will iterate through each character in the string and update our DP array based on the previous states.

Steps:
1. Initialize a 3D DP array with dimensions [n+1][26][26] where n is the length of the string. Set all values to a large number (e.g., 1e6) to represent infinity.
2. For each character in the string, calculate the distance from the previous positions of the fingers to the current character and update the DP array accordingly.
3. After processing all characters, the answer will be the minimum value in dp[n][j][k] for all j and k.
4. Return the minimum distance found.

Time Complexity: O(n * 26 * 26) where n is the length of the string, as we need to iterate through each character and update the DP array for all possible positions of the fingers.
Space Complexity: O(n * 26 * 26) for the DP array.  
*/

class Solution {
public:
    int cal(int a, int b) {
        int ax = a / 6, ay = a % 6, bx = b / 6, by = b % 6;
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    int minimumDistance(string s) {
        int n = s.size(), dp[300][26][26];

        for (int i = 0; i < n; i++) {
            int t = s[i] - 'A';
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    dp[i + 1][j][k] = 1e6;
                }
            }
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    dp[i + 1][j][t] = min(dp[i + 1][j][t], dp[i][j][k] + cal(k, t));
                    dp[i + 1][t][k] = min(dp[i + 1][t][k], dp[i][j][k] + cal(j, t));
                }
            }
        }

        int ans = 1e6;
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                ans = min(ans, dp[n][j][k]);
            }
        }
        return ans;
    }
};
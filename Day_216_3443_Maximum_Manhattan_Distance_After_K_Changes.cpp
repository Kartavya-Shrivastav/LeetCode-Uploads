#include <bits/stdc++.h>
using namespace std;

// Problem: Given a string representing directions ('N', 'S', 'E', 'W') and an integer k, find the maximum Manhattan distance that can be achieved after making at most k changes to the string.
// Approach: Iterate through the string while maintaining counts of each direction. Calculate the Manhattan distance at each step and consider the effect of making changes.

// Steps:
// 1. Initialize counters for each direction (north, south, east, west).
// 2. Iterate through the string, updating the counters based on the current character.
// 3. Calculate the current Manhattan distance based on the absolute differences of the counters.
// 4. For each position, compute the maximum distance considering the number of changes allowed (k).
// 5. Return the maximum distance found.

// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(1), since we only use a fixed number of counters.


class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        int north = 0, south = 0, east = 0, west = 0;
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == 'N') north++;
            else if (c == 'S') south++;
            else if (c == 'E') east++;
            else if (c == 'W') west++;
            
            int x = abs(north - south);
            int y = abs(east - west);
            int MD = x + y;
            int dis = MD + min(2 * k, i + 1 - MD);
            ans = max(ans, dis);
        }
        
        return ans;
    }
};
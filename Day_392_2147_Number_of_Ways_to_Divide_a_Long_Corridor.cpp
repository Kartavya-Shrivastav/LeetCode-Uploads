#include <bits/stdc++.h>
using namespace std;

// Problem: Number of Ways to Divide a Long Corridor
// Approach: Identify positions of seats and calculate the number of ways to divide the corridor based on gaps between pairs of seats.

// Steps:
// 1. Traverse the corridor string to find the indices of all 'S' (seats).
// 2. If the number of seats is odd or zero, return 0 as it's impossible to divide the corridor properly.
// 3. For every pair of seats, calculate the number of empty spaces (gaps) between them.
// 4. Multiply the number of gaps between each pair of seats to get the total number of ways to divide the corridor.
// 5. Return the result modulo 1e9 + 7.

// Complexity Analysis:
// - Time Complexity: O(N) where N is the length of the corridor string, as we traverse the string once.
// - Space Complexity: O(M) where M is the number of seats, for storing their positions.

class Solution {
public:
    const int mod = 1e9 + 7;
    int numberOfWays(string corridor) {
        vector<int> pos;
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                pos.push_back(i);
            }
        }
        
        if (pos.size() % 2 or pos.size() == 0) {
            return 0;
        }
        
        long res = 1;
        for (int i = 2; i < pos.size(); i += 2) {
            int len_of_gap = pos[i] - pos[i - 1];
            res = (res * len_of_gap) % mod;
        }

        return res;
    }
};
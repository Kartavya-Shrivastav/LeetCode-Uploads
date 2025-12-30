#include <bits/stdc++.h>
using namespace std;

// Problem: Pyramid Transition Matrix
// Approach: Use DFS with memoization to explore possible pyramid configurations based on allowed transitions.

// Steps:
// 1. Parse the allowed transitions into a 2D array for quick access.   
// 2. Represent the pyramid levels using bit manipulation for efficient storage and retrieval.
// 3. Implement a DFS function that attempts to build the pyramid from the bottom up, checking all possible top blocks for each pair of adjacent blocks.
// 4. Use a visited array to memoize already explored configurations to avoid redundant calculations.
// 5. If the pyramid can be successfully built to the top, return true; otherwise, return false.
// 6. The main function initializes the pyramid and starts the DFS process.

// Time Complexity: O(k^(n^2)) in the worst case, where k is the number of allowed transitions and n is the height of the pyramid.
// Space Complexity: O(n^2) for the pyramid representation and visited states.

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        vector<int> groups[7][7];
        for (auto& s : allowed) {
            groups[s[0] & 31][s[1] & 31].push_back(s[2] & 31);
        }

        int n = bottom.size();
        vector<int> pyramid(n);
        for (int i = 0; i < n; i++) {
            pyramid[n - 1] |= (bottom[i] & 31) << (i * 3);
        }

        vector<uint8_t> vis(1 << ((n - 1) * 3));

        auto dfs = [&](this auto&& dfs, int i, int j) -> bool {
            if (i < 0) {
                return true;
            }

            if (vis[pyramid[i]]) {
                return false;
            }

            if (j == i + 1) {
                vis[pyramid[i]] = true;
                return dfs(i - 1, 0);
            }

            for (int top : groups[pyramid[i + 1] >> (j * 3) & 7][pyramid[i + 1] >> ((j + 1) * 3) & 7]) {
                pyramid[i] &= ~(7 << (j * 3));
                pyramid[i] |= top << (j * 3);
                if (dfs(i, j + 1)) {
                    return true;
                }
            }
            return false;
        };

        return dfs(n - 2, 0);
    }
};
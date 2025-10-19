#include <bits/stdc++.h>
using namespace std;

// Problem: Find the lexicographically smallest string after applying a series of operations
// Approach: Greedy + Simulation

// Steps:
// 1. Precompute the best possible digit for each digit (0-9) after applying the operation.
// 2. Use a visited array to keep track of the positions we can modify.
// 3. For each valid starting position, generate the modified string and keep track of the lexicographically smallest one.
// 4. Return the smallest string found.

// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution {
public:
    string findLexSmallestString(const string& s, const int a, const int b) {
        const int n = (int)s.size();
        vector<int> best(10);
        for (int i = 1; i < 10; i++) {
            int mn = i;
            for (int j = 1; j < 10; j++) {
                if ((i + a * j) % 10 < mn) {
                    mn = (i + a * j) % 10;
                    best[i] = j;
                }
            }
        }
        vector<char> seen(n);
        int j = 0;
        while (!seen[j]) {
            seen[j] = 1;
            (j += b) %= n;
        }
        auto ans = s;
        for (int i = 0; i < n; i++) {
            if (!seen[i])
                continue;
            auto t = s;
            rotate(t.begin(), t.begin() + i, t.end());
            vector m {b & 1 ? best[t[0] - '0'] : 0, best[t[1] - '0']};
            for (j = 0; j < n; j++)
                t[j] = static_cast<char>((t[j] - '0' + m[j & 1] * a) % 10 + '0');
            ans = min(ans, t);
        }
        return ans;
    }
};
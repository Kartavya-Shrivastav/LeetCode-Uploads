#include <bits/stdc++.h>
using namespace std;

// Problem: Delete Columns to Make Sorted II
// Approach: Greedy with state tracking

// Steps:
// 1. Maintain a boolean array to track which adjacent string pairs are already sorted.
// 2. For each column, check if it can help in sorting the unresolved pairs.
// 3. If a column causes any unresolved pair to be unsorted, increment deletion count.
// 4. Otherwise, update the resolved pairs based on the current column.
// 5. Return the total count of deleted columns.

// Complexity:
// Time: O(m * n) where m is number of strings and n is length of each string
// Space: O(n) for the resolved tracking array

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        vector<bool> resolved(n - 1, false);
        int unresolved = n - 1;
        int deletions = 0;

        for (int col = 0; col < m && unresolved > 0; col++) {
            bool bad = false;

            for (int i = 0; i < n - 1; i++) {
                if (!resolved[i] && strs[i][col] > strs[i + 1][col]) {
                    bad = true;
                    break;
                }
            }

            if (bad) {
                deletions++;
                continue;
            }

            for (int i = 0; i < n - 1; i++) {
                if (!resolved[i] && strs[i][col] < strs[i + 1][col]) {
                    resolved[i] = true;
                    unresolved--;
                }
            }
        }

        return deletions;
    }
};
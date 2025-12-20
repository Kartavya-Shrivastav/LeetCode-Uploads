#include <bits/stdc++.h>
using namespace std;

// Problem: Delete Columns to Make Sorted
// Approach: Greedy

// Steps:
// 1. For each column, check if it is sorted.   
// 2. If a column is not sorted, increment the deletion count.
// 3. Return the total count of unsorted columns.

// Complexity:
// Time: O(m * n) where m is number of strings and n is length of each string
// Space: O(1)

class Solution {
    bool isUnsorted(const vector<string>& strs, int j) {
        for (int i = 1; i < strs.size(); i++)
            if (strs[i][j] < strs[i - 1][j])
                return true;
        return false;
    }

public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0;
        for (int j = 0; j < strs[0].size(); j++)
            res += isUnsorted(strs, j);
        return res;
    }
};

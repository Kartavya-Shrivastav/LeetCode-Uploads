#include <bits/stdc++.h>
using namespace std;

// Problem: Count Negative Numbers in a Sorted Matrix
// Approach: Start from the bottom-left corner of the matrix and move either up or right based on the value at the current position.

// Steps:
// 1. Initialize two pointers, one at the bottom-left corner of the matrix (i = m-1, j = 0).
// 2. While the row pointer is within bounds (i >= 0) and the column pointer is within bounds (j < n):
//    a. If the current element is negative, all elements to the right in that row are also negative. Count them and move the row pointer up (i--).
//    b. If the current element is non-negative, move the column pointer to the right (j++).
// 3. Return the total count of negative numbers.

// Time Complexity: O(m + n) where m is the number of rows and n is the number of columns.
// Space Complexity: O(1) as we are using only a constant amount of extra space

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int i = m - 1; //row
        int j = 0;     //col

        int res = 0;

        while (i >= 0 && j < n) {
            if (grid[i][j] < 0) {
                res += n - j;
                i--;
            } else
                j++;
        }

        return res;
    }
};
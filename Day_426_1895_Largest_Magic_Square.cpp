#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given a 2D grid of integers, find the largest magic square within the grid. A magic square is defined as a square where the sums of each row, each column, and both main diagonals are all equal.
// Approach: We will use prefix sums to efficiently calculate the sums of rows, columns, and diagonals for any sub-square in the grid. We will then check all possible squares starting from the largest size down to 2x2 to find the largest magic square.

// Steps:
// 1. Precompute prefix sums for rows, columns, main diagonals, and anti-diagonals.
// 2. Iterate over all possible square sizes from the largest to the smallest.
// 3. For each square size, check all possible top-left corners of the square in the grid.
// 4. Use the prefix sums to quickly calculate the sums of rows, columns, and diagonals for the current square.
// 5. If a magic square is found, return its size immediately.

// Time Complexity: O(min(m, n)^3), where m and n are the dimensions of the grid, as we check all possible squares.
// Space Complexity: O(m * n), for storing the prefix sums.

class Solution {
public:
    bool isMagic(vector<vector<array<int,4>>> const & prefixSum, int r, int c, int sz) {
        int sum = prefixSum[r+sz][c+sz][2] - prefixSum[r][c][2]; // main-diagonal sum
        // cout << " main diagonal sum: " << sum << endl;
        if (sum != prefixSum[r+sz][c+1][3] - prefixSum[r][c+sz+1][3]) {
            // cout << " secondary: " << "(" << r+sz << "," << c+1 << ") ";
            // cout << prefixSum[r+sz][c+1][3] << " - "; 
            // cout << "(" << r << "," << c+sz+1 << ") ";
            // cout << prefixSum[r][c+sz+1][3] << endl;
            return false; // secondary-diagonal sum
        }
        // cout << " diagonal sum ok" << endl;

        // check row sum
        for (int i = 0, j = r; i < sz; i++, j++) {
            if (sum != prefixSum[j+1][c+sz][0] - prefixSum[j+1][c][0]) {
                // cout << " row: " << j << " " << prefixSum[j+1][c+sz][0] << " - " << prefixSum[j+1][c][0] << endl;
                return false;
            }
        }
        // cout << " row sum ok" << endl;
        // check col sum
        for (int i = 0, j = c; i < sz; i++, j++) {
            if (sum != prefixSum[r+sz][j+1][1] - prefixSum[r][j+1][1]) return false;
        }
        // cout << " col sum ok" << endl;
        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // {0,1,2,3} = {row,col,diag,anti-diag}
        vector<vector<array<int,4>>> prefixSum(m+1, vector<array<int,4>>(n+2));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int val = grid[i-1][j-1];
                prefixSum[i][j][0] = prefixSum[i][j-1][0] + val;
                prefixSum[i][j][1] = prefixSum[i-1][j][1] + val;
                prefixSum[i][j][2] = prefixSum[i-1][j-1][2] + val;
                prefixSum[i][j][3] = prefixSum[i-1][j+1][3] + val;
                // cout << i << "," << j << " (" << prefixSum[i][j][3] << ") ";
            }
            // cout << endl;
        }

        int sz = min(m, n); // the largest possible length of magic square
        for (int k = sz; k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    // cout << i << "," << j << "; sz: " << k << endl;
                    if (isMagic(prefixSum, i, j, k)) return k;
                }
            }
        }
        return 1;
    }
};
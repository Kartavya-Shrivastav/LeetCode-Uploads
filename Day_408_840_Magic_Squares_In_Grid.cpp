#include <bits/stdc++.h>
using namespace std;

// Problem: Magic Squares In Grid
// Approach: Check every 3x3 sub-grid to see if it forms a magic square 

// Steps:
// 1. Iterate through each possible starting point of a 3x3 sub-grid in the given grid.
// 2. For each sub-grid, check if it contains all numbers from 1 to 9 exactly once.
// 3. Verify that the sums of each row, each column, and both diagonals are equal.
// 4. Count the number of valid magic squares found.
// 5. `isMagicSquare` function checks if a 3x3 sub-grid is a magic square.
// 6. `numMagicSquaresInside` function iterates through the grid and counts all magic squares.
// 7. Return the total count of magic squares found.

// Time Complexity: O(m * n) where m is the number of rows and n is the number of columns in the grid.
// Space Complexity: O(1) since the extra space used does not depend on the input

class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int r, int c) {
        int sum = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        unordered_set<int> st;

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                int num = grid[r+i][c+j];
                if(num < 1 || num > 9 || st.count(num)) return false;
                st.insert(num);
            }
        }

        for(int i = 0; i < 3; i++) {
            if(grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i] != sum) return false;
            if(grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != sum) return false;
        }

        if(grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != sum) return false;
        if(grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != sum) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;

        for(int i = 0; i <= m - 3; i++) {
            for(int j = 0; j <= n - 3; j++) {
                if(isMagicSquare(grid, i, j)) cnt++;
            }
        }
        return cnt;
    }
};
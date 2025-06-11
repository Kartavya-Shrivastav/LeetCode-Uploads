#include <bits/stdc++.h>
using namespace std;
// This code is a solution to the problem of generating a spiral matrix of size n x n.
// The solution uses a direction array to navigate through the matrix and fill it with numbers from 1 to n^2.

class Solution {
public:
    int floorMod(int x, int y) { return ((x % y) + y) % y; }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int cnt = 1;
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0;
        int row = 0;
        int col = 0;
        while (cnt <= n * n) {
            result[row][col] = cnt++;
            int r = floorMod(row + dir[d][0], n);
            int c = floorMod(col + dir[d][1], n);
            // change direction if next cell is non zero
            if (result[r][c] != 0) d = (d + 1) % 4;
            row += dir[d][0];
            col += dir[d][1];
        }
        return result;
    }
};
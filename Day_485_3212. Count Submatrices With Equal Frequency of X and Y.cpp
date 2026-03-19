#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a 2D matrix of characters containing 'X' and 'Y', count the number of submatrices that have an equal frequency of 'X' and 'Y'.
Approach: We can use a dynamic programming approach to solve this problem. We will iterate through the matrix and for each cell, we will calculate the cumulative count of 'X' and 'Y' up to that cell. We will maintain two arrays, sumX and sumY, to keep track of the cumulative counts of 'X' and 'Y' respectively. For each cell, if the cumulative count of 'X' is equal to the cumulative count of 'Y', it means that there is a submatrix ending at that cell with an equal frequency of 'X' and 'Y'. We will increment our result counter whenever we find such a condition.

Steps:
1. Initialize two arrays, sumX and sumY, to keep track of the cumulative counts of 'X' and 'Y' for each column.
2. Iterate through each row of the matrix.
3. For each cell, update the cumulative counts of 'X' and 'Y' based on the character at that cell.
4. If the cumulative count of 'X' is equal to the cumulative count of 'Y' at any cell, increment the result counter.
5. Return the final count of submatrices with equal frequency of 'X' and 'Y'.

Time Complexity: O(m*n) where m is the number of rows and n is the number of columns, as we need to iterate through each cell of the matrix once.
Space Complexity: O(n) for the additional space used to store the cumulative counts of 'X' and 'Y' for each column.

*/

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> sumX(cols, 0);
        vector<int> sumY(cols, 0);
        int res = 0;

        for (int i = 0; i < rows; i++) {
            int rx = 0, ry = 0;

            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 'X') rx++;
                else if (grid[i][j] == 'Y') ry++;
                sumX[j] += rx;
                sumY[j] += ry;
                if (sumX[j] > 0 && sumX[j] == sumY[j]) res++;
            }
        }

        return res;
    }
};
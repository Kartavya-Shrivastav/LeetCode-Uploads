#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a binary matrix, find the area of the largest submatrix that can be formed by rearranging the columns of the original matrix. The submatrix must consist of only 1s.
Approach: We can use a dynamic programming approach to solve this problem. First, we will iterate through the matrix and for each cell, we will calculate the number of consecutive 1s in the column up to that cell. This will give us a new matrix where each cell contains the height of the column of 1s. Then, for each row in this new matrix, we will sort the values in descending order. The area of the largest submatrix that can be formed with the current row as the base can be calculated by multiplying the height of the column (the value in the sorted row) by its position (index + 1). We will keep track of the maximum area found during this process.

Steps:
1. Iterate through the matrix and update each cell to contain the number of consecutive 1s in the column up to that cell.
2. For each row in the updated matrix, sort the values in descending order.
3. For each value in the sorted row, calculate the area of the submatrix that can be formed with that value as the height and its position as the width.
4. Keep track of the maximum area found and return it at the end.

Time Complexity: O(m*n*log(n)) where m is the number of rows and n is the number of columns. The sorting step takes O(n*log(n)) for each row, and we have m rows.
Space Complexity: O(1) if we modify the input matrix in place, otherwise O(m*n) for the additional space used to store the heights of the columns.  
*/

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        auto m = matrix.size(), n = matrix[0].size();
        int res = 0;

        for (int i = 1; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 1)
                    matrix[i][j] += matrix[i - 1][j];

        for (int i = 0; i < m; i++) {
            sort(matrix[i].rbegin(), matrix[i].rend());
            for (int j = 0; j < n; j++)
                res = max(res, matrix[i][j] * (j + 1));
        }

        return res;
    }
};
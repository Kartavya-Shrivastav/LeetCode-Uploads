#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a 2D matrix of integers and an integer k, reverse the elements of every k x k submatrix vertically. The reversal should be done in-place, meaning that the original matrix should be modified directly without using any additional space for another matrix.
Approach: We can iterate through the matrix in steps of k to identify the top-left corner of each k x k submatrix. For each identified submatrix, we can use two pointers to reverse the elements vertically. The top pointer will start at the top row of the submatrix and the bottom pointer will start at the bottom row of the submatrix. We will swap the elements in these two rows for each column in the submatrix until the top pointer is less than the bottom pointer.

Steps:
1. Iterate through the matrix with a step of k to identify the top-left corner of each k x k submatrix.
2. For each identified submatrix, initialize two pointers: one at the top row and one at the bottom row of the submatrix.
3. Swap the elements in the top and bottom rows for each column in the submatrix.   
4. Move the top pointer down and the bottom pointer up until they meet or cross each other.
5. Return the modified matrix after processing all k x k submatrices.'

Time Complexity: O(n * m) where n is the number of rows and m is the number of columns in the matrix. This is because we need to iterate through each element of the matrix once to reverse the submatrices.
Space Complexity: O(1) since we are modifying the matrix in-place and not using any additional space for another matrix.
*/

class Solution {
public:
    static vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int t=x, b=x+k-1; t<b; t++, b--){
            for(int j=y; j<y+k; j++)
                swap(grid[t][j], grid[b][j]);
        }
        return grid;
    }
};
#include <bits/stdc++.h>
using namespace std;

/*
Problem: You are given an m x n integer matrix grid and an integer k. You need to cyclically rotate the grid k times. In one cyclic rotation, the elements of the grid are shifted by one in the following order:
- The first element of the first row moves to the first element of the second row.  
- The last element of the first row moves to the first element of the first row.
- The last element of the second row moves to the first element of the third row.   
- The last element of the third row moves to the first element of the fourth row.
- The last element of the fourth row moves to the first element of the first row.
- The last element of the last row moves to the first element of the first row.
Return the grid after cyclically rotating it k times.

Approach: We can solve this problem by iterating through each layer of the grid and performing the cyclic rotation for that layer. We will first extract the elements of the current layer into a temporary vector, then we will rotate the elements in that vector by k positions, and finally we will place the rotated elements back into their respective positions in the grid.

Steps:
1. We will determine the number of layers in the grid, which is equal to min(m, n) / 2, where m is the number of rows and n is the number of columns.
2. For each layer, we will create a temporary vector to store the elements of that layer. We will iterate through the top row, right column, bottom row, and left column of the current layer to fill the temporary vector.
3. We will then rotate the elements in the temporary vector by k positions. We can achieve this by calculating the new index for each element after rotation using the formula (current_index + k) % size_of_vector.
4. Finally, we will place the rotated elements back into their respective positions in the grid by iterating through the same top row, right column, bottom row, and left column of the current layer and assigning the rotated values from the temporary vector.

Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the grid, since we need to iterate through each element of the grid at least once.   
Space Complexity: O(m + n), since we are using a temporary vector to store the elements of each layer, which can have at most m + n elements in the worst case.
*/

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for(int layer = 0; layer < layers; layer++) {

            vector<int> vals;

            int top = layer;
            int left = layer;

            int bottom = m - layer - 1;
            int right = n - layer - 1;

            // top row
            for(int j = left; j <= right; j++) {
                vals.push_back(grid[top][j]);
            }

            // right column
            for(int i = top + 1; i <= bottom - 1; i++) {
                vals.push_back(grid[i][right]);
            }

            // bottom row
            for(int j = right; j >= left; j--) {
                vals.push_back(grid[bottom][j]);
            }

            // left column
            for(int i = bottom - 1; i >= top + 1; i--) {
                vals.push_back(grid[i][left]);
            }

            int sz = vals.size();
            int start = k % sz;
            int idx = start;

            // top row
            for(int j = left; j <= right; j++) {
                grid[top][j] = vals[idx];
                idx++;
                if(idx == sz){
                    idx = 0;
                }
            }

            // right column
            for(int i = top + 1; i <= bottom - 1; i++) {
                grid[i][right] = vals[idx];
                idx++;
                if(idx == sz){
                    idx = 0;
                }
            }

            // bottom row
            for(int j = right; j >= left; j--) {
                grid[bottom][j] = vals[idx];
                idx++;
                if(idx == sz){
                    idx = 0;
                }
            }

            // left column
            for(int i = bottom - 1; i >= top + 1; i--) {
                grid[i][left] = vals[idx];
                idx++;
                if(idx == sz){
                    idx = 0;
                }
            }
        }

        return grid;
    }
};
#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a 2D grid of integers, determine if it is possible to partition the grid into two non-empty parts with equal sums by making a single horizontal or vertical cut. A horizontal cut divides the grid into two parts along a row, while a vertical cut divides the grid into two parts along a column.
Approach: We can first calculate the total sum of all the elements in the grid. If the total sum is odd, it is impossible to partition the grid into two equal parts, so we can return false immediately. If the total sum is even, we can calculate the target sum for each part, which is half of the total sum. We can then iterate through the grid and calculate the cumulative sums for both horizontal and vertical cuts. If at any point the cumulative sum equals the target sum, we can return true, indicating that a valid partition exists.

Steps:
1. Calculate the total sum of all elements in the grid.
2. If the total sum is odd, return false.
3. Calculate the target sum as total sum divided by 2.
4. Iterate through the grid to calculate cumulative sums for horizontal cuts. If any cumulative sum equals the target sum, return true.
5. Reset the cumulative sum and iterate through the grid to calculate cumulative sums for vertical cuts. If any cumulative sum equals the target sum, return true.
6. If no valid partition is found after checking both horizontal and vertical cuts, return false.

Time Complexity: O(m * n) where m is the number of rows and n is the number of columns in the grid. We need to iterate through the grid to calculate the total sum and cumulative sums for both cuts.
Space Complexity: O(1) as we are using only a few variables to store sums and
the target value, regardless of the size of the grid.
*/

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long total = 0;
        
        for (auto &row : grid)
            for (int x : row)
                total += x;
        
        if (total % 2) return false;
        
        long long target = total / 2, sum = 0;
        
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++)
                sum += grid[i][j];
            if (sum == target) return true;
        }
        
        sum = 0;
        
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++)
                sum += grid[i][j];
            if (sum == target) return true;
        }
        
        return false;
    }
};
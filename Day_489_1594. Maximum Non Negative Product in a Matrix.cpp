#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a 2D grid of integers, find the maximum non-negative product of a path from the top-left corner to the bottom-right corner. The path can only move right or down. If there is no non-negative product, return -1. The result should be returned modulo 10^9 + 7.
Approach: We can use dynamic programming to solve this problem. We will maintain a 3D array dp where dp[i][j][0] represents the minimum product of a path to reach cell (i, j) and dp[i][j][1] represents the maximum product of a path to reach cell (i, j). We will iterate through the grid and for each cell, we will calculate the minimum and maximum products based on the values from the left and top cells. Finally, we will return the maximum product at the bottom-right corner if it is non-negative, otherwise we will return -1.

Steps:
1. Initialize a 3D array dp of size r x c x 2, where r is the number of rows and c is the number of columns in the grid. The third dimension will store the minimum and maximum products.
2. Set dp[0][0][0] and dp[0][0][1] to the value of the top-left cell of the grid.
3. Fill the first row and first column of the dp array by multiplying the current cell value with the previous cell's product.
4. For each cell (i, j) starting from (1, 1), calculate the minimum and maximum products by considering the products from the left and top cells and multiplying them with the current cell value.
5. After filling the dp array, check the maximum product at the bottom-right corner (dp[r-1][c-1][1]). If it is negative, return -1; otherwise, return the maximum product modulo 10^9 + 7.

Time Complexity: O(r * c) where r is the number of rows and c is the number of columns in the grid. We need to fill the dp array for each cell.
Space Complexity: O(r * c) for the dp array, which is required to store the minimum and maximum products for each cell in the grid.
*/

int64_t dp[15][15][2];
class Solution {
public:
    static int maxProductPath(vector<vector<int>>& grid) {
        const int r=grid.size(), c=grid[0].size(), MOD=1e9+7;
        int64_t p=dp[0][0][0]=dp[0][0][1]=grid[0][0];
        for(int j=1; j<c; j++){
            p*=grid[0][j];
            dp[0][j][0]=dp[0][j][1]=p;
        }
        p=grid[0][0];
        for(int i=1; i<r; i++){
            p*=grid[i][0];
            dp[i][0][0]=dp[i][0][1]=p;
            for(int j=1; j<c; j++){
                int x=grid[i][j];
                auto [minP, maxP]=minmax({x*dp[i][j-1][0], x*dp[i][j-1][1], x*dp[i-1][j][0], x*dp[i-1][j][1]});
                dp[i][j][0]=minP, dp[i][j][1]=maxP;
            }
        }
        int64_t ans=dp[r-1][c-1][1];
        return ans<0?-1: ans%MOD;
    }
};
#include <bits/stdc++.h>
using namespace std;    

/*
Problem: Given a 2D matrix of integers and an integer k, count the number of submatrices that have a top-left element and a sum less than k.
Approach: We can use a dynamic programming approach to solve this problem. We will iterate through the matrix and for each cell, we will calculate the sum of the submatrix that starts at that cell and extends to the right and downwards. We will keep track of the count of submatrices that have a sum less than k. We can optimize this by breaking out of the inner loop early when we find a submatrix that exceeds k, as any larger submatrix will also exceed k.

Steps:
1. Initialize a count variable to keep track of the number of valid submatrices.
2. Iterate through each cell in the matrix.
3. For each cell, calculate the sum of the submatrix that starts at that cell and extends to the right and downwards.
4. If the sum is less than k, increment the count.
5. If the sum exceeds k, break out of the inner loop to optimize performance.

Time Complexity: O(m*n*min(m,n)) where m is the number of rows and n is the number of columns. In the worst case, we may have to check all submatrices starting from each cell.
Space Complexity: O(1) if we modify the input matrix in place, otherwise O(m*n) for the additional space used to store the sums of the submatrices.
*/

class Solution {
public:
    static int countSubmatrices(vector<vector<int>>& grid, int k) {
        const int r=grid.size(), c=grid[0].size();
        int cnt=0, brCol=c;
        if (grid[0][0]>k) return 0;

        cnt++;
        for(int j=1; j<c; j++){
            int& x=grid[0][j];
            x+=grid[0][j-1];
            if(x>k)
                { brCol=j; break;}
            cnt++;
        }
        for(int i=1; i<r; i++){
            grid[i][0]+=grid[i-1][0];
            if (grid[i][0]>k) break;
            cnt++;
            for(int j=1; j<brCol; j++){
                int& x=grid[i][j];
                x+=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
                if (x>k){
                    brCol=j; break;
                }
                cnt++;
            }
        }
        return cnt;
    }
};
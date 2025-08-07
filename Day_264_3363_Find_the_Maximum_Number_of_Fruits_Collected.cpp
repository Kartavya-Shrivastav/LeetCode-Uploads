#include <bits/stdc++.h>
using namespace std;

// Problem: Find the Maximum Number of Fruits Collected from a Triangular Grid
// Approach: Use dynamic programming to calculate the maximum fruits collected from the triangular grid.

// Steps:
// 1. Initialize a variable to keep track of the diagonal sum, which is the sum of the fruits collected from the diagonal elements of the grid.
// 2. Fill the grid with 0 for specific indices to avoid unnecessary calculations.
// 3. Iterate through the grid, updating the number of fruits collected at each position based on the maximum fruits collected from
//    the previous row and adjacent columns.
// 4. Return the total maximum fruits collected, which is the sum of the diagonal elements and the last two elements of the last row and column.

// Time Complexity: O(n^2) where n is the size of the grid, as we iterate through each element.
// Space Complexity: O(1) as we are modifying the grid in place without using additional space.

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        const int n=fruits.size();
        int diag=0;
        for (int i=0; i<n; i++) diag+=fruits[i][i];

        // fill fruits[i][j] with 0 for i+j=n-2, i+j=n-3 
        for(int i=0; i<n-2; i++){
            fruits[i][n-2-i]=fruits[i][n-3-i]=0;
        }
        fruits[n-2][0]=0;

        // Proceed collecting fruits on the triangle east & triangle south simultaneously
        for (int i=1; i<n-1; i++) {
            int j0=max(i+1, n-i-1);
            for (int j=j0; j<n-1; j++) {
                fruits[i][j]+=max(fruits[i-1][j-1],
                    max(fruits[i-1][j], fruits[i-1][j+1]));
                fruits[j][i]+=max(fruits[j-1][i-1],
                    max(fruits[j][i-1], fruits[j+1][i-1]));
            }
            fruits[i][n-1]+=max(fruits[i-1][n-2], fruits[i-1][n-1]);
            fruits[n-1][i]+=max(fruits[n-2][i-1], fruits[n-1][i-1]);
        }
        return diag+fruits[n-2][n-1]+fruits[n-1][n-2];
    }
};
#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a grid of integers and a target score k, find the maximum score of a path from the top-left corner to the bottom-right corner, where each cell contributes its value to the score, but cells with value 0 contribute nothing.
Approach: We can use a depth-first search (DFS) approach with memoization to solve this problem. We will define a recursive function that takes the current position in the grid, the accumulated score so far, and the target score k. The function will explore both possible moves (right and down) and calculate the new score based on the value of the current cell. If the new score exceeds k, we will return -1 to indicate that this path is not valid. If we reach the bottom-right corner, we will return the value of that cell as part of the score. We will use a 3D vector for memoization to store results for each position and accumulated score to avoid redundant calculations.    

Steps:
1. Define a recursive function f that takes the grid, current position (a, b), accumulated score, and target score k as parameters.
2. Check if the current position is out of bounds. If it is, return -1.
3. Calculate the new score by adding the value of the current cell to the accumulated score. If the value of the current cell is 0, it does not contribute to the score.
4. If the new score exceeds k, return -1 to indicate that this path is not valid.
5. If we have reached the bottom-right corner of the grid, return the value of that cell as part of the score.
6. Check if the result for the current position and accumulated score is already computed in the dp vector. If it is, return that value to avoid redundant calculations.
7. Recursively call the function for the right and down moves, and calculate the best score from those moves.
8. If both moves return -1, it means there are no valid paths from the current position, so we will store -1 in the dp vector for the current position and accumulated score.

Time Complexity: O(x * y * k), where x is the number of rows, y is the number of columns, and k is the target score, since we are exploring each cell with different accumulated scores.
Space Complexity: O(x * y * k) for the dp vector used for memoization, where x is the number of rows, y is the number of columns, and k is the target score.
*/


class Solution {
public:

    int x,y;
    vector<vector<vector<int>>>dp;

    int f(vector<vector<int>>& grid,int a,int b,int cost,int k){

        if(a>=x || b>=y) return -1;

        int newCost=cost+(grid[a][b]!=0);

        if(newCost>k) return -1;

        if(a==x-1 && b==y-1) return grid[a][b];

        if(dp[a][b][newCost]!=INT_MIN)  return dp[a][b][newCost];

        int right=f(grid,a,b+1,newCost,k);
        int down=f(grid,a+1,b,newCost,k);
        int best=max(right,down);

        if(best==-1) return dp[a][b][newCost]=-1; 

        return dp[a][b][newCost]=grid[a][b]+best;

    }
    int maxPathScore(vector<vector<int>>& grid, int k) {

        x=grid.size();
        y=grid[0].size();

        dp.assign(x,vector<vector<int>>(y,vector<int>(k+1,INT_MIN)));

        return f(grid,0,0,0,k);

    }
};
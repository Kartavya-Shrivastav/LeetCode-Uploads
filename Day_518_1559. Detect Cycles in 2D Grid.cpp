#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a 2D grid of characters, return true if there is a cycle in the grid, or false otherwise. A cycle is a path of length 4 or more in the grid that starts and ends at the same cell and consists of cells that are adjacent (horizontally or vertically) and have the same value.
Approach: We can use Depth First Search (DFS) to detect cycles in the grid. We will maintain a visited array to keep track of the cells we have already visited during our DFS traversal. For each unvisited cell, we will start a DFS and check if we can find a cycle by visiting adjacent cells with the same value. If we encounter a visited cell that is not the parent of the current cell, it means we have found a cycle.

Steps:
1. Create a function dfs that takes the current cell's coordinates, the parent cell's coordinates, the grid, the visited array, and the dimensions of the grid as parameters. This function will perform a DFS and return true if it finds a cycle.
2. In the dfs function, mark the current cell as visited. Then, for each of the four possible directions (up, down, left, right), check if the adjacent cell is within bounds and has the same value as the current cell. If it does, and if it has not been visited, recursively call dfs on that cell. If it has been visited and is not the parent of the current cell, return true to indicate a cycle has been found.
3. In the main function containsCycle, iterate through each cell in the grid. If a cell has not been visited, call the dfs function on that cell. If dfs returns true, return true from containsCycle. If we finish iterating through all cells without finding a cycle, return false.
4. The time complexity of this approach is O(m*n), where m and n are the dimensions of the grid, since we may visit each cell at most once. The space complexity is also O(m*n) in the worst case due to the visited array and the recursion stack in DFS.
5. This solution effectively detects cycles in the grid by leveraging the properties of DFS and the visited array to ensure we do not revisit cells unnecessarily while checking for cycles.

Time Complexity: O(m*n), where m and n are the dimensions of the grid, since we may visit each cell at most once.
Space Complexity: O(m*n) in the worst case due to the visited array and the recursion stack in DFS.
*/

class Solution {
public:
    int dfs(int i, int j, int pi, int pj,
            vector<vector<char>>& grid,
            vector<vector<int>>& isvisited,
            int r , int c){

        isvisited[i][j] = 1;

        // up
        if((i-1)>=0 && grid[i-1][j] == grid[i][j]){
            if(isvisited[i-1][j] == 0){
                if(dfs(i-1, j, i, j, grid, isvisited, r , c)) return 1;
            }
            else if(i-1 != pi || j != pj){
                return 1;
            }
        }

        // down
        if((i+1)<r && grid[i+1][j] == grid[i][j]){
            if(isvisited[i+1][j] == 0){
                if(dfs(i+1, j, i, j, grid, isvisited, r , c)) return 1;
            }
            else if(i+1 != pi || j != pj){
                return 1;
            }
        }

        // left
        if((j-1)>=0 && grid[i][j-1] == grid[i][j]){
            if(isvisited[i][j-1] == 0){
                if(dfs(i, j-1, i, j, grid, isvisited, r , c)) return 1;
            }
            else if(i != pi || j-1 != pj){
                return 1;
            }
        }

        // right
        if((j+1)<c && grid[i][j+1] == grid[i][j]){
            if(isvisited[i][j+1] == 0){
                if(dfs(i, j+1, i, j, grid, isvisited, r , c)) return 1;
            }
            else if(i != pi || j+1 != pj){
                return 1;
            }
        }


        return 0;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        vector<vector<int>> isvisited(rows, vector<int>(cols, 0));

        for(int i=0; i<rows ; i++){
            for(int j=0; j<cols; j++){
                if(isvisited[i][j]==0){
                   int temp = dfs(i, j, -1, -1, grid, isvisited, rows, cols);
                   if(temp == 1){
                        return true;
                   }
                }
            }
        }
        return false;
    }
};
#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a grid of integers where each integer represents a type of street, determine if there is a valid path from the top-left corner to the bottom-right corner. A valid path is one that follows the connections defined by the street types. The street types are defined as follows:
Approach: We can use Breadth First Search (BFS) to explore the grid and check for a valid path. We will maintain a queue to keep track of the cells we need to explore and a visited array to avoid revisiting cells. For each cell, we will check the possible moves based on the street type and ensure that the next cell has a compatible street type that allows for a valid connection.

Steps:
1. Define the allowed moves for each street type in a vector of vectors, where each inner vector contains pairs of integers representing the row and column changes for valid moves.
2. Initialize a queue for BFS and a visited array to keep track of visited cells. Start by pushing the top-left corner (0, 0) into the queue and marking it as visited.
3. While the queue is not empty, pop the front cell and check if it is the bottom-right corner. If it is, return true as we have found a valid path.
4. For the current cell, iterate through the allowed moves based on its street type. For each move, calculate the new row and column indices.
5. Check if the new indices are within bounds and if the cell has not been visited. If valid, check if the next cell's street type allows for a reverse connection back to the current cell. If it does, mark the next cell as visited and push it into the queue.
6. If we exhaust the queue without reaching the bottom-right corner, return false as there is no valid path.

Time Complexity: O(m*n), where m and n are the dimensions of the grid, since we may visit each cell at most once.
Space Complexity: O(m*n) in the worst case due to the visited array and the queue used for BFS.
*/

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // allowed moves for each type
        vector<vector<pair<int,int>>> dir(7);

        dir[1] = {{0,-1},{0,1}};   // left right
        dir[2] = {{-1,0},{1,0}};   // up down
        dir[3] = {{0,-1},{1,0}};   // left down
        dir[4] = {{0,1},{1,0}};    // right down
        dir[5] = {{0,-1},{-1,0}};  // left up
        dir[6] = {{0,1},{-1,0}};   // right up

        queue<pair<int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n,0));

        q.push({0,0});
        vis[0][0] = 1;

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            if(r==m-1 && c==n-1)
                return true;

            // try all moves from current cell
            for(auto [dr,dc] : dir[grid[r][c]]){
                int nr = r + dr;
                int nc = c + dc;

                if(nr<0 || nc<0 || nr>=m || nc>=n || vis[nr][nc])
                    continue;

                // check reverse connection
                for(auto [bdr,bdc] : dir[grid[nr][nc]]){
                    if(nr + bdr == r && nc + bdc == c){
                        vis[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }
            }
        }

        return false;
    }
};
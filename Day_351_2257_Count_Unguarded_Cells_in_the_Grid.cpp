#include <bits/stdc++.h>
using namespace std;

// Problem: Count Unguarded Cells in the Grid
// Approach: Simulate the guarding process by marking cells in the grid

// Steps:
// 1. Initialize a grid and mark walls and guards   
// 2. For each guard, mark all cells in its line of sight until a wall or grid boundary is reached
// 3. Count the remaining unguarded cells
// 4. Return the count of unguarded cells

// Time Complexity: O(m*n) where m and n are the dimensions of the grid
// Space Complexity: O(m*n) for the grid representation

char grid[100000];
class Solution {
public:
    int m, n, comp;
    int d[5] = {0, 1, 0, -1, 0};
    inline int  idx(int r, int c){
        return r*n+c;
    }
    inline void cross(int r, int c) {
        for (int a = 0; a < 4; a++) {
            int di = d[a], dj = d[a + 1];
            for (int i=r+di, j=c+dj; ; i+=di, j+=dj) {
                int pos=idx(i, j);
                if (i<0 || i>=m || j<0 || j>=n || grid[pos] == 'X') break;
                comp-=(grid[pos]==' ');
                grid[pos] = 'V';
            }
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        this->m = m, this->n = n;
        comp=m*n;
        memset(grid, ' ', m*n);
        // Mark walls
        for (auto& ij : walls){
            grid[idx(ij[0], ij[1])] = 'X';
            comp--;
        }
        // Mark guards
        for (auto& ij : guards){
            grid[idx(ij[0], ij[1])] = 'X';
            comp--;
        }
        // Mark Cells Viewed
        for (auto& ij : guards) {
            cross(ij[0], ij[1]);
        }
        return comp;
    }
};
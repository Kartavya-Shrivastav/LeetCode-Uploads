#include <bits/stdc++.h>
using namespace std;

/*
Problem: You are given an m x n matrix of characters grid, representing a box. Each cell of the box is one of the following:
- A stone '#'
- A stationary obstacle '*'
- Empty '.'
The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. The obstacles do not move, and the stones do not pass through the obstacles. It is guaranteed that each stone in grid rests on an obstacle, another stone, or the bottom of the box.
Return an n x m matrix representing the box after the rotation described above.

Approach: We can solve this problem in two steps. First, we will simulate the effect of gravity on the stones in the box. We will iterate through each row of the box and move the stones to their correct positions based on the presence of obstacles and other stones. After that, we will rotate the box 90 degrees clockwise to get the final result.

Steps:
1. Iterate through each row of the box and for each row, we will keep track of the position where the next stone should be placed. We will initialize this position to 0 at the beginning of each row.
2. For each cell in the current row, if we encounter a stone '#', we will swap it with the cell at the current position of the next stone and then increment the position for the next stone. If we encounter an obstacle '*', we will update the position for the next stone to be one cell to the right of the obstacle, since stones cannot pass through obstacles.
3. After we have processed all the rows, we will create a new matrix to store the rotated box. We will iterate through the original box and fill the new matrix according to the rotation rules. Specifically, the element at position (r, c) in the original box will be moved to position (c, rows - 1 - r) in the new matrix.
4. Finally, we will return the new matrix representing the rotated box.

Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the box, since we need to iterate through each cell in the box to simulate gravity and then to rotate the box.
Space Complexity: O(n * m), since we are creating a new matrix to store the rotated box, which has dimensions n x m.
*/

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        for (int r = 0; r < rows; r++) {
            int p = 0;
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '.') {
                    swap(grid[r][c], grid[r][p]);
                    p++;
                } else if (grid[r][c] == '*')
                    p = c + 1;
            }
        }
        
        vector<vector<char>> res(cols, vector<char>(rows));
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                res[c][rows - 1 - r] = grid[r][c];
                
        return res;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Arrays to track numbers in each row, column, and 3x3 box
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        // Iterate through each cell in the 9x9 board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                // If cell is not empty
                if (board[i][j] != '.') {
                    // Convert char to 0-based index (1-9 -> 0-8)
                    int num = board[i][j] - '1';
                    // Calculate which 3x3 box we're in
                    int boxIndex = (i / 3) * 3 + (j / 3);
                    
                    // Check if number already exists in row, column, or box
                    if (rows[i][num] || cols[j][num] || boxes[boxIndex][num]) 
                        return false;
                    
                    // Mark number as seen in row, column, and box
                    rows[i][num] = cols[j][num] = boxes[boxIndex][num] = true;
                }
            }
        }
        return true;
    }
};
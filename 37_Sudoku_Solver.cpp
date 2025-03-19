#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool rowCheck[9][9] = {false};
        bool colCheck[9][9] = {false};
        bool blockCheck[3][3][9] = {false};
        bool isSolved = false;

        vector<pair<int, int>> emptyPositions;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    emptyPositions.push_back({i, j});
                } else {
                    int value = board[i][j] - '1';
                    rowCheck[i][value] = colCheck[j][value] = blockCheck[i / 3][j / 3][value] = true;
                }
            }
        }

        function<void(int)> dfs = [&](int index) {
            if (index == emptyPositions.size()) {
                isSolved = true;
                return;
            }
            int row = emptyPositions[index].first;
            int col = emptyPositions[index].second;

            for (int value = 0; value < 9; ++value) {
                if (!rowCheck[row][value] && !colCheck[col][value] && !blockCheck[row / 3][col / 3][value]) {
                    rowCheck[row][value] = colCheck[col][value] = blockCheck[row / 3][col / 3][value] = true;
                    board[row][col] = value + '1';

                    dfs(index + 1);

                    if (isSolved) {
                        return;
                    }

                    rowCheck[row][value] = colCheck[col][value] = blockCheck[row / 3][col / 3][value] = false;
                }
            }
        };
        dfs(0);
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns the minimum number of moves to reach the last square in Snakes and Ladders
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        // min_rolls[i]: minimum rolls needed to reach square i, -1 if not visited
        vector<int> min_rolls(n * n + 1, -1);
        queue<int> q;
        min_rolls[1] = 0; // Start from square 1
        q.push(1);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            // Try all possible dice rolls (1 to 6)
            for (int i = 1; i <= 6 && x + i <= n * n; i++) {
                int t = x + i;
                // Calculate row and column for square t
                int row = (t - 1) / n, col = (t - 1) % n;
                // Adjust column for zigzag board numbering
                int v = board[n - 1 - row][row % 2 ? n - 1 - col : col];
                // If there's a snake or ladder, move to its destination
                int y = v > 0 ? v : t;
                // If reached the last square, return the answer
                if (y == n * n)
                    return min_rolls[x] + 1;
                // If not visited, mark and enqueue
                if (min_rolls[y] == -1) {
                    min_rolls[y] = min_rolls[x] + 1;
                    q.push(y);
                }
            }
        }
        // If unreachable, return -1
        return -1;
    }
};
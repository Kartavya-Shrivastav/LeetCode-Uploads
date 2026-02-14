#include <bits/stdc++.h>
using namespace std;

// Problem: We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on until the 100th row. Each glass holds one cup of champagne. We pour some champagne into the first glass at the top. When the topmost glass is full, any excess liquid poured will fall equally to the left and right glasses of the next row. When those glasses become full, any excess champagne will fall equally to the left and right glasses of the next row, and so on. We want to know how full a specific glass is after pouring a certain amount of champagne.
// Approach: We can simulate the pouring process using a 2D array to represent the glasses. We start by pouring the champagne into the top glass and then iteratively distribute any excess champagne to the glasses in the next row. We continue this process until we have processed all rows up to the query row. Finally, we return the amount of champagne in the specified glass, ensuring that it does not exceed 1 cup.

// Steps:
// 1. Create a 2D array to represent the glasses in the tower, initialized to 0.
// 2. Pour the champagne into the top glass.
// 3. Iterate through each row and distribute any excess champagne to the glasses in the next row.
// 4. After processing all rows up to the query row, return the amount of champagne in the specified glass, ensuring it does not exceed 1 cup.
// 5. Handle edge cases where the poured amount is less than or equal to 1, in which case we can directly return the poured amount for the top glass.

// Time Complexity: O(query_row^2) since we need to process each glass up to the query row.
// Space Complexity: O(query_row^2) for the 2D array representing the glasses

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double tower[102][102] = {0.0};
        tower[0][0] = (double)poured;
        
        for (int r = 0; r <= query_row; r++) {
            for (int c = 0; c <= r; c++) {
                if (tower[r][c] > 1.0) {
                    double excess = (tower[r][c] - 1.0) / 2.0;
                    tower[r][c] = 1.0;
                    tower[r + 1][c] += excess;
                    tower[r + 1][c + 1] += excess;
                }
            }
        }
        return tower[query_row][query_glass];
    }
};
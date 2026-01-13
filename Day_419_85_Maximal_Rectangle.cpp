#include <bits/stdc++.h>
using namespace std;

// Problem: 85. Maximal Rectangle
// Approach: Dynamic Programming with boundary tracking for each row.

// Steps:
// 1. Initialize three arrays: left, right, and height to keep track of the left boundary, right boundary, and height of '1's for each column.
// 2. Iterate through each row of the matrix:   
//    - Update the height array: increment height for '1's and reset to 0 for '0's.
//    - Update the left boundary array: for '1's, update left[j] to the maximum of current left[j] and current left boundary; for '0's, reset left[j] and update current left boundary.
//    - Update the right boundary array: for '1's, update right[j] to the minimum of current right[j] and current right boundary; for '0's, reset right[j] and update current right boundary.
//    - Calculate the area for each column using the formula (right[j] - left[j]) * height[j] and update the maximum area found.
// 3. Return the maximum area found.

// Time Complexity: O(n*m), where n is the number of rows and m is the number of columns in the matrix.
// Space Complexity: O(m) for the three auxiliary arrays.

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int n = grid.size(), m = grid[0].size();
        vector<int> left(m, 0);    // left boundary of current height
        vector<int> right(m, m);   // right boundary of current height  
        vector<int> height(m, 0);  
        
        int ans = 0;
        for (int i = 0 ; i < n ; ++ i) {
            int lft = 0, rgt = m;
            
            for (int j = 0 ; j < m ; ++ j) {
                if (grid[i][j] == '1') {
                    height[j] += 1; 
                }
                else height[j] = 0;
            }

            for (int j = 0 ; j < m ; ++ j) {
                if (grid[i][j] == '1') {
                    left[j] = max(left[j], lft);
                }
                else lft = j + 1, left[j] = 0; 
            }

            for (int j = m - 1; j >= 0 ; --j) {
                if (grid[i][j] == '1') {
                    right[j] = min(right[j], rgt); 
                }
                else rgt = j, right[j] = m;
            }

            for (int j = 0; j < m ; ++ j) {
                ans = max(ans , (right[j] - left[j]) * height[j]) ;
            }

        }        

        return ans;
    }
};
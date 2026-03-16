#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a 2D grid of integers, find the biggest three distinct rhombus sums in the grid. A rhombus sum is defined as the sum of the integers on the border of a rhombus shape in the grid. The rhombus can be of size 0 (a single cell) or larger.
Approach: We can iterate through each cell in the grid and treat it as the top vertex of a rhombus. We will then try to expand the rhombus downwards while ensuring that we do not go out of bounds. For each valid rhombus, we will calculate the sum of its border and store it in a set to maintain distinct sums. Finally, we will extract the three largest sums from the set.

Steps:
1. Initialize a set to store distinct rhombus sums.
2. Iterate through each cell in the grid as the top vertex of the rhombus.
3. For each cell, try to expand the rhombus downwards by increasing the size k.
4. For each valid rhombus, calculate the sum of its border by traversing the four sides of the rhombus.
5. Insert the calculated sum into the set.
6. After processing all cells, extract the three largest sums from the set and return them as a vector.

Time Complexity: O(m*n*k) where m and n are the dimensions of the grid and k is the maximum size of the rhombus. In the worst case, k can be O(min(m, n)).
Space Complexity: O(m*n) in the worst case for storing distinct sums in the set, and O(1) for the output vector since we are only storing three sums.  
*/

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        set<int> st;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                // size 0 rhombus
                st.insert(grid[i][j]);

                for(int k = 1; ; k++) {

                    int r = i + 2*k;
                    int left = j - k;
                    int right = j + k;

                    if(r >= m || left < 0 || right >= n) break;

                    int sum = 0;

                    int x = i, y = j;

                    // top -> right
                    for(int t = 0; t < k; t++) {
                        sum += grid[x + t][y + t];
                    }

                    // right -> bottom
                    for(int t = 0; t < k; t++) {
                        sum += grid[x + k + t][y + k - t];
                    }

                    // bottom -> left
                    for(int t = 0; t < k; t++) {
                        sum += grid[x + 2*k - t][y - t];
                    }

                    // left -> top
                    for(int t = 0; t < k; t++) {
                        sum += grid[x + k - t][y - k + t];
                    }

                    st.insert(sum);
                }
            }
        }

        vector<int> ans;
        for(auto it = st.rbegin(); it != st.rend() && ans.size() < 3; ++it) {
            ans.push_back(*it);
        }

        return ans;
    }
};
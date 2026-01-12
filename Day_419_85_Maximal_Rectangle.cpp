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
#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a 2D matrix of integers and an integer k, find the minimum absolute difference between any two distinct integers in every k x k submatrix of the given matrix. If there are no two distinct integers in a submatrix, the minimum absolute difference is considered to be 0.
Approach: We can use a sliding window approach to solve this problem efficiently. We will iterate through the matrix and for each k x k submatrix, we will maintain a frequency map of the integers in that submatrix. We will calculate the minimum absolute difference between any two distinct integers in the frequency map. As we slide the window to the right, we will update the frequency map by removing the leftmost column and adding the new rightmost column.

Steps:
1. Initialize a 2D vector ans to store the results for each k x k submatrix.
2. Iterate through the matrix with a sliding window of size k x k.
3. For each k x k submatrix, maintain a frequency map of the integers in that submatrix.
4. Calculate the minimum absolute difference between any two distinct integers in the frequency map.
5. Update the frequency map as we slide the window to the right by removing the leftmost column and adding the new rightmost column.
6. Return the final 2D vector ans containing the minimum absolute differences for each k x k submatrix.

Time Complexity: O(n * m * k) where n is the number of rows, m is the number of columns, and k is the size of the submatrix. This is because we need to iterate through each k x k submatrix and calculate the minimum absolute difference.
Space Complexity: O(k^2) for the frequency map used to store the integers in the current k x k submatrix.
*/

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));
        for (int i = 0; i <= n - k; i++) {
            map<int, int> mp;
            for (int r = i; r < i + k; r++) {
                for (int c = 0; c < k; c++) {
                    mp[grid[r][c]]++;
                }
            }
            for (int c = 0; c <= m - k; c++) {
                if (mp.size() > 1) {
                    int mini = 1e9;
                    auto it = mp.begin();
                    int prev = it->first;
                    for (++it; it != mp.end(); it++) {
                        mini = min(mini, abs(it->first - prev));
                        prev = it->first;
                    }
                    ans[i][c] = mini;
                } else {
                    ans[i][c] = 0;
                }

                if (c < m - k) {
                    for (int r = i; r < i + k; r++) {
                        mp[grid[r][c]]--;
                        if (mp[grid[r][c]] == 0)
                            mp.erase(grid[r][c]);
                        mp[grid[r][c + k]]++;
                    }
                }
            }
        }
        return ans;
    }
};
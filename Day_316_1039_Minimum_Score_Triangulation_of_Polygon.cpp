#include <bits/stdc++.h>
using namespace std;

// Problem: 1039. Minimum Score Triangulation of Polygon
// Approach: Dynamic Programming

// Steps:
// 1. Use a 2D DP array to store the minimum score for triangulating sub-polygons.
// 2. Recursively calculate the minimum score for each sub-polygon by trying all possible triangulations.
// 3. The base case is when the sub-polygon has less than 3 vertices, where the score is 0.
// 4. Return the minimum score for the entire polygon.

// Time Complexity: O(n^3), where n is the number of vertices in the polygon.
// Space Complexity: O(n^2) for the DP table.

class Solution {
public:
    int dp[50][50] = {};
    
    int minScoreTriangulation(vector<int>& values, int i = 0, int j = 0, int res = 0) {
        if (j == 0) j = values.size() - 1;
        if (dp[i][j] != 0) return dp[i][j];
        for (int k = i + 1; k < j; ++k) {
            res = min(res == 0 ? INT_MAX : res,
                minScoreTriangulation(values, i, k) + 
                values[i] * values[k] * values[j] + 
                minScoreTriangulation(values, k, j));
        }
        return dp[i][j] = res;
    }
};
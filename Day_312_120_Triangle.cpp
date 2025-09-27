#include <bits/stdc++.h>
using namespace std;

// Problem: 120. Triangle
// Approach: Bottom-Up Dynamic Programming

// Steps:
// 1. Start from the second last row of the triangle and move upwards.
// 2. For each element, add the minimum of the two elements directly below it.
// 3. Continue this process until you reach the top of the triangle.
// 4. The top element will contain the minimum path sum.
// 5. Return the top element as the result.

// Time Complexity: O(n^2), where n is the number of rows in the triangle.
// Space Complexity: O(1), as we are modifying the triangle in place.

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--)
            for (int j = 0; j < triangle[i].size(); j++)
                triangle[i][j] +=
                    min(triangle[i + 1][j], triangle[i + 1][j + 1]);

        return triangle[0][0];
    }
};
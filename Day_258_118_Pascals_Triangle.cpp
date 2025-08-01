#include <bits/stdc++.h>
using namespace std;

// Problem: Generate Pascal's Triangle up to a specified number of rows.
// Approach: Use a nested loop to build each row based on the previous row's values.

// Steps:
// 1. Initialize a vector to hold the rows of Pascal's Triangle.
// 2. Start with the first row containing a single element, 1.
// 3. For each subsequent row, initialize it with 1 at the start and end.
// 4. Compute the inner elements of the row by summing the two elements directly above from the previous row.
// 5. Append the completed row to the triangle.
// 6. Repeat until the desired number of rows is generated.

// Time Complexity: O(numRows^2) since each row takes linear time to compute.
// Space Complexity: O(numRows^2) for storing the triangle.

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        triangle.push_back({1});

        for (int rowNum = 1; rowNum < numRows; ++rowNum) {
            vector<int> row;
            vector<int>& prevRow = triangle[rowNum - 1];

            row.push_back(1);

            for (int j = 1; j < rowNum; ++j) {
                row.push_back(prevRow[j - 1] + prevRow[j]);
            }

            row.push_back(1);
            triangle.push_back(row);
        }

        return triangle;
    }
};
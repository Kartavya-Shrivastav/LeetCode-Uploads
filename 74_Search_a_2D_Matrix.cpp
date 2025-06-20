#include <bits/stdc++.h>
using namespace std;

// Problem: Search a 2D matrix for a target value.
// Approach: Use binary search to find the target in a row-wise sorted 2D matrix.

// Steps:
// 1. Perform a binary search on the rows to find the row that may contain the target.
// 2. Once the row is found, perform a binary search on that row to find the target.
// 3. Return true if the target is found, otherwise return false.

// Time Complexity: O(log(m) + log(n)), where m is the number of rows and n is the number of columns.
// Space Complexity: O(1), since we are not using any additional data structures that grow with input size.

class Solution {
public:
    bool rowSearch(vector<int>& matrix, int target) {
        int low = 0;
        int high = matrix.size() - 1;
        while (high >= low) {
            int mid = (low + high) / 2;
            if (matrix[mid] == target) {
                return true;
            } else if (matrix[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = 0;
        int high = rows - 1;

        while (high >= low) {
            int mid = low + (high - low) / 2;

            if (target >= matrix[mid][0] && target <= matrix[mid][cols - 1]) {

                if (rowSearch(matrix[mid], target))
                    return true;
                else
                    return false;

            } else if (target < matrix[mid][0]) {

                high = mid - 1;

            } else {

                low = mid + 1;
            }
        }
        return false;
    }
};
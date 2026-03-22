#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.
Approach: We can check all four possible rotations of the matrix mat (0 degrees, 90 degrees, 180 degrees, and 270 degrees) against the target matrix. We can use bitwise operations to keep track of which rotations are still possible as we compare the elements of mat and target. If at any point we find a mismatch for a particular rotation, we can eliminate that rotation from consideration. If after checking all elements we still have at least one valid rotation, we return true; otherwise, we return false.

Steps:
1. Initialize a variable m to 0b1111 (binary representation of 15) to represent the four possible rotations (0, 90, 180, 270 degrees).
2. Iterate through each element of the mat and compare it with the corresponding elements in the target for each of the four rotations.
3. If a mismatch is found for a particular rotation, use bitwise AND to eliminate that rotation from consideration.
4. After checking all elements, if m is not zero, it means at least one rotation is still valid, so return true; otherwise, return false.
5. Return the result based on the value of m after the loop.

Time Complexity: O(n^2) where n is the size of the matrix. We need to compare each element of the mat with the corresponding elements in the target for all four rotations.
Space Complexity: O(1) since we are using a constant amount of extra space to keep track of the valid rotations.
*/

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        int m = 0b1111;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != target[i][j]) m &= 0b1110;
                if (mat[i][j] != target[j][n - 1 - i]) m &= 0b1101;
                if (mat[i][j] != target[n - 1 - i][n - 1 - j]) m &= 0b1011;
                if (mat[i][j] != target[n - 1 - j][i]) m &= 0b0111;
                if (m == 0) return false;
            }
        }

        return m != 0;
    }
};
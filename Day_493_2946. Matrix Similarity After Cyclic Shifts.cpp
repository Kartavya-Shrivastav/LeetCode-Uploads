#include <bits/stdc++.h>
using namespace std;


/*
Problem: Given a 2D matrix of integers and an integer k, determine if the matrix is similar to itself after performing cyclic shifts on its rows. A cyclic shift on a row means that the elements of the row are shifted to the left or right by k positions, and the elements that fall off one end are reintroduced at the other end. The similarity condition requires that for every even-indexed row (0-based), a left cyclic shift by k positions results in the same row, and for every odd-indexed row, a right cyclic shift by k positions results in the same row.
Approach: We can iterate through each row of the matrix and check the similarity condition for even and odd indexed rows. For even indexed rows, we will check if the element at position j is equal to the element at position (j + k) % n, where n is the number of columns. For odd indexed rows, we will check if the element at position j is equal to the element at position (j - k + n) % n. If any row does not satisfy the condition, we can return false immediately. If all rows satisfy the condition, we return true.

Steps:
1. Determine the number of rows (m) and columns (n) in the matrix.
2. Reduce k by taking k modulo n to handle cases where k is greater than the number of columns.
3. Iterate through each row of the matrix:
    a. For even indexed rows, check if the element at position j is equal to the element at position (j + k) % n for all j.
    b. For odd indexed rows, check if the element at position j is equal to the element at position (j - k + n) % n for all j.
4. If any row does not satisfy the condition, return false.
5. If all rows satisfy the condition, return true.

Time Complexity: O(m * n) where m is the number of rows and n is the number of columns in the matrix. We need to check each element in the matrix to verify the similarity condition.
Space Complexity: O(1) as we are using only a few variables to store the dimensions of the matrix and the value of k, regardless of the size of the input matrix.
*/
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        k %= n;  //(reduce k<n)

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) {
                    // even row , left rotate
                    if (mat[i][j] != mat[i][(j + k) % n])
                        return false;
                } else {
                    // odd row , right rotate
                    if (mat[i][j] != mat[i][(j - k + n) % n])
                        return false;
                }
            }
        }

        return true;
    }
};
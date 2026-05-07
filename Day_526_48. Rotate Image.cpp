#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise). You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
Approach: We can rotate the matrix in-place by performing a layer-by-layer rotation. For each layer, we will rotate the elements in groups of four. Specifically, for each element in the current layer, we will move it to its new position in the rotated matrix, and then move the other three elements in the group to their new positions as well. We will repeat this process for all layers until we have rotated the entire matrix.

Steps:
1. Determine the number of layers in the matrix, which is n / 2.    
2. For each layer, iterate through the elements in the current layer and perform the rotation for each group of four elements.
    a. Store the value of the current element in a temporary variable.
    b. Move the element from the left side of the group to the top position.
    c. Move the element from the bottom side of the group to the left position.
    d. Move the element from the right side of the group to the bottom position.
    e. Move the value stored in the temporary variable to the right position.

Time Complexity: O(n^2), where n is the size of the matrix, since we are iterating through each element in the matrix once to perform the rotation.
Space Complexity: O(1), since we are performing the rotation in-place and only using a constant amount of extra space to store temporary variables for the rotation.
*/

class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size(), k = n - 1;
        for (int i = 0; i < n >> 1; i++)
            for (int j = i; j < k - i; j++) {
                int t = mat[i][j];
                mat[i][j] = mat[k - j][i];
                mat[k - j][i] = mat[k - i][k - j];
                mat[k - i][k - j] = mat[j][k - i];
                mat[j][k - i] = t;
            }
    }
};
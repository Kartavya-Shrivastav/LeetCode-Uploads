#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a 2D grid of integers, construct a product matrix where each element at position (i, j) is the product of all elements in the grid except the one at (i, j). The product should be taken modulo 12345.
Approach: We can use two passes to construct the product matrix. In the first pass, we calculate the prefix product for each element in the grid, which is the product of all elements before it in a row-wise manner. In the second pass, we calculate the suffix product for each element, which is the product of all elements after it in a row-wise manner. The final product for each element can be obtained by multiplying its prefix and suffix products together, and taking the result modulo 12345.

Steps:
1. Initialize a constant N to 12345, and get the dimensions of the grid (n and m).
2. Create an answer matrix of the same dimensions as the grid, initialized with zeros.
3. Initialize a variable pref to 1, which will hold the prefix product.
4. Iterate through the grid in a row-wise manner, updating the answer matrix with the prefix product for each element and updating pref with the current element's value.
5. Initialize a variable suf to 1, which will hold the suffix product.
6. Iterate through the grid in reverse row-wise manner, updating the answer matrix with the suffix product for each element and updating suf with the current element's value.

Time Complexity: O(n*m) where n is the number of rows and m is the number of columns in the grid. We need to iterate through the grid twice to calculate the prefix and suffix products.
Space Complexity: O(n*m) for the answer matrix, which is required to store the product
for each element in the grid.
*/

class Solution {
public:
    static vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int N=12345, n=grid.size(), m=grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        uint64_t pref=1, suf=1;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++){
                ans[i][j]=pref;
                pref=pref*grid[i][j]%N;
            }
        for(int i=n-1; i>=0; i--)
            for(int j=m-1; j>=0; j--){
                ans[i][j]=ans[i][j]*suf%N;
                suf=suf*grid[i][j]%N;
            }
        return ans;
    }
};
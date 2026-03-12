#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an m x n binary matrix mat, return the number of special positions in the matrix.
A position (i, j) is called special if:
- mat[i][j] == 1
- All other elements in row i are 0
- All other elements in column j are 0

Approach:
The idea is to check every cell of the matrix. Whenever we encounter a cell containing '1',
we verify whether it is the only '1' in its row and column.

To achieve this:
1. Use a helper function rowc() to check if the row contains any other '1' apart from the current position.
2. Use another helper function colc() to check if the column contains any other '1' apart from the current position.
3. If both conditions are satisfied, then the position is a special position and we increment the answer.

Steps:
1. Get the number of rows m and columns n.
2. Traverse every cell (i, j) in the matrix.
3. If mat[i][j] == 1:
   - Call rowc(mat, i, j) to ensure no other '1' exists in row i.
   - Call colc(mat, i, j) to ensure no other '1' exists in column j.
4. If both functions return true, increment the counter.
5. After checking all cells, return the final count.

Helper Functions:
- rowc(mat, x, y): Checks row x and ensures that all elements except column y are 0.
- colc(mat, x, y): Checks column y and ensures that all elements except row x are 0.

Time Complexity: O(m * n * (m + n))
- We traverse all m*n cells.
- For each '1', we may scan the entire row (n) and column (m).

Space Complexity: O(1)
- Only a few variables are used; no additional data structures are required.
*/

class Solution {
public:
    bool rowc(vector<vector<int>>& mat,int x,int y){
        int m = mat.size() ;
        int n = mat[0].size() ;

        for(int j=0 ;j<n ;j++){
            if(y!=j){
                if(mat[x][j]) return false ;
            }
        }

        return true ;
    }

    bool colc(vector<vector<int>>& mat,int x,int y){
        int m = mat.size() ;
        int n = mat[0].size() ;

        for(int j=0 ;j<m ;j++){
            if(x!=j){
                if(mat[j][y]) return false ;
            }
        }

        return true ;
    }


    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0 ;
        int m = mat.size() ;
        int n = mat[0].size() ;

        for(int i=0 ;i<m ;i++){
            for(int j=0 ;j<n ;j++){
                if(mat[i][j] == 1 && rowc(mat,i,j) && colc(mat,i,j)) ans++ ;
            }
        }

        return ans ;
    }
};
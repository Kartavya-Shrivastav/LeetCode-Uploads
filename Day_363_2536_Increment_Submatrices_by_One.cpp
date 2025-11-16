#include <bits/stdc++.h>
using namespace std;

// Problem: Given an n x n matrix initialized with all 0's and a list of queries where each query consists of four integers [r1, c1, r2, c2] representing the top-left and bottom-right coordinates of a submatrix, increment all elements within that submatrix by 1. Return the final matrix after processing all queries.
// Approach: 

// Steps:
// 1. 
// 2. 

// Time Complexity: O(n^2 + q) where n is the size of the matrix and q is the number of queries.
// Space Complexity: O(n^2) for the difference array.   


class Solution {
public:
    static vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>  arr(n+1, vector<int>(n, 0));
        for(auto& q: queries){
            const int r1=q[0], c1=q[1], r2=q[2], c2=q[3];
            arr[r1][c1]++;
            arr[r2+1][c1]--;
            if (c2+1<n){
                arr[r1][c2+1]--;
                arr[r2+1][c2+1]++;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=1; j<n; j++)
                arr[i][j]+=arr[i][j-1];
        }
        for(int j=0; j<n; j++){
            for(int i=1; i<n; i++)
                arr[i][j]+=arr[i-1][j];
        }
        arr.resize(n);
        return arr;
    }
};
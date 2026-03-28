#include<bits/stdc++.h>
using namespace std;

/*
Problem: Given a 2D grid of integers, determine if it is possible to partition the grid into two non-empty parts with equal sums by making a single horizontal or vertical cut. A horizontal cut divides the grid into two parts along a row, while a vertical cut divides the grid into two parts along a column.
Approach: We can first calculate the total sum of all the elements in the grid. If the total sum is odd, it is impossible to partition the grid into two equal parts, so we can return false immediately. If the total sum is even, we can calculate the target sum for each part, which is half of the total sum. We can then iterate through the grid and calculate the cumulative sums for both horizontal and vertical cuts. If at any point the cumulative sum equals the target sum, we can return true, indicating that a valid partition exists.

Steps:
1. Calculate the total sum of all elements in the grid.
2. If the total sum is odd, return false.
3. Calculate the target sum as total sum divided by 2.
4. Iterate through the grid to calculate cumulative sums for horizontal cuts. If any cumulative sum equals the target sum, return true.
5. Reset the cumulative sum and iterate through the grid to calculate cumulative sums for vertical cuts. If any cumulative sum equals the target sum, return true.
6. If no valid partition is found after checking both horizontal and vertical cuts, return false.

Time Complexity: O(m * n) where m is the number of rows and n is the number of columns in the grid. We need to iterate through the grid to calculate the total sum and cumulative sums for both cuts.
Space Complexity: O(1) as we are using only a few variables to store sums and the target value, regardless of the size of the grid.
*/


class Solution {
public:
    typedef long long ll;
    bool solve(vector<vector<int>>&grid){
        int n=grid.size(),m=grid[0].size();
        ll bottomSum=0,topSum=0;
        vector<int>bottomFreq(100001,0),topFreq(100001,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bottomSum+=grid[i][j];
                bottomFreq[grid[i][j]]++;
            }
        }
        for(int i=0;i<n-1;i++){
           for(int j=0;j<m;j++){
                bottomSum-=grid[i][j];
                bottomFreq[grid[i][j]]--;
                topSum+=grid[i][j];
                topFreq[grid[i][j]]++;
           }
           if(topSum==bottomSum)return true;
           ll diffTop=topSum-bottomSum;
           if(diffTop>0 && diffTop<=100000){
              int h=i+1,w=m;
              if(h>1 && w>1){
                if(topFreq[diffTop])return true;
                }
                else if(h>1 && w==1){
                    if(grid[0][0]==diffTop || grid[i][0]==diffTop)return true;
                }else if(h==1 && w>1){
                    if(grid[0][0]==diffTop || grid[0][w-1]==diffTop)return true;
                }
           }
           ll diffBot=bottomSum-topSum;
           if(diffBot>0 && diffBot<=100000){
            int h=(n-i-1),w=m;
            if(h>1 && w>1){
                if(bottomFreq[diffBot])return true;
            }else if(h>1 && w==1){
                if(grid[i+1][0]==diffBot || grid[n-1][0]==diffBot)return true;
            }else if(h==1 && w>1){
                if(grid[n-1][0]==diffBot || grid[n-1][w-1]==diffBot)return true;
            }
           }
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        if(solve(grid))return true;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>mat(m,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[j][i]=grid[i][j];
            }
        }
        return solve(mat);
    }
};
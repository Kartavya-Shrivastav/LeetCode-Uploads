#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a 2D grid of integers representing the longest common prefix (LCP) lengths between pairs of strings, find the original string that corresponds to the given LCP grid. If there are multiple valid strings, return any one of them. If there is no valid string, return an empty string.
Approach: We can reconstruct the original string by iterating through the LCP grid. We will start with an empty string and fill it based on the LCP values. For each pair of indices (i, j), if the LCP value is greater than 0, it means that the characters at those positions in the original string must be the same. We can use a character variable to assign characters to the string as we iterate through the grid. After filling the string, we will verify if the constructed string matches the LCP grid by calculating the LCP values for all pairs of indices and comparing them with the given grid.

Steps:
1. Initialize an empty string of length n (where n is the size of the LCP grid) and a character variable starting from 'a'.
2. Iterate through the LCP grid. For each pair of indices (i, j), if the LCP value is greater than 0, assign the same character to both positions in the string.
3. After filling the string, create a new 2D grid to calculate the LCP values for the constructed string.
4. Compare the calculated LCP grid with the given LCP grid. If they match, return the constructed string; otherwise, return an empty string.

Time Complexity: O(n^2) for filling the string and verifying the LCP grid, where n is the size of the LCP grid.
Space Complexity: O(n^2) for the LCP grid and the constructed string, where n is the size of the LCP grid.
*/

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n=lcp.size();
        string ans(n,0);
        char ch='a';
        for(int i=0;i<n;i++){
            if(ans[i]!=0)continue;
            if(ch>'z')return "";
            for(int j=i;j<n;j++){
                if(lcp[i][j])ans[j]=ch;
            }
            ch++;
        }
        vector<vector<int>>mat(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(ans[i]==ans[j])mat[i][j]=mat[i+1][j+1]+1;
                else mat[i][j]=0;
                if(mat[i][j]!=lcp[i][j])return "";
            }
        }
        return ans;
    }
};
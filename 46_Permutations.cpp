#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int factorial(int n){
        return (n==1 || n==0) ? 1: n * factorial(n - 1);
    }

    vector<vector<int>> permute(vector<int>& nums){
        int f = factorial(nums.size());
        vector<vector<int>> ans;
        for(int i=0; i<f; i++){
            ans.push_back(nums);
            next_permutation(nums.begin(), nums.end());
        }

        return ans;
    }
};
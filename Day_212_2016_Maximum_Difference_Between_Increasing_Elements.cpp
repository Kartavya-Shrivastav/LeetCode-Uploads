#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of integers, find the maximum difference between two elements such that the larger element comes after the smaller one.
// Approach: Use two pointers to traverse the array from both ends, keeping track of the minimum and maximum values seen so far, and calculate the maximum difference.

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int maxD=-1, xMinL=1e9, xMaxR=-1;
        for(int l=0, r=n-1; l<r; l++){
            xMinL=min(nums[l], xMinL);
            while(l<r && nums[l+1]>nums[l]){
                l++;
                maxD=max(maxD, nums[l]-xMinL);
            }
            xMaxR=max(nums[r], xMaxR);
            while(l<r && nums[r-1]<nums[r]){
                r--;
                maxD=max(maxD, nums[r]-xMaxR);
            }
            maxD=max(maxD, xMaxR-xMinL);
        } 
        return maxD==0?-1:maxD;
    }
};
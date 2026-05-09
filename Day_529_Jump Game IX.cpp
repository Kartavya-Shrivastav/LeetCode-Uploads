#include <bits/stdc++.h>
using namespace std;

/*
Problem: You are given a 0-indexed integer array nums of length n. The value of the i-th element of nums is the maximum jump length from that position (i.e., you can jump at most nums[i] steps forward from that position). You are initially positioned at index 0. Return an array of length n where the i-th element is the maximum reachable index from index i (inclusive) if you start at index i and make jumps according to the values in nums.   
Approach: We can solve this problem by using two auxiliary arrays, prefMax and sufMin. The prefMax array will store the maximum jump length from the start to the current index, while the sufMin array will store the minimum jump length from the end to the current index. We can then iterate through the nums array and fill these two auxiliary arrays accordingly. Finally, we can iterate through the nums array again and compare the values in prefMax and sufMin to determine the maximum reachable index for each position.

Steps:
1. Initialize two auxiliary arrays, prefMax and sufMin, of the same length as nums. The prefMax array will store the maximum jump length from the start to the current index, while the sufMin array will store the minimum jump length from the end to the current index.
2. Fill the prefMax array by iterating through the nums array from left to right. For each index i, set prefMax[i] to the maximum of prefMax[i-1] and nums[i].
3. Fill the sufMin array by iterating through the nums array from right to left. For each index i, set sufMin[i] to the minimum of sufMin[i+1] and nums[i].
4. Initialize an answer array ans of the same length as nums. Set ans[n-1] to prefMax[n-1], since the maximum reachable index from the last position is just the value at that position.
5. Iterate through the nums array from right to left (starting from n-2 down to 0). For each index i, compare prefMax[i] and sufMin[i+1]. If prefMax[i] is greater than sufMin[i+1], it means that the maximum reachable index from index i is the same as the maximum reachable index from index i+1, so we set ans[i] to ans[i+1]. Otherwise, we set ans[i] to prefMax[i], since that is the maximum jump length from index i.    

Time Complexity: O(n), where n is the length of the nums array, since we need to iterate through the nums array three times to fill the prefMax and sufMin arrays and to compute the final answer.
Space Complexity: O(n), since we are using two auxiliary arrays, prefMax and sufMin, of the same length as nums, and an answer array ans of the same length as nums to store the final results.
*/

class Solution {
public:
    static vector<int> maxValue(vector<int>& nums) {
        const int n=nums.size();
        vector<int> prefMax(n), sufMin(n);// vector option
        prefMax[0]=nums[0];
        sufMin[n-1]=nums[n-1];

        for(int i=1; i<n; i++){
            const int x=nums[i], y=nums[n-1-i];
            prefMax[i]=max(prefMax[i-1], x);
            sufMin[n-1-i]=min(sufMin[n-i], y);
        }
        vector<int> ans(n);
        ans[n-1]=prefMax[n-1];
        for(int i=n-2; i>=0; i--){
            if (prefMax[i]>sufMin[i+1]) 
                ans[i]=ans[i+1];
            else ans[i]=prefMax[i];
        }
        return ans;
    }
};
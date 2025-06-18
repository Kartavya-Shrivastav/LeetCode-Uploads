#include <bits/stdc++.h>
using namespace std;

// Problem: Divide an array into groups of three such that the maximum difference between the smallest and largest number in each group is at most k.
// Approach: Sort the array and then group elements in threes, checking the difference condition.
// Steps:
// 1. Sort the array.
// 2. Iterate through the sorted array in steps of three.
// 3. For each group of three, check if the difference between the maximum and minimum is within k.
// 4. If any group does not satisfy the condition, return an empty vector.
// 5. Otherwise, return the groups formed.

// Time Complexity: O(n log n) for sorting, O(n) for grouping, where n is the size of the array.

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i+=3){
            if(nums[i+2]-nums[i]>k) return {};
            ans.push_back({nums[i],nums[i+1],nums[i+2]});
        }
        return ans;
    }
};
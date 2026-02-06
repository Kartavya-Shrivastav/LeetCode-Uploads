#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array of integers and an integer k, find the minimum number of elements that need to be removed from the array so that for every remaining element x, there exists another element y in the array such that x * k >= y.  
// Approach: We can sort the array and use a two-pointer technique to find the longest subarray that satisfies the condition. The minimum number of removals will be the total number of elements minus the length of this longest subarray.

// Steps:
// 1. Sort the array to facilitate the two-pointer approach.    
// 2. Initialize two pointers, l and r, to the beginning of the array.
// 3. Iterate through the array with the right pointer r. For each element at r 
//   - Move the left pointer l to the right as long as the condition nums[l] * k < nums[r] is not satisfied.
//   - Calculate the length of the current valid subarray (r - l + 1) and update the minimum removals accordingly.
// 4. Return the minimum number of removals calculated.

// Time Complexity: O(N log N) due to sorting, where N is the number of elements in the array. The two-pointer traversal takes O(N).
// Space Complexity: O(1) if we ignore the space used for sorting, otherwise O(N) due to the sorting algorithm's space complexity.
class Solution {
public:
    using ll=long long;
    static int minRemoval(vector<int>& nums, int k) {
        const int n=nums.size();
        sort(nums.begin(), nums.end());
        
        if ((ll)nums[0]*k>=nums.back()) return 0;
        
        int ans=n;
        for(int l=0, r=0; r<n; r++){
            const int x=nums[r];
        
            while(l<r && (ll)nums[l]*k<x) 
                l++;
        
            ans = min(ans, n-(r-l+1));
        }
        return ans;
    }
};
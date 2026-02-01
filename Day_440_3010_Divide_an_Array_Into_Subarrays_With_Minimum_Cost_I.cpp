#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array nums where the first element represents the cost of a subarray and the rest are elements of the array,
// divide the array into subarrays such that the total cost is minimized. The cost of a subarray is defined as the sum of its first element and the two smallest elements in that subarray.

// Approach: To minimize the total cost, we can consider the entire array as a single subarray.

// Steps:
// 1. Identify the first element of the array as the cost of the subarray.
// 2. Find the two smallest elements in the rest of the array.
// 3. Sum the first element and the two smallest elements to get the minimum cost.
// 4. Return the minimum cost.

// Time Complexity: O(N), where N is the number of elements in the array, as we need to traverse the array to find the two smallest elements.
// Space Complexity: O(1), as we are using a constant amount of extra space.

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int min1 = 100; 
        int min2 = 100;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < min1){
                min2 = min1;
                min1 = nums[i];
            }
            else if(nums[i] < min2){
                min2 = nums[i];
            }
        }
        return nums[0] + min1 + min2;
    }
};
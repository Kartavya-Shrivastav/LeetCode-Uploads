#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of integers nums, an integer target, and an integer start, return the minimum distance from start to the index of any occurrence of target in nums. If target does not exist in nums, return -1.
Approach: We can iterate through the array and check for occurrences of the target. For each occurrence, we calculate the distance from the start index and keep track of the minimum distance found.

Steps:
1. Initialize a variable result to store the minimum distance, set it to the size of the array (as the maximum distance can be the size of the array).
2. Iterate through the array nums:
   a. If the current element is equal to the target, calculate the distance from the start index and update the result if it's smaller than the current result. 
   b. Continue iterating until the end of the array.

3. After iterating through the array, if result is still equal to the size of the array, it means we did not find the target, so we return -1. Otherwise, we return the result.

Time Complexity: O(n) where n is the size of the array, as we need to iterate through the array once.
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int result = nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target)
                result = min(result,abs(i-start));
        }
        return result;
    }
};
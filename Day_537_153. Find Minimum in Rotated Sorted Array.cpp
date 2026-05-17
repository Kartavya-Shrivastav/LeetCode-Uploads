#include <bits/stdc++.h>
using namespace std;

/*
Problem: Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
- [4,5,6,7,0,1,2] if it was rotated 4 times.
- [0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]]. Given the sorted rotated array nums of unique elements, return the minimum element of this array.

Appproach: We can solve this problem by iterating through the array and keeping track of the minimum element we encounter. Since the array is rotated, the minimum element will be the point where the order of the elements changes. We can simply compare each element with the current minimum and update it accordingly.

Steps:
1. Initialize a variable min to store the minimum element, and set it to the maximum possible integer value (INT_MAX).
2. Iterate through each element in the nums array:
   a. If the current element is less than min, update min to be the current element.    
   b. Continue iterating through the array until we have checked all elements.
3. After the loop, min will contain the minimum element in the array, which we can return as the result.

Time Complexity: O(n), where n is the length of the nums array. We need to iterate through the entire array once to find the minimum element.
Space Complexity: O(1), since we are using only a constant amount of extra space to store the minimum element and the loop variable.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int min=INT_MAX;
        int l=0;
        int h=nums.size()-1;
        for(int i=0;i<=h;i++){
            if(nums[i]<min){
                min=nums[i];
            }
        }
        return min;
    }
};
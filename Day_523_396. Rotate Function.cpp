#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of integers, calculate the maximum value of the rotate function F(k) for k = 0, 1, ..., n-1, where F(k) is defined as the sum of i * nums[(i + k) % n] for i = 0 to n-1.
Approach: We can calculate the initial value of F(0) and the sum of all elements in the array. Then, we can use a loop to calculate F(k) for k = 1 to n-1 using the relationship between F(k) and F(k-1). Specifically, we can derive that F(k) = F(k-1) + sum - n * nums[n-k], where sum is the total sum of the array and nums[n-k] is the element that is being rotated out of the current position. We will keep track of the maximum value of F(k) during this process.

Steps:
1. Calculate the initial value of F(0) by summing i * nums[i] for i = 0 to n-1.
2. Calculate the sum of all elements in the array.
3. Initialize a variable ans to store the maximum value of F(k) and set it to F(0).
4. Use a loop to calculate F(k) for k = 1 to n-1.
    a. Update F(k) using the relationship F(k) = F(k-1) + sum - n * nums[n-k].
    b. Update ans to be the maximum of ans and F(k).

Time Complexity: O(n), where n is the number of elements in the array, since we are iterating through the array a few times to calculate F(0) and F(k) for k = 1 to n-1.
Space Complexity: O(1), since we are using a constant amount of extra space to store variables for the calculations.
*/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) 
    {
        int ret = 0;
        int sum = 0;
        int ans = INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            ret += i*nums[i];
            sum += nums[i];
        }
        ans = ret;
        for(int i=0; i<nums.size(); i++)
        {
            ret += sum;
            ret -= (nums.size() * nums[nums.size()-1 - i]);
            ans = max(ans, ret);
        }
        return ans;
    }
};
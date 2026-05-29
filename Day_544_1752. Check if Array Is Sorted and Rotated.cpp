#include <bits/stdc++.h>
using namespace std;


/*
Problem: Given an array of integers nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
Approach: We can solve this problem by counting the number of times the order of the elements is violated. Specifically, we can iterate through the array and count how many times an element is greater than the next element (considering the array as circular). If this count is more than 1, then the array cannot be a rotated sorted array.

Steps:
1. Initialize a count variable to 0.
2. Iterate through the array and compare each element with the next element (using modulo to wrap around).
3. If the current element is greater than the next element, increment the count.
4. If the count exceeds 1, return false.
5. If the loop completes and the count is 0 or 1, return true.

Time Complexity: O(n) since we need to iterate through the array once.
Space Complexity: O(1) since we are using only a constant amount of extra space.
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[(i + 1) % n] < nums[i]) {
                count++;
            }
            
            if (count > 1) return false;
        }

        return true;
        
    }
};
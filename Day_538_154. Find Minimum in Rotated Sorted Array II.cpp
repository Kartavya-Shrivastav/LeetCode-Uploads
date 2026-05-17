#include <bits/stdc++.h>
using namespace std;

/*
Problem: Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6
Approach: We can solve this problem by using a modified binary search algorithm. Since the array is rotated, we can compare the middle element with the last element to determine which half of the array is sorted. If the middle element is greater than the last element, it means that the minimum element is in the right half of the array. Otherwise, it means that the minimum element is in the left half of the array. We can continue this process until we find the minimum element.    

Steps:
1. Initialize two pointers, left and right, to the start and end of the array, respectively.
2. Store the last element of the array in a variable last, as it will be used for comparison.
3. While left is less than right:
   a. Calculate the middle index mid as the average of left and right.
   b. If the middle element nums[mid] is greater than last, it means that the minimum element is in the right half of the array. Therefore, update left to mid + 1.
   c. Otherwise, it means that the minimum element is in the left half of the array. Therefore, update right to mid.    
4. After the loop, left will be pointing to the minimum element in the array, which we can return as the result.

Time Complexity: O(log n), where n is the length of the nums array. The binary search algorithm allows us to find the minimum element in logarithmic time.
Space Complexity: O(1), since we are using only a constant amount of extra space to store the pointers and the last element for comparison.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() - 1;
        int last = nums[n];
        int left = 0, right = n;

        while (left < n && nums[left] == last)
            left++;

        while (left < right) {
            int mid = left + right >> 1;

            if (nums[mid] > last)
                left = mid + 1;
            else
                right = mid;
        }

        return nums[left];
    }
};
#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of integers nums which is sorted in ascending order and is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]), and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
Approach: We can solve this problem using a modified binary search. The idea is to first find the index of the smallest element in the rotated array, which gives us the pivot point. Once we have the pivot, we can determine which part of the array to search for the target. We then perform a standard binary search on the appropriate half of the array.

Steps:
1. Use binary search to find the index of the smallest element in the rotated array, which is the pivot point.
2. Once we have the pivot, we can determine if the target is in the left half (from the start to the pivot) or in the right half (from the pivot to the end).
3. Perform a standard binary search on the determined half of the array to find the target.
4. If the target is found, return its index; otherwise, return -1.

Time Complexity: O(log n) for finding the pivot and O(log n) for the binary search, resulting in O(log n) overall.
Space Complexity: O(1) since we are using only a constant amount of extra space.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums.back()) lo = mid + 1;
            else hi = mid;
        }

        int rot = lo;
        lo = 0, hi = n - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int real = (mid + rot) % n;

            if (nums[real] == target)
                return real;

            if (nums[real] < target) lo = mid + 1;
            else hi = mid - 1;
        }

        return -1;
    }
};
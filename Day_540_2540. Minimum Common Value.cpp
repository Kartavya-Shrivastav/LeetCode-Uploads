#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given two integer arrays nums1 and nums2, return the minimum common value in nums1 and nums2. If there is no common value, return -1.
Approach: We can solve this problem by first sorting both arrays and then using a two-pointer technique to find the minimum common value. We will initialize two pointers, one for each array, and compare the values at these pointers. If the values are equal, we have found the minimum common value and we can return it. If the value at the first pointer is less than the value at the second pointer, we will move the first pointer forward to try to find a larger value that might match with the second pointer. If the value at the second pointer is less than the value at the first pointer, we will move the second pointer forward to try to find a larger value that might match with the first pointer. We will continue this process until we either find a common value or exhaust one of the arrays.

Steps:
1. Sort both nums1 and nums2.
2. Initialize two pointers, i and j, to 0.
3. While both pointers are within the bounds of their respective arrays:
   a. If nums1[i] is equal to nums2[j], return nums1[i] as the minimum common value.
   b. If nums1[i] is less than nums2[j], increment pointer i to move to the next value in nums1.
   c. If nums1[i] is greater than nums2[j], increment pointer j to move to the next value in nums2.
4. If we exit the loop without finding a common value, return -1.

Time Complexity: O(n log n + m log m), where n and m are the lengths of nums1 and nums2 respectively, due to the sorting step. The two-pointer traversal takes O(n + m) time.
Space Complexity: O(1) if we sort the arrays in place, otherwise O(n + m) if we create new sorted arrays.
*/

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int result=-1;
        int n1=nums1.size(),n2=nums2.size();
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(nums1[i]==nums2[j]){
                result=nums1[i];
                break;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return result;
    }
};
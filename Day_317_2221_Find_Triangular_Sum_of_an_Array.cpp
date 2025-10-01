#include <bits/stdc++.h>
using namespace std;

// Problem: 2221. Find Triangular Sum of an Array
// Approach: Iterative Reduction

// Steps:
// 1. Start with the given array and iteratively reduce its size by replacing each element.
// 2. In each iteration, replace each element with the sum of itself and the next element modulo 10.
// 3. Continue this process until only one element remains in the array.
// 4. Return the remaining element as the triangular sum.

// Time Complexity: O(n^2), where n is the number of elements in the array.
// Space Complexity: O(1), as we are modifying the array in place.

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
       for (int i=n-1; i>=1; i--){
           for(int j=0; j<i; j++){
               nums[j]=(nums[j]+nums[j+1])%10;
           }
       }
       return nums[0]; 
    }
};
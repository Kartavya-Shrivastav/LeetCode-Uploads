#include <bits/stdc++.h>
using namespace std;

// Problem: 976. Largest Perimeter Triangle
// Approach: Sorting and Greedy Selection

// Steps:
// 1. Sort the array of side lengths in descending order.
// 2. Iterate through the sorted array and check for the first triplet that satisfies the triangle inequality condition.
// 3. Return the perimeter of the first valid triangle found.
// 4. If no valid triangle is found, return 0.

// Time Complexity: O(n log n)
// Space Complexity: O(1)

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        sort(nums.begin(), nums.end(), std::greater<int>());

        for(int i=0;i<=n-3; i++){
            if(nums[i+1] + nums[i+2] > nums[i]){
                return nums[i+1] + nums[i+2] + nums[i];
            }           
        }
        return 0;
    }
};
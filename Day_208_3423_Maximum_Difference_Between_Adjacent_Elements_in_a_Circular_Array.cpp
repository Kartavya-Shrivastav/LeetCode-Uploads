#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the maximum absolute difference between adjacent elements in a circular array
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi = 0;
        // Iterate through the array and check the difference between each pair of adjacent elements
        for (int i = 0 ; i < nums.size() - 1 ; i++)
            maxi = max(maxi , abs(nums[i + 1] - nums[i]));
        // Check the difference between the last and first element to account for the circular nature
        maxi = max(maxi , abs(nums[nums.size() - 1] - nums[0]));
        return maxi;
    }
};
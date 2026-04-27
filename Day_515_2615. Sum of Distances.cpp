#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an integer array nums, return an array answer where answer[i] is the sum of the distances between the index i and all other indices j such that nums[i] == nums[j] and i != j.
Approach: We can use a hash map to group the indices of the same numbers together. For each group of indices, we can calculate the sum of distances for each index in that group using prefix sums.

Steps:
1. Initialize an empty vector ans of the same size as nums to store the result.
2. Create an unordered map mp to group the indices of the same numbers together. The key will be the number itself and the value will be a vector of indices where that number appears in nums.
3. Iterate through the nums array and populate the map mp with the indices of each number.  
4. For each group of indices in the map mp:
   a. Calculate the total sum of the indices in that group and store it in a variable sum.
   b. Initialize a variable leftSum to 0 to keep track of the sum of indices to the left of the current index.
   c. Iterate through the indices in the group:
      i. Calculate the rightSum as sum - leftSum - current index.
      ii. Calculate the distance for the current index as (current index * number of indices to the left) - leftSum + rightSum - (current index * number of indices to the right).
      iii. Store this distance in the ans vector at the position of the current index.
      iv. Update leftSum by adding the current index to it.
5. Return the ans vector containing the sum of distances for each index.

Time Complexity: O(n), where n is the length of the nums array. We iterate through the nums array once to populate the map and then iterate through each group of indices, which in total will also be O(n).    
Space Complexity: O(n), where n is the length of the nums array. In the worst case, all numbers in nums could be the same, resulting in a single group of indices that contains all indices, which would require O(n) space to store in the map. Additionally, we use O(n) space for the ans vector to store the results.
*/

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++)
            mp[nums[i]].push_back(i);

        for(auto &it : mp){
            auto &pos = it.second;

            long long sum = 0;
            for(int x : pos) sum += x;

            long long leftSum = 0;
            int m = pos.size();

            for(int i = 0; i < m; i++){
                long long rightSum = sum - leftSum - pos[i];

                long long left  = 1LL * pos[i] * i - leftSum;
                long long right = rightSum - 1LL * pos[i] * (m-i-1);

                ans[pos[i]] = left + right;

                leftSum += pos[i];
            }
        }

        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of integers, we need to find the minimum distance between three equal elements in the array. The distance is defined as the difference between the indices of the first and third occurrence of the same element.
Approach: We can use a hash map to store the indices of each element in the array. For each element, if it occurs at least three times, we can calculate the distance between the first and third occurrence and keep track of the minimum distance found.

Steps:
1. Create a hash map to store the indices of each element in the array.
2. Iterate through the array and populate the hash map with the indices of each element.
3. For each element in the hash map, check if it has at least three occurrences. If it does, calculate the distance between the first and third occurrence and update the minimum distance if it's smaller than the current minimum.
4. After processing all elements, return the minimum distance found. If no element has three occurrences, return -1.

Time Complexity: O(n) where n is the size of the array, as we need to iterate through the array once to populate the hash map and then iterate through the hash map to find the minimum distance.
Space Complexity: O(n) in the worst case, if all elements in the array are unique, we will store all indices in the hash map.
*/

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }
        
        int mini = INT_MAX;
        
        for(auto &it : mp){
            vector<int> &temp = it.second;
            int m = temp.size();
            
            if(m >= 3){
                for(int i = 0; i < m - 2; i++){
                    int a = temp[i];
                    int b = temp[i+1];
                    int c = temp[i+2];
                    
                    int diff = 2 * (c - a);
                    mini = min(mini, diff);
                }
            }
        }
        
        return mini == INT_MAX ? -1 : mini;
    }
};
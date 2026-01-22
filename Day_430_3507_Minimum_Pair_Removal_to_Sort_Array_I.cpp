#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of integers, you can perform the following operation any number of times: select two adjacent elements and replace them with their sum. The goal is to determine the minimum number of such operations required to make the array sorted in non-decreasing order.
// Approach: The approach involves repeatedly finding the pair of adjacent elements with the smallest sum, merging them, and counting the number of operations until the array is sorted.

// Steps:
// 1. Define a function to find the position of the pair of adjacent elements with the minimum sum.
// 2. Define a function to merge the pair of elements at the found position.
// 3. In the main function, repeatedly find and merge the minimum pair until the array is sorted, counting the number of operations performed.
// 4. Return the count of operations.

// Time Complexity: O(n^2) in the worst case, as we may need to perform up to n merges and each merge involves checking the array for the minimum pair.
// Space Complexity: O(1) additional space, as we are modifying the input array in place.

class Solution {
public:
    int minPair(vector<int> v){
        int minSum = 1e9;
        int pos = -1;
        for(int i = 0; i < (int)v.size() - 1; i ++){
            if(v[i] + v[i + 1] < minSum){
                minSum = v[i] + v[i + 1];
                pos = i;
            }
        }
        return pos;
    }
    void mergePair(vector<int> &v, int pos){
        v[pos] += v[pos + 1];
        v.erase(v.begin() + pos + 1);
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        while(!is_sorted(nums.begin(), nums.end())){
            mergePair(nums, minPair(nums));
            ops += 1;
        }
        return ops;
    }
};
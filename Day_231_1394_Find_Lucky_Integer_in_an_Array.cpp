#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of integers, find the largest lucky integer in the array.
// A lucky integer is defined as an integer that appears in the array exactly as many times as its value.

// Approach: Use a hash map to count the occurrences of each integer, then iterate through the array to find the largest lucky integer.

// Steps:
// 1. Create a hash map to store the frequency of each integer in the array.
// 2. Iterate through the array and populate the hash map with counts.
// 3. Iterate through the array again to check if any integer is a lucky integer (i.e., its value equals its count).
// 4. Keep track of the largest lucky integer found.
// 5. Return the largest lucky integer, or -1 if none is found.

// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(n), for storing the frequency counts in the hash map.

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> map;
        int ans = -1;
        for(int i: arr){
            map[i]++;
        }

        for(int i: arr){
            if(i == map[i]){
                if(i > ans) 
                    ans = i;
            }
        }

        return ans;
    }
};
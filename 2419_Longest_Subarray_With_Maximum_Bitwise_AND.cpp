#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int longest = 0, currLen = 0;
        for(int i: nums){
            if(i == mx){
                currLen++;
                longest = max(longest, currLen);
            }
            else{
                currLen = 0;
            }
        }
        return longest;
    }
};
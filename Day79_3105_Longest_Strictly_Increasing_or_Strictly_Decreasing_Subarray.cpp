#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        int inc = 1;
        int dec = 1;

        for(int i=1; i<n; i++){
            if(nums[i-1] < nums[i]){
                inc++;
                dec=1;
            }
            else if(nums[i-1] > nums[i]){
                inc=1;
                dec++;
            }
            else{
                inc = 1;
                dec =1;
            }

            ans = max({ans, dec, inc});
        }

    return ans;
    }
};
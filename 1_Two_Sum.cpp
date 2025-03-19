#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans(2);
        for(int i=0; i<nums.size(); i++){
            int d = target - nums[i];
            if(mp.find(d) != mp.end()){
                ans[0] = i;
                ans[1] = mp[d];
                break;
            }
            mp[nums[i]] = i;
            
        }
        return ans;
    }
};
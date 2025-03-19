#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // int mx = *max_element(nums.begin(), nums.end());
        // if(mx < 0) return 1;

        // unordered_set<int> st;
        // for(int i=0; i<nums.size(); i++){
        //     st.insert(nums[i]);
        // }

        // for(int i=1; i<=mx; i++){
        //     if(st.find(i) == st.end()){
        //         return i;
        //     }
        // }
        
        // return mx+1;

        int n = nums.size();

        for(int i=0; i<n; i++){
            while(nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i] != i+1) return i+1;
        }

        return n+1;
    }
};
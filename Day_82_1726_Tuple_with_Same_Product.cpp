#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bucket[512];
    void radix_sort(vector<int>& nums) {

        // 1st round
        for (int& x : nums) bucket[x & 511].push_back(x);
        int i = 0;
        for (auto& B : bucket) { for (auto v : B) nums[i++] = v; B.clear(); }

        // 2nd round
        for (int& x : nums) bucket[(x >> 9) & 511].push_back(x);
        i = 0;
        for (auto& B : bucket) { for (auto v : B) nums[i++] = v; B.clear(); }

        // 3rd round
        for (int& x : nums) bucket[x >> 18].push_back(x);
        i = 0;
        for (auto& B : bucket) { for (auto v : B) nums[i++] = v; B.clear(); }
    }
    
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                arr.push_back(nums[i]*nums[j]);
            }
        }

        radix_sort(arr);
        
        int last = -1;
        int same_count = 0;
        for(int k=0; k<arr.size(); k++){
            if(arr[k] == last){
                same_count++;
            }
            else{
                ans += 8 * same_count * (same_count-1) / 2;
                last = arr[k];
                same_count = 1;
            }
        }

        ans += 8 * same_count * (same_count-1) / 2;
        return ans;
    }
};
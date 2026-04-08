#include <bits/stdc++.h>
using namespace std;

/*
Problem: We are given an array of integers and a list of queries. Each query consists of four integers (l, r, k, v) where l and r define a range in the array, k is a step size, and v is a value to multiply. For each query, we need to multiply every k-th element in the range [l, r] by v and then compute the XOR of all elements in the array after processing all queries.
Approach: We can iterate through each query and update the elements in the specified range according to
    the step size. After processing all queries, we will compute the XOR of all elements in the array to get the final result.

Steps:
1. Iterate through each query in the list of queries.   
2. For each query, extract the values of l, r, k, and v.
3. Use a loop to update every k-th element in the range [l, r] by multiplying it with v and taking modulo with 10^9 + 7 to prevent overflow.
4. After processing all queries, compute the XOR of all elements in the array and return the result.

Time Complexity: O(q * (r - l) / k) where q is the number of queries, and r and l are the range limits for each query. In the worst case, this can be O(n * q) if k is 1.
Space Complexity: O(1) as we are modifying the input array in place and using a constant amount of extra space for variables.
*/

class Solution {
    const int mod=1000000007;
    #define ll long long
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto &t:queries){
            int l=t[0];
            int r=t[1];
            int k=t[2];
            int v=t[3];
            int idx=l;
            while(idx<=r){
                ll temp=nums[idx];
                nums[idx]=(temp*v)%mod;
                idx+=k;
            }
        }
        int ans=0;
        for(int num:nums){
            ans^=num;
        }
        return ans;
    }
};
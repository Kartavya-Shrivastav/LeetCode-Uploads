#include<bits/stdc++.h>
using namespace std;

// Problem: 2048. Next Greater Numerically Balanced Number
// Approach: Use backtracking to generate numerically balanced numbers and find the next greater one.

// Steps:
// 1. Define a recursive function `rec` that builds numerically balanced numbers digit by digit.
// 2. The function takes the current number being built, its length, and a count of digits used so far.
// 3. If the length reaches zero, check if the built number is greater than n and if it is numerically balanced.
// 4. If valid, return the number; otherwise, continue building the number by trying each digit from 1 to 9.
// 5. In the main function, call the recursive function for the length of n and length + 1 to find the next greater numerically balanced number.

// Time Complexity: Exponential in the worst case due to backtracking
// Space Complexity: O(1) additional space apart from recursion stack

#define ll long long
class Solution {
public:
    ll rec(ll n,ll cur,ll len,vector<ll> &ct){
        if(len==0){
            if(cur>n){
                for(int i=1;i<10;i++){
                    if(ct[i]!=i && ct[i]>0) return 0;
                }
                return cur;
            }
            return 0;
        }
        ll ans=0;
        for(int i=1;i<10 && ans==0;i++){
            if(ct[i]<i && i-ct[i]<=len){
                ct[i]++;
                ans=rec(n,cur*10+i,len-1,ct);
                ct[i]--;
            }
        }
        return ans;
    }
    int nextBeautifulNumber(int n) {
        string s=to_string(n);
        ll m=s.size();
        vector<ll> ct(10,0);
        ll ans=rec(n,0,m,ct);
        ct.assign(10,0);
        ll x=rec(0,0,m+1,ct);
        if(ans==0) ans=x;
        return ans;
    }
};
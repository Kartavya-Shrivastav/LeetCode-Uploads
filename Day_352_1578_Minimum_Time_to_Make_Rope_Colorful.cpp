#include<bits/stdc++.h>
using namespace std;

// Problem: Minimum Time to Make Rope Colorful
// Approach: Iterate through the string and for consecutive same colors, sum up the needed times and subtract the maximum time

// Steps:
// 1. Initialize variables to keep track of total time, current index, and size of the string
// 2. Loop through the string to find consecutive characters that are the same 
// 3. For each group of consecutive characters, sum up the needed times and subtract the maximum time   
// 4. Return the total time required to make the rope colorful

// Time Complexity: O(n) where n is the length of the colors string
// Space Complexity: O(1) as we are using a constant amount of extra space

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        int index=0;
        int n=colors.size();
        int temp=0;
        int maxi=0;
        while(index<n)
        {
            maxi=0;
            temp=0;
            bool found=false;
            while(index<n-1 && colors[index]==colors[index+1])
            {
                found=true;
                temp=temp+neededTime[index];
                maxi=max(maxi,neededTime[index]);
                index++;
            }
            temp=temp+neededTime[index];
            maxi=max(maxi,neededTime[index]);
            
            if(found)
            {
                ans=ans+temp-maxi;
            }
            index++;
        }
        return ans;
    }
};
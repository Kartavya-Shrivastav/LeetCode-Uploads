#include <bits/stdc++.h>
using namespace std;    

// Problem Statement: Given an array consisting of characters 'P' and 'T' where 'P' represents police officers and 'T' represents thieves. Each police officer can catch a thief if the thief is within K distance from the police officer. A police officer can catch only one thief. The task is to find the maximum number of thieves that can be caught.
// Approach: We can use two pointers to traverse the array. One pointer will track the position of police officers and the other will track the position of thieves. We will iterate through the array and whenever we find a police officer and a thief within K distance, we will increment our count and move both pointers forward. If the thief is out of range, we will move the pointer of the police officer or thief accordingly.

// Steps:
// 1. Initialize two pointers, one for police officers and one for thieves.
// 2. Iterate through the array using both pointers.
// 3. Whenever a police officer and a thief are found within K distance, increment the count and move both pointers forward.
// 4. If the thief is out of range, move the pointer of the police officer or thief accordingly.
// 5. Return the count of maximum thieves that can be caught.

// Time Complexity: O(n), where n is the size of the array.
// Space Complexity: O(1), as we are using only a constant amount of extra space.

class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n=arr.size();
        int count=0;
        int t=0,p=0;
        while(t<n && p<n)
        { 
            while(t<n && arr[t]!='T') ++t;
            while(p<n && arr[p]!='P') ++p;
            if(t<n && p<n && abs(t-p)<=k)
            {
                ++count;++p;++t;
            }
            else if(t<p) ++t;
            else ++p;
        }
        return count;
    }
};
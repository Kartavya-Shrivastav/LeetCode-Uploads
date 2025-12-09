#include <bits/stdc++.h>
using namespace std;

// Problem: Count Special Triplets
// Approach: Frequency Counting with Prefix Sums

// Steps:
// 1. Count the frequency of each number in the input array.
// 2. Use a prefix frequency array to keep track of how many times each number has appeared up to the current index.
// 3. For each element in the array (except the first and last), check if double its value exists in the array.
// 4. Calculate the number of valid triplets using the prefix frequency and total frequency of the doubled value.
// 5. Sum up the counts for all valid triplets and return the result modulo 10^9 + 7.

// Time Complexity: O(n) where n is the size of the input array
// Space Complexity: O(M) where M is the maximum value in the input array

const int mod=1e9+7;
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int M=100001, n=nums.size();
        int freq[M]={0}, prev[M]={0};
        for(int x: nums) freq[x]++;
        long long cnt=0;
        prev[nums[0]]++;
        for(int i=1; i<n-1; i++){
            const int x=nums[i], x2=x<<1;
            if (x2<M)
                cnt+=(long long)prev[x2]*(freq[x2]-prev[x2]-(x==0));
            prev[x]++;
        }
        return cnt%mod;
    }
};
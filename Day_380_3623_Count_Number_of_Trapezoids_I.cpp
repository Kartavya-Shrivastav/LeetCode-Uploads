#include <bits/stdc++.h>
using namespace std;

// Problem: Count Number of Trapezoids
// Approach: Combinatorial Counting with Hash Map

// Steps:
// 1. Use a hash map to count the frequency of each y-coordinate among the given points.
// 2. For each unique y-coordinate with frequency f, calculate the number of ways to choose 2 points (f choose 2) which gives the number of horizontal segments at that y-level.
// 3. Sum up the counts of horizontal segments to get the total number of ways to choose pairs of horizontal segments.
// 4. Use the formula to calculate the number of trapezoids formed by choosing two different horizontal segments.
// 5. Return the result modulo 10^9 + 7.

// Time Complexity: O(n) where n is the number of points
// Space Complexity: O(n) for the hash map storing frequencies of y-coordinates

class Solution {
public:
    static int countTrapezoids(vector<vector<int>>& points) {
        const long long mod=1e9+7, n=points.size();
        unordered_map<int, int> freq;
        freq.reserve(n);
        for(auto& p: points)
            freq[p[1]]++;
        long long sum=0, c2=0;
        for(auto& [y, f]: freq){
            if (f<=1) continue;
            const long long c=f*(f-1LL)/2LL;
            sum+=c;
            c2+=c*c;
        }
        long long ans=sum*sum-c2;
        ans/=2;
        ans%=mod;
        return ans;
    }
};
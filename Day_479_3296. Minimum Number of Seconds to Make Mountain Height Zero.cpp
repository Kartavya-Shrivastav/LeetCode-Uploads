#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement: Given an integer height and a 0-indexed integer array times, where times[i] is the time taken to reduce the height of the mountain by 1 unit using the i-th machine, return the minimum number of seconds needed to make the height of the mountain equal to 0.  
Approach: We can use binary search to find the minimum number of seconds needed. We will check for each mid value if we can reduce the height to 0 using the machines within that time. We will calculate the total height reduced by all machines in mid seconds and compare it with the given height. If the total height reduced is greater than or equal to the given height, we can try to reduce the time, otherwise, we need to increase the time.

Steps:
1. Initialize low (lo) to 1 and high (hi) to a large number (e.g., 1e16).
2. While lo is less than hi:    
    a. Calculate mid as the average of lo and hi.
    b. Initialize tot to 0, which will store the total height reduced by all machines in mid seconds.
    c. For each machine, calculate how many units of height it can reduce in mid seconds using the formula: sqrt((mid / times[i]) * 2 + 0.25) - 0.5. This formula is derived from the sum of the first n natural numbers (n*(n+1)/2) and solving for n.
    d. If tot is greater than or equal to height, set hi to mid, otherwise set lo to mid + 1.
3. Return lo as the minimum number of seconds needed to reduce the height to 0.

Time Complexity: O(n log(max_time)), where n is the number of machines and max_time is the maximum time we are checking in our binary search.   
Space Complexity: O(1), as we are using only a constant amount of extra space.
*/

using ll = long long;
class Solution {
public:
    ll minNumberOfSeconds(int height, vector<int>& times) {
        ll lo = 1, hi = 1e16;

        while (lo < hi) {
            ll mid = (lo + hi) >> 1;
            ll tot = 0;
            for (int i = 0; i < times.size() && tot < height; i++)
                tot += (ll)(sqrt((double)mid / times[i] * 2 + 0.25) - 0.5);
            if (tot >= height)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};
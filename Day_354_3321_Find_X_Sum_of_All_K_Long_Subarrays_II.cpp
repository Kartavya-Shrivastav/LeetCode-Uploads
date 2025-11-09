#include <bits/stdc++.h>
using namespace std;

// Problem: Find X Sum of All K Long Subarrays II
// Approach: Use a sliding window with two balanced sets to maintain the top x unique elements and
//           the rest. Use a frequency map to track counts of elements in the current window. Rebalance the sets
//           after each insertion and deletion to ensure the top x elements are always in the top set.

// Steps:
// 1. Initialize frequency map and two sets with custom comparator to maintain order based on frequency and value.
// 2. Define a rebalance function to ensure the top set contains the top x elements.
// 3. Iterate through the array, adding new elements and removing old elements as the window
//    slides. Update the frequency map and sets accordingly.
// 4. After processing each complete window, store the sum of the top x elements in the result vector.
// 5. Return the result vector containing sums for all k-length subarrays.

// Time Complexity: O(n log k) where n is the number of elements in nums and k is the length of each subarray.
// Space Complexity: O(k) for the frequency map and sets.

class Solution 
{
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) 
    {
        int n = nums.size();
        vector<long long> ans(n - k + 1);
        unordered_map<int,int> freq;

        // Step 1: Initialize structures
        auto cmp = [&](int a, int b) 
        {
            if (freq[a] != freq[b])
            {
                return freq[a] < freq[b];
            } 
            return a < b;
        };

        set<int, decltype(cmp)> topX(cmp), rest(cmp);
        long long sumTop = 0;

        // Step 2: Ordering / comparator defined above

        auto rebalance = [&]() 
        {
            // Step 4: rebalance logic
            while ((int)topX.size() < min(x, (int)freq.size()) && !rest.empty()) 
            {
                int best = *prev(rest.end());
                rest.erase(prev(rest.end()));
                topX.insert(best);
                sumTop += 1LL * freq[best] * best;
            }

            while ((int)topX.size() > x) 
            {
                int worst = *topX.begin();
                topX.erase(topX.begin());
                rest.insert(worst);
                sumTop -= 1LL * freq[worst] * worst;
            }

            while (!topX.empty() && !rest.empty()) 
            {
                int worstTop = *topX.begin();
                int bestRest = *prev(rest.end());
                int fw = freq[worstTop], fr = freq[bestRest];

                if (fr > fw || (fr == fw && bestRest > worstTop)) 
                {
                    topX.erase(topX.begin());
                    rest.erase(prev(rest.end()));
                    topX.insert(bestRest);
                    rest.insert(worstTop);
                    sumTop += 1LL * fr * bestRest - 1LL * fw * worstTop;
                } 
                else 
                {
                    break;
                }
            }
        };

        // Step 3,5,6 and Step 7: Main sliding-window loop
        for (int i = 0; i < n; ++i) 
        {
            int v = nums[i];
            int old = freq[v];

            if (old > 0) 
            {
                if (topX.erase(v)) 
                {
                    sumTop -= 1LL * old * v;
                } 
                else 
                {
                    rest.erase(v);
                }
            }

            freq[v] = old + 1;
            rest.insert(v);
            rebalance();

            if (i >= k) 
            {
                int u = nums[i - k];
                int oldU = freq[u];

                if (topX.erase(u)) 
                {
                    sumTop -= 1LL * oldU * u;
                } 
                else 
                {
                    rest.erase(u);
                }

                if (oldU == 1) 
                {
                    freq.erase(u);
                } 
                else 
                {
                    freq[u] = oldU - 1;
                    rest.insert(u);
                }
                rebalance();
            }

            if (i >= k - 1) 
            {
                ans[i - k + 1] = sumTop;
            }
        }

        // Step 9: Return result
        return ans;
    }
};
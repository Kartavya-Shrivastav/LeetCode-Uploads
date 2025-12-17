#include <bits/stdc++.h>
using namespace std;

// Problem: Best Time to Buy and Sell Stock V
// Approach: Dynamic Programming

// Steps:
// 1. Define a DP state to keep track of maximum profit with at most k transactions.
// 2. Iterate through each price and update the DP states accordingly.
// 3. Return the maximum profit after processing all prices.

// Complexity:
// Time: O(n * k) where n is the number of days and k is the maximum number of transactions
// Space: O(k) for DP table

struct Data{
    long long profit=0, buy=0, sell=0;
    Data(long long profit=0, long long buy=0, long long sell=0):
        profit(profit), buy(buy), sell(sell) {}
};
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        const int x0=prices[0];
        vector<Data> dp(k+1, Data(0, -x0, x0));// day 0
        const int n=prices.size();
        for(int i=1; i<n; i++){
            const int x=prices[i];
            for(int t=k; t>0; t--){
                auto& [p, b, s]=dp[t];
                const long long prevP=dp[t-1].profit;
                p=max(p, max(b+x, s-x));
                b=max(b, prevP-x);
                s=max(s, prevP+x);
            }
        }
        return dp[k].profit;
    }
};
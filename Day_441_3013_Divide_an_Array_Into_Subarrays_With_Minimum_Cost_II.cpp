#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array nums where the first element represents the cost of a subarray and the rest are elements of the array,
// divide the array into subarrays such that the total cost is minimized. The cost of a subarray is defined as the sum of its first element and the K smallest elements in that subarray.

// Approach: We can use a sliding window technique combined with a balanced data structure to efficiently maintain the K smallest elements in the current window.

// Steps:
// 1. Create a SmartWindow class that maintains two multisets: one for the K smallest elements and another for the rest.
// 2. Implement methods to add and remove elements from the window while keeping it balanced.   
// 3. Use the SmartWindow to slide over the array, updating the window and calculating the cost at each step.   
// 4. Keep track of the minimum cost encountered during the sliding process.
// 5. Return the minimum cost after processing the entire array.

// Time Complexity: O(N log K), where N is the number of elements in the array, as each addition and removal operation in the multiset takes O(log K) time.
// Space Complexity: O(K), as we are storing K elements in the SmartWindow.

class Solution {
public:
    struct SmartWindow{
        int K;
        multiset<int> low, high;
        long long sumLow = 0;

        SmartWindow(int k) : K(k) {}

        int windowSize() const{
            return (int)low.size() + (int)high.size();
        }
        void rebalance() {
            int need = min(K, windowSize());

            while((int)low.size() > need){
                auto it = prev(low.end());
                int x = *it;
                low.erase(it);
                sumLow -= x;
                high.insert(x);
            }
            while((int)low.size() < need && !high.empty()){
                auto it = high.begin();
                int x = *it;
                high.erase(it);
                low.insert(x);
                sumLow += x;
            }
        }
        void add(int x){
            if(low.empty() || x <= *prev(low.end())){
                low.insert(x);
                sumLow += x;
            }
            else{
                high.insert(x);
            }
            rebalance();
        }
        void remove(int x){
            auto itLow = low.find(x);
            if(itLow != low.end()){
                low.erase(itLow);
                sumLow -= x;
            }
            else{
                auto itHigh = high.find(x);
                if(itHigh != high.end()){
                    high.erase(itHigh);
                }
            }
            rebalance();
        }
        long long query() const{
            return sumLow;
        }
    };
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = (int)nums.size();
        k -= 1;
        SmartWindow window(k);
        for(int i = 1; i <= 1 + dist; i ++){
            window.add(nums[i]);
        }
        long long ans = window.query();
        for(int i = 2; i + dist < n; i ++){
            window.remove(nums[i - 1]);
            window.add(nums[i + dist]);
            ans = min(ans, window.query());
        }
        return ans + nums[0];
    }
};
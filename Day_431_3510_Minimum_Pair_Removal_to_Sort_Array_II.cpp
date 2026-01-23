#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of integers, you can perform the following operation any number of times: select two adjacent elements and replace them with their sum. The goal is to determine the minimum number of such operations required to make the array sorted in non-decreasing order.
// Approach: The approach involves using a priority queue to always merge the pair of adjacent elements with the smallest sum, while maintaining the sorted order of the array.

// Steps:
// 1. Initialize a priority queue to store sums of adjacent pairs along with their indices.
// 2. Maintain arrays to track the previous and next indices of each element to efficiently update the adjacency after merges.
// 3. Keep track of the number of sorted adjacent pairs to quickly check if the array is sorted.
// 4. Repeatedly extract the minimum sum pair from the priority queue, merge them, and update the necessary structures until the array is sorted.
// 5. Return the count of operations performed.

// Time Complexity: O(n log n) in the average case, as each merge operation involves logarithmic time complexity due to the priority queue operations.
// Space Complexity: O(n) additional space for the priority queue and tracking arrays.

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        vector<long long> arr(nums.begin(), nums.end());
        vector<bool> removed(n, false);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        
        int sorted = 0;
        for (int i = 1; i < n; ++i) {
            pq.emplace(arr[i-1] + arr[i], i-1);
            if (arr[i] >= arr[i-1]) sorted++;
        }
        if (sorted == n - 1) return 0;
        
        int remaining = n;
        vector<int> prev(n), next(n);
        for (int i = 0; i < n; ++i) {
            prev[i] = i - 1;
            next[i] = i + 1;
        }
        
        while (remaining > 1) {
            auto [sum, left] = pq.top(); pq.pop();
            int right = next[left];
            if (right >= n || removed[left] || removed[right] || arr[left] + arr[right] != sum)
                continue;
                
            int pre = prev[left];
            int nxt = next[right];
            
            if (arr[left] <= arr[right]) sorted--;
            if (pre != -1 && arr[pre] <= arr[left]) sorted--;
            if (nxt != n && arr[right] <= arr[nxt]) sorted--;
            
            arr[left] += arr[right];
            removed[right] = true;
            remaining--;
            
            if (pre != -1) {
                //next[pre] = left;
                //prev[left] = pre;
                pq.emplace(arr[pre] + arr[left], pre);
                if (arr[pre] <= arr[left]) sorted++;
            } else {
                prev[left] = -1;
            }
            
            if (nxt != n) {
                prev[nxt] = left;
                next[left] = nxt;
                pq.emplace(arr[left] + arr[nxt], left);
                if (arr[left] <= arr[nxt]) sorted++;
            } else {
                next[left] = n;
            }
            
            if (sorted == remaining - 1)
                return n - remaining;
        }
        return n;
    }
};
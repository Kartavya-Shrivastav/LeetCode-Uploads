#include <bits/stdc++.h>
using namespace std;

// Problem: Count Fruits That Cannot Be Placed in Baskets
// Approach: Use a segment tree to efficiently track the maximum capacity of baskets and determine how many fruits cannot be placed.

// Steps:
// 1. Build a segment tree to represent the capacities of the baskets.
// 2. For each fruit, check if it can be placed in the baskets by querying the segment tree.
// 3. If the maximum capacity is less than the fruit's size, increment the count of unplaced fruits.
// 4. If it can be placed, update the segment tree to reflect that the basket has been used by setting the corresponding 
//    index to -1 (indicating it's no longer available).
// 5. After processing all fruits, return the count of unplaced fruits.

// Time Complexity: O(n log n) for building the segment tree and O(m log n) for processing m fruits, where n is the number of baskets.
// Space Complexity: O(n) for the segment tree.

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        int N = 1;
        while (N <= n) N <<= 1;

        vector<int> segTree(N << 1);
        for (int i = 0; i < n; ++i)
            segTree[N + i] = baskets[i];
        
        for (int i = N - 1; i > 0; --i)
            segTree[i] = max(segTree[2 * i], segTree[2 * i + 1]);

        int count = 0;
        for (int fruit : fruits) {
            int index = 1;
            if (segTree[index] < fruit) {
                count++;
                continue;
            }

            while (index < N) {
                if (segTree[2 * index] >= fruit)
                    index = 2 * index;
                else
                    index = 2 * index + 1;
            }

            segTree[index] = -1;
            while (index > 1) {
                index >>= 1;
                segTree[index] = max(segTree[2 * index], segTree[2 * index + 1]);
            }
        }
        return count;
    }
};
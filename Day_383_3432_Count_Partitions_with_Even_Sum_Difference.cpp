#include <bits/stdc++.h>
using namespace std;

// Problem: Count Partitions with Even Sum Difference
// Approach: Mathematical Insight

// Steps:
// 1. Calculate the total sum of the array.
// 2. If the total sum is odd, return 0 as it's impossible to partition into two subsets with even sum difference.
// 3. If the total sum is even, return n - 1, where n is the size of the array, as there are n - 1 valid partitions.

// Time Complexity: O(n) where n is the size of the array
// Space Complexity: O(1) as we are using only a few extra variables

class Solution {
public:
    int countPartitions(vector<int>& A) {
        int total = accumulate(A.begin(), A.end(), 0);
        return total & 1 ? 0 : A.size() - 1;
    }
};
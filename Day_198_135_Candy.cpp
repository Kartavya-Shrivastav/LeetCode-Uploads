#include <bits/stdc++.h>
using namespace std;

// This code defines a function to calculate the minimum number of candies required to distribute among children
// based on their ratings, ensuring that each child has at least one candy and children with higher ratings receive
// more candies than their neighbors.

class Solution {
public:
    // Function to calculate the minimum number of candies required
    int candy(vector<int>& ratings, int cnt = 0) {
        // Get the number of children (size of ratings vector)
        int n = ratings.size();
        // Initialize candies vector with 1 candy for each child
        vector<int> candies(n, 1);

        // First pass: left to right
        // If the current child's rating is higher than the previous, give one more candy than previous
        for (int i = 1; i < n; i++) 
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        
        // Second pass: right to left
        // If the previous child's rating is higher than current, ensure previous has more candies
        for (int i = n - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i])
                candies[i - 1] = max(candies[i] + 1, candies[i - 1]);
            // Accumulate the candies count
            cnt += candies[i - 1];
        }
        // Add the candies for the last child and return total
        return cnt + candies[n - 1];
    }
};
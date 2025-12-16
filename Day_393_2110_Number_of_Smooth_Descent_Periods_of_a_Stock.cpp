#include <bits/stdc++.h>
using namespace std;

// Problem: Number of Smooth Descent Periods of a Stock
// Approach: Count the lengths of consecutive descending sequences in the prices array.

// Steps:
// 1. Initialize a counter for the total number of smooth descent periods and a variable to track the current descent length.
// 2. Iterate through the prices array starting from the second element.
// 3. For each price, check if it is exactly one less than the previous price.
//    - If yes, increment the current descent length.
//    - If no, reset the current descent length to 1.
// 4. Add the current descent length to the total count of smooth descent periods.
// 5. Return the total count.

// Complexity Analysis:
// - Time Complexity: O(N) where N is the number of prices, as we traverse the prices array once.
// - Space Complexity: O(1) since we use only a constant amount of extra space

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        const int n=prices.size();
        long long sum=1, des=1;
        for(int i=1; i<n; i++){
            des=(prices[i]+1==prices[i-1])*des+1;
            sum+=des;
        }
        return sum;
    }
};
#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Number of Increments on Subarrays to Form a Target Array
// Approach: Calculate the total increments needed by comparing each element with its predecessor

// Steps:
// 1. Initialize sum with the first element of the target array
// 2. Iterate through the target array from the second element
// 3. For each element, if it is greater than the previous element, add the difference to sum
// 4. Return the total sum as the result    

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int sum = target[0]; // start with first element
        for (int i = 1; i < target.size(); i++) {
            if (target[i] > target[i - 1]) {
                sum += target[i] - target[i - 1]; // add only when value increases
            }
        }
        return sum; // total operations needed
    }
};

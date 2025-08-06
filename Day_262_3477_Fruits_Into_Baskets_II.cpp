#include <bits/stdc++.h>
using namespace std;

// Problem: Count Fruits That Cannot Be Placed in Baskets
// Approach: Use a greedy approach to determine how many fruits cannot be placed in the baskets.

// Steps:
// 1. Initialize a boolean array to track which baskets have been used.
// 2. For each fruit, check if it can be placed in any of the baskets.
// 3. If a basket can accommodate the fruit, mark that basket as used.
// 4. If no basket can accommodate the fruit, increment the count of unplaced fruits.
// 5. Return the count of unplaced fruits.

// Time Complexity: O(n^2) where n is the number of fruits, as we may need to check each fruit against all baskets.
// Space Complexity: O(n) for the boolean array to track used baskets.

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> used(n, false); 
        int unplaced = 0;

        for (int i = 0; i < n; i++) {
            bool placed = false;
            for (int j = 0; j < n; j++) {
                if (!used[j] && baskets[j] >= fruits[i]) {
                    used[j] = true;
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                unplaced++;
            }
        }
        return unplaced;
    }
};
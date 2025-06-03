#include <bits/stdc++.h>
using namespace std;

// This code defines a function to calculate the maximum candies that can be collected from boxes,
// given the constraints of keys and contained boxes. It uses a greedy approach to open boxes
// and collect candies until no more boxes can be opened.

class Solution {
public:
    // Function to calculate the maximum candies that can be collected from boxes
    int maxCandies(vector<int>& vis, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        bool foundOpenable = true; // Flag to check if any box can be opened in the current iteration
        int totalCandies = 0;      // Total candies collected
        // Continue while there are boxes to process and at least one box was openable in the last iteration
        while (!initialBoxes.empty() && foundOpenable) {
            foundOpenable = false;
            vector<int> nextBoxes; // Stores boxes to be processed in the next iteration
            for (int boxId : initialBoxes) {
                if (vis[boxId]) { // If the box is openable
                    foundOpenable = true;
                    // Add contained boxes to the list for the next iteration
                    nextBoxes.insert(end(nextBoxes), begin(containedBoxes[boxId]), end(containedBoxes[boxId]));
                    // Mark keys found in this box as available (openable)
                    for (int keyId : keys[boxId]) vis[keyId] = 1;
                    // Collect candies from this box
                    totalCandies += candies[boxId];
                } else {
                    // If the box can't be opened yet, keep it for the next round
                    nextBoxes.push_back(boxId);
                }
            }
            // Prepare for the next iteration
            swap(initialBoxes, nextBoxes);
        }
        
        return totalCandies; // Return the total candies collected
    }
};
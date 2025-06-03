#include <bits/stdc++.h>
using namespace std;

// This code defines a function to calculate the maximum candies that can be collected from boxes,
// given the constraints of keys and contained boxes. It uses a greedy approach to open boxes
// and collect candies until no more boxes can be opened.

class Solution {
public:
    int maxCandies(vector<int>& vis, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        bool foundOpenable = true;
        int totalCandies = 0;
        while (!initialBoxes.empty() && foundOpenable) {
            foundOpenable = false;
            vector<int> nextBoxes;
            for (int boxId : initialBoxes) {
                if (vis[boxId]) {
                    foundOpenable = true;
                    nextBoxes.insert(end(nextBoxes), begin(containedBoxes[boxId]), end(containedBoxes[boxId]));
                    for (int keyId : keys[boxId]) vis[keyId] = 1;
                    totalCandies += candies[boxId];
                } else {
                    nextBoxes.push_back(boxId);
                }
            }
            swap(initialBoxes, nextBoxes);
        }
        
        return totalCandies;
    }
};
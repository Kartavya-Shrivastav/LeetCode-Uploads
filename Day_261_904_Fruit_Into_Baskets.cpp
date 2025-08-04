#include <bits/stdc++.h>
using namespace std;

// Problem: Fruit Into Baskets
// Approach: Use a sliding window technique to find the maximum number of fruits that can be collected in two baskets.

// Steps:
// 1. Initialize two variables to track the last two types of fruits and their counts.  
// 2. Use a single loop to iterate through the array of fruits.
// 3. If the current fruit is one of the last two types, increment the count for that fruit type.
// 4. If the current fruit is a new type, check if we can still use the second basket. If not, we need to remove the oldest fruit type
//    from the basket and update the counts accordingly.
// 5. Update the maximum count of fruits collected whenever a valid basket configuration is found.

// Time Complexity: O(n) where n is the number of fruits, as each fruit is processed at most once.
// Space Complexity: O(1) for the sliding window pointers and counts.

class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int lastFruit = -1, secondLastFruit = -1;
        int lastFruitCount = 0;
        int maxCount = 0, curCount = 0;

        for (int fruit : arr) {
            if (fruit == lastFruit || fruit == secondLastFruit) {
                curCount++;
            } else {
                curCount = lastFruitCount + 1;  // just last streak + new fruit
            }

            if (fruit == lastFruit) lastFruitCount++;
            else {
                lastFruitCount = 1;
                secondLastFruit = lastFruit;
                lastFruit = fruit;
            }

            maxCount = max(maxCount, curCount);
        }
        return maxCount;
    }
};
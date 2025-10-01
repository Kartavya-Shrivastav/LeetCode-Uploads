#include <bits/stdc++.h>
using namespace std;

// Problem: 1518. Water Bottles
// Approach: Mathematical Calculation

// Steps:
// 1. Start with the initial number of full bottles `b`.
// 2. Each time you drink a bottle, you get an empty bottle.
// 3. You can exchange `n` empty bottles for one full bottle.
// 4. The total number of bottles you can drink is the initial full bottles plus the additional bottles obtained through exchanges.
// 5. The formula to calculate the total number of bottles is: total = b + (b - 1) / (n - 1).
// 6. Return the total number of bottles you can drink.

// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    int numWaterBottles(int b, int n) {
        return b + (b - 1) / (n - 1);
    }
};
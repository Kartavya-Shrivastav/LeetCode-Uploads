#include <bits/stdc++.h>
using namespace std;

// Problem: 3100. Water Bottles II
// Approach: Greedy Simulation

// Steps:
// 1. Start with the initial number of full bottles `numBottles`.
// 2. Each time you drink a bottle, you get an empty bottle.
// 3. You can exchange `x` empty bottles for one full bottle.
// 4. The total number of bottles you can drink is the initial full bottles plus the additional bottles obtained through exchanges.
// 5. Use a loop to simulate the process of drinking and exchanging bottles until you can no longer exchange.
// 6. Return the total number of bottles you can drink.

// Time Complexity: O(b/x) in the worst case, where b is the initial number of bottles.
// Space Complexity: O(1)

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int x) {
        int ans = numBottles;
        while (numBottles >= x) {
            numBottles -= x - 1, x++, ans++;
        }
        return ans;
    }
};
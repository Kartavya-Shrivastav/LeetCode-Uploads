#include <vector>
#include <map>
#include <algorithm>
#include <climits>
using namespace std;

// Problem: Rearranging Fruits in Two Baskets
// Approach: Use a map to count occurrences of each fruit, then determine the minimum cost to rearrange them.

// Steps:
// 1. Count the total occurrences of each fruit in both baskets.
// 2. Check if the total count of each fruit is even; if not, return -1 as it's impossible to rearrange.
// 3. Find the minimum fruit value to determine the cost of swapping.
// 4. Create a list of fruits that need to be swapped based on the difference in counts.
// 5. Sort the list of fruits to swap.
// 6. Calculate the total cost by taking the minimum of the fruit value or double the minimum fruit value for each swap.
// 7. Return the total cost.

// Time Complexity: O(n log n) due to sorting the fruits to swap.
// Space Complexity: O(n) for storing the counts and fruits to swap.


class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> total_counts;
        for (int fruit : basket1) total_counts[fruit]++;
        for (int fruit : basket2) total_counts[fruit]++;

        long long min_val = LLONG_MAX;
        for (auto const& [fruit, count] : total_counts) {
            if (count % 2 != 0) return -1;
            min_val = min(min_val, (long long)fruit);
        }
        
        vector<long long> fruits_to_swap;
        map<int, int> count1;
        for (int fruit : basket1) count1[fruit]++;
        
        for (auto const& [fruit, total_count] : total_counts) {
            int diff = count1[fruit] - (total_count / 2);
            for (int i = 0; i < abs(diff); ++i) {
                fruits_to_swap.push_back(fruit);
            }
        }
        
        sort(fruits_to_swap.begin(), fruits_to_swap.end());
        
        long long total_cost = 0;
        int swaps_to_make = fruits_to_swap.size() / 2;
        for (int i = 0; i < swaps_to_make; ++i) {
            total_cost += min(fruits_to_swap[i], 2 * min_val);
        }
        
        return total_cost;
    }
};
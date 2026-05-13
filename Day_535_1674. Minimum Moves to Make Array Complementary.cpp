#include <bits/stdc++.h>
using namespace std;

/*
Problem: You are given an array of integers nums and an integer limit. In one move, you can replace any integer from nums with another integer between 1 and limit, inclusive. The array nums is complementary if for every index i (0-indexed), nums[i] + nums[nums.size() - 1 - i] <= limit. Return the minimum number of moves required to make nums complementary.
Approach: We can solve this problem by using a difference array to keep track of the number of moves required to achieve the complementary condition for each possible target sum of pairs. We will iterate through the first half of the array and calculate the minimum and maximum values for each pair of elements. Based on these values, we will update the difference array to reflect the number of moves needed for each target sum.

Steps:
1. Initialize a difference array delta of size (2 * limit + 2) with all values set to 0.
2. Iterate through the first half of the nums array (from 0 to n/2 - 1):
   a. For each pair of elements (nums[i], nums[n - 1 - i]), calculate the minimum and maximum values.
   b. Update the difference array delta to reflect the moves needed for each target sum based on the minimum and maximum values.    
3. Initialize a variable res to store the minimum moves required and a variable moves to keep track of the current number of moves.
4. Iterate through the possible target sums from 2 to 2 * limit:
   a. Update the moves variable by adding the value from the difference array delta for the current target sum.
   b. Update the res variable to be the minimum of its current value and the moves variable.
5. Return the value of res, which will be the minimum number of moves required to make the array complementary.

Time Complexity: O(n + limit), where n is the size of the nums array and limit is the given integer. The first loop runs in O(n/2) which simplifies to O(n), and the second loop runs in O(limit). 
Space Complexity: O(limit), since we are using a difference array of size (2 * limit +2) to keep track of the moves required for each target sum.
*/

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> delta((limit << 1) + 2, 0);

        for (int i = 0; i < n >> 1; i++) {
            int min = nums[i];
            int max = nums[n - 1 - i];
            if (min > max) swap(min, max);

            delta[2] += 2;
            delta[min + 1]--;
            delta[min + max]--;
            delta[min + max + 1]++;
            delta[max + limit + 1]++;
        }

        int res = n, moves = 0;

        for (int targ = 2; targ <= limit * 2; targ++) {
            moves += delta[targ];
            res = min(res, moves);
        }

        return res;
    }
};
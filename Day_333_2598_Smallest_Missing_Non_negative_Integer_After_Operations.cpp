#include <bits/stdc++.h>
using namespace std;

// Problem: 2598. Smallest Missing Non-negative Integer After Operations
// Approach: Use a frequency array to count occurrences of each remainder when divided by v and then find the smallest missing integer

// Steps:
// 1. Create a frequency array `rem` of size `v` to count occurrences of each remainder when elements in `nums` are divided by `v`.
// 2. Iterate through the `nums` array, compute the non-negative remainder for each element, and increment the corresponding index in the `rem` array.
// 3. Initialize a result variable `res` to 0, which will hold the smallest missing non-negative integer.
// 4. Use a while loop to check the frequency of the current `res` modulo `v` in the `rem` array. If the frequency is greater than 0, decrement it and increment `res`.
// 5. Continue this process until you find a `res` whose frequency in `rem` is 0.
// 6. Return `res` as the smallest missing non-negative integer after the operations.

// Time Complexity: O(n), where n is the size of the `nums` array.
// Space Complexity: O(v) for the frequency array.

class Solution {
public:
	int findSmallestInteger(vector<int>& nums, int v) {
		long long n = nums.size(), x, res = 0;
		vector<int> rem(v, 0);
		for (int i = 0; i < n; i++) {
			x = ((nums[i] % v) + v) % v;
			rem[x]++;
		}

		while (rem[res % v]--) res++;
		return res;
	}
};
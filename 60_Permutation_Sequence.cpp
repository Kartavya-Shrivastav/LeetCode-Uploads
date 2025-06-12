#include <bits/stdc++.h>
using namespace std;
// This code finds the k-th permutation sequence of numbers from 1 to n
// It uses a factorial-based approach to determine the correct sequence without generating all permutations

class Solution {
public:
    // Helper function to compute factorial of n
    int fact(int n) {
        if (n == 0 || n == 1) return 1;
        int ans = 1;
        while (n > 0) {
            ans = ans * n;
            n--;
        }
        return ans;
    }

    // Main function to get the k-th permutation sequence
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int> nums;
        // Initialize the list of numbers from 1 to n
        for (int i = 0; i < n; i++) {
            nums.push_back(i + 1);
        }
        int a = n;
        k--; // Convert k to zero-based index

        // Build the permutation one position at a time
        for (int i = 0; i < a; i++) {
            // Number of permutations for each possible first element
            int choices = fact(n - i - 1);
            // Determine which number should be at the current position
            int q = (k / choices);
            ans += to_string(nums[q]);
            // Remove the used number from the list
            nums.erase(nums.begin() + (q));
            // Update k for the next position
            k = k % choices;
        }
        return ans;
    }
};
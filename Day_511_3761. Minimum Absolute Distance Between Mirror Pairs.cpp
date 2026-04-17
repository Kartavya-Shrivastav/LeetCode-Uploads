#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of integers a, find the minimum absolute distance between any two mirror pairs in the array. A mirror pair is defined as a pair of indices (i, j) such that a[i] is equal to the reverse of a[j].
Approach: We can use a hash map to store the indices of the reversed values of the elements in the array. As we iterate through the array, we check if the current element has a corresponding reversed value in the hash map. If it does, we calculate the distance between the current index and the index stored in the hash map for that reversed value. We keep track of the minimum distance found.

Steps:
1. Create a hash map to store the indices of the reversed values of the elements in the array.
2. Initialize a variable ans to store the minimum distance, starting with a large value (e.g., 1e6).
3. Iterate through the array:
   a. For each element, check if it exists in the hash map. If it does, calculate the distance from the current index to the index stored in the hash map and update ans if this distance is smaller.
   b. Store the index of the reversed value of the current element in the hash map.
4. After iterating through the array, if ans is still the initial large value, return -1 to indicate that no mirror pairs were found. Otherwise, return ans as the minimum distance.

Time Complexity: O(n * k), where n is the size of the array and k is the number of digits in the largest number (for reversing). In practice, since the numbers are typically small, this can be considered O(n).
Space Complexity: O(n), as we are using a hash map to store the indices of the reversed values of the elements in the array.
*/

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& a) {
        unordered_map<int, int> mpp;
        int n = a.size(), ans = 1e6;

        for (int i = 0; i < n; i++) {
            if (mpp.count(a[i])) {
                ans = min(ans, i - mpp[a[i]]);
            }
            mpp[reverse(a[i])] = i;
        }
        return ans == 1e6 ? -1 : ans;
    }
};
#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given two integer arrays A and B of the same length, return an array of length n where res[i] is the number of common elements in the prefix A[0...i] and B[0...i].
Approach: We can solve this problem by using a bitset to keep track of the elements we have seen in both arrays. We will iterate through both arrays simultaneously and for each index i, we will check if the current element in A has been seen before in B and if the current element in B has been seen before in A. If either of these conditions is true, we will increment our count of common elements. We will then set the current elements in both arrays as seen in our bitset. Finally, we will store the count of common elements at index i in our result array.

Steps:
1. Initialize a result array of the same length as A and B to store the count of common elements.
2. Initialize a bitset to keep track of seen elements.
3. Iterate through both arrays simultaneously:
   a. For each index i, check if A[i] has been seen before in B and if B[i] has been seen before in A. If either condition is true, increment the count of common elements.
   b. Set A[i] and B[i] as seen in the bitset.
   c. Store the count of common elements at index i in the result array.

Time Complexity: O(n), where n is the length of the input arrays, since we are iterating through both arrays once.
Space Complexity: O(1) if we consider the bitset size to be constant (since the problem constraints may limit the range of values in A and B), otherwise O(n) if we need to store seen elements in a larger data structure.
*/

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), count = 0;
        vector<int> res(n);
        bitset<51> seen;

        for (int i = 0; i < n; i++) {
            count += seen[A[i]];
            seen.set(A[i]);

            count += seen[B[i]];
            seen.set(B[i]);

            res[i] = count;
        }

        return res;
    }
};
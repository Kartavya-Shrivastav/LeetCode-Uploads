#include <bits/stdc++.h>
using namespace std;

// Problem: Repeated Element in Size 2N Array
// Approach: Since the array contains N+1 occurrences of one element and N occurrences of others, we can find the repeated element by checking for duplicates within a small window. Given the constraints, checking adjacent elements and those two positions apart is sufficient to identify the repeated element.

// Steps:
// 1. Iterate through the array up to the third last element.
// 2. For each element, check if it is equal to the next element or the one after that.
// 3. If a match is found, return that element as the repeated one.
// 4. If no matches are found in the loop, return the last element as it must be the repeated one.
// 5. Return the identified repeated element.

// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as we are using constant extra space.

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (int i = 0; i < A.size() - 2; ++i)
            if (A[i] == A[i + 1] || A[i] == A[i + 2])
                return A[i];
        return A.back();
    }
};

#include <bits/stdc++.h>    
using namespace std;

/*
Problem: Given two non-increasing integer arrays A and B, find the maximum distance between a pair of indices (i, j) such that i <= j and A[i] <= B[j].
Approach: We can use a two-pointer technique to solve this problem efficiently. We will maintain two pointers, i and j, starting at the beginning of arrays A and B respectively. We will iterate through both arrays simultaneously. If A[i] is greater than B[j], we will move the pointer i to the right to find a smaller value in A. If A[i] is less than or equal to B[j], we will move the pointer j to the right to find a larger value in B. During this process, we will keep track of the maximum distance (j - i) whenever we find a valid pair (A[i] <= B[j]).

Steps:
1. Initialize two pointers i and j to 0.    
2. While both pointers are within the bounds of their respective arrays:
   a. If A[i] is greater than B[j], increment i to find a smaller value in A.
   b. If A[i] is less than or equal to B[j], increment j to find a larger value in B and update the maximum distance if (j - i) is greater than the current maximum.
3. After the loop, return the maximum distance found.

Time Complexity: O(n + m), where n and m are the lengths of arrays A and B respectively, since we are traversing both arrays at most once.
Space Complexity: O(1), as we are using only a constant amount of extra space for the pointers and the variable to store the maximum distance.
*/

class Solution {
public:
    int maxDistance(vector<int>& A, vector<int>& B) {
        int i = 0, j = 0;

        while (i < A.size() && j < B.size()) {
            if (A[i] > B[j]) i++;
            j++;
        }
        return max(0, j - i - 1);
    }
};
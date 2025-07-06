#include <bits/stdc++.h>
using namespace std;

// Problem: Given two integer arrays nums1 and nums2, implement a data structure that supports the following operations:
// Approach: Use a hash map to store the frequency of elements in nums2, allowing for efficient updates and queries.

// Steps:
// 1. Initialize the data structure with two integer arrays nums1 and nums2.
// 2. Use an unordered_map to keep track of the frequency of each element in nums2.
// 3. Implement the add operation to update an element in nums2 and adjust its frequency in the hash map.
// 4. Implement the count operation to count how many pairs (i, j) exist such that nums1[i] + nums2[j] equals a given target value t.   
// 5. The count operation iterates through nums1 and uses the hash map to find how many elements in nums2 can form the required sum with each element in nums1.

// Time Complexity - O(n + m) for initialization, O(1) for add operation, and O(n) for count operation, where n is the size of
//                   nums1 and m is the size of nums2.
// Space Complexity - O(m) for storing the frequency counts in the hash map.

class FindSumPairs {
private:
    vector<int> n1, n2;
    unordered_map<int, int> m;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for (int x : n2) {
            m[x]++;
        }
    }

    void add(int i, int v) {
        m[n2[i]]--;
        n2[i] += v;
        m[n2[i]]++;
    }

    int count(int t) {
        int c = 0;
        for (int x : n1) {
            c += m[t - x];
        }
        return c;
    }
};
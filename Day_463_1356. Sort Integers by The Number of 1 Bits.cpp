#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an integer array arr, sort the integers in the array in ascending order by the number of 1's in their binary representation. In case of a tie, sort them in ascending order. 
Approach: Use the built-in function __builtin_popcount to count the number of 1's in the binary representation of each integer. Sort the array using a custom comparator that first compares the number of 1's and then the integers themselves in case of a tie.

Steps:
1. Iterate through the array and count the number of 1's in the binary representation of each integer.
2. Sort the array using a custom comparator that compares the counts of 1's and then the integers themselves in case of a tie.
3. Return the sorted array.

Time Complexity: O(n log n), where n is the length of the array. The sorting operation takes O(n log n) time, and the __builtin_popcount function takes O(1) time for each integer.
Space Complexity: O(1) extra space (not counting the space used by the sorting algorithm).

*/

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[](int& a,int &b)
        {
            int n=__builtin_popcount(a),m=__builtin_popcount(b);
            if(n==m) return a<b;
            return n<m;
        });
        return arr;
    }
};
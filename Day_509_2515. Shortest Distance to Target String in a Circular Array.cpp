#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a circular array of strings words, a string target and an integer start, return the shortest distance from start to the closest occurrence of target in words.
Approach: We can iterate through the circular array starting from the index start and check for the target string. We can check both directions (clockwise and counterclockwise) simultaneously to find the closest occurrence of the target string. The distance is calculated based on the number of steps taken from the start index to reach the target string.

Steps:
1. Get the size of the words array.
2. Iterate through the array from 0 to n/2 (inclusive) to check for the target string in both directions.
3. If the target string is found in either direction, return the distance (i).
4. If the loop completes without finding the target string, return -1 to indicate that the target string is not present in the array.

Time Complexity: O(n), where n is the size of the words array. In the worst case, we may need to check all elements in the array.
Space Complexity: O(1), as we are using only a constant amount of extra space to store variables.
*/

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int start) {
        int n = words.size();
        for (int i = 0; i <= n >> 1; i++)
            if (words[(start + i) % n] == target |
                words[(start - i + n) % n] == target)
                return i;
                
        return -1;
    }
};
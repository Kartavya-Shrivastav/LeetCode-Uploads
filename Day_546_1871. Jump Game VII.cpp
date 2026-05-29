#include <bits/stdc++.h>
using namespace std;

/*
Problem: You are given a binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'. You can move from index i to index j if the following conditions are fulfilled:
- i + minJump <= j <= min(i + maxJump, s.length - 1
- s[j] == '0'
Return true if you can reach index s.length - 1 in s, or false otherwise.

Approach: We can solve this problem using a breadth-first search (BFS) approach. The idea is to maintain a queue of indices that we can jump to and a variable to keep track of the maximum reachable index. We will iterate through the string and for each index, we will check if it is reachable based on the previous jumps and if it is a '0'. If it is reachable, we will add it to the queue and update the maximum reachable index.    

Steps:
1. Initialize a queue to store the indices that we can jump to and a variable `maxR` to keep track of the maximum reachable index.
2. Start from index 0 and mark it as visited (e.g., by changing it to 'v').
3. Iterate through the string starting from index `minJump` to the end of the string.
4. For each index `i`, check if it is greater than `maxR`. If it is, return false since we cannot reach this index.
5. Update the `reach` variable by adding 1 if the index `i - minJump` is marked as visited and subtracting 1 if the index `i - maxJump - 1` is marked as visited (to maintain a sliding window of reachable indices).
6. If `reach` is greater than 0 and the current index `i` is '0', mark it as visited and update `maxR` to `i + maxJump`.
7. After the loop, return true if we have reached the end of the string, otherwise return false.

Time Complexity: O(n) since we need to iterate through the string once.
Space Complexity: O(1) since we are modifying the input string in place and using only a constant amount of extra space for the queue and variables.
*/

class Solution {
public:
    bool canReach(string s, int minJ, int maxJ) {
        int n = s.length();

        if (s.back() & 1) return false;

        s[0] = 'v';
        int reach = 0, maxR = maxJ;

        for (int i = minJ; i < n; i++) {
            if (i > maxR) return false;

            reach += s[i - minJ] == 'v';
            reach -= (i > maxJ) && s[i - maxJ - 1] == 'v';

            if (reach && (~s[i] & 1)) {
                s[i] = 'v';
                maxR = i + maxJ;
            }
        }

        return reach;
    }
};
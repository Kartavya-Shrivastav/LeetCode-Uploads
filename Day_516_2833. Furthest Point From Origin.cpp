#include <bits/stdc++.h>
using namespace std;

/*
Problem: You are given a string moves, where moves[i] is either 'L', 'R', or '_', representing a move to the left, a move to the right, or a blank move, respectively. You start at the origin (0) on a number line. Return the furthest distance from the origin you can get after performing all the moves in the string.
Approach: We can count the number of left moves, right moves, and blank moves in the string. The furthest distance from the origin can be calculated by taking the absolute difference between the number of left and right moves and adding the number of blank moves, since blank moves can be used to move in either direction.

Steps:
1. Initialize three integer variables left, right, and blanks to 0 to count the number of left moves, right moves, and blank moves, respectively.
2. Iterate through each character c in the moves string:
   a. If c is 'L', increment the left counter.
   b. If c is 'R', increment the right counter.
   c. If c is '_', increment the blanks counter.
3. Calculate the furthest distance from the origin using the formula: abs(left - right) + blanks.
4. Return the calculated distance.

Time Complexity: O(n), where n is the length of the moves string, since we need to iterate through the string once to count the moves.
Space Complexity: O(1), since we are using only a constant amount of extra space to store the counters for left, right, and blank moves.
*/

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0, blanks = 0;

        for (char c : moves) {
            if (c == 'L') left++;
            else if (c == 'R') right++;
            else blanks++;
        }

        return abs(left - right) + blanks;
    }
};
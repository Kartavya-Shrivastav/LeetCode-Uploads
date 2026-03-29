#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given two strings s1 and s2, each of length 4, determine if it is possible to make the two strings equal by performing a series of operations. An operation consists of swapping any two characters in one of the strings.
Approach: We can check the characters at the corresponding positions in both strings. For s1 and s2 to be made equal, the characters at positions 0 and 2 must either be the same or swapped, and the characters at positions 1 and 3 must also either be the same or swapped. We can check these conditions directly by comparing the characters at the respective positions in both strings.

Steps:
1. Check if the characters at positions 0 and 2 in s1 can be swapped to match the characters at positions 0 and 2 in s2.
2. Check if the characters at positions 1 and 3 in s1 can be swapped to match the characters at positions 1 and 3 in s2.
3. If both conditions are satisfied, return true; otherwise, return false. 

Time Complexity: O(1) since we are only comparing a fixed number of characters (4 in each string).
Space Complexity: O(1) as we are using only a few boolean variables to store the results of the comparisons, regardless of the size of the input strings.
*/  

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        bool s02=s1[0]==s2[2] && s1[2]==s2[0];
        bool b02=s1[0]==s2[0] && s1[2]==s2[2];
        bool s13=s1[1]==s2[3] && s1[3]==s2[1];
        bool b13=s1[1]==s2[1] && s1[3]==s2[3];
        return ((s02 ||b02)&&(s13 || b13));
    }
};
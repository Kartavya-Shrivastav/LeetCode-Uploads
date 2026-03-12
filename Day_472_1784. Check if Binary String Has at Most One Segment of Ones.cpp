#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a binary string s containing only '0's and '1's, determine if the string contains at most one contiguous segment of '1's. 
A segment of '1's means a group of consecutive '1' characters without interruption by '0'.

Approach: 
The idea is to check whether all the '1's in the string appear in a single continuous block. 
1. Start from the beginning of the string and count the initial continuous '1's.
2. If the entire string consists of '1's, then it obviously has only one segment.
3. Otherwise, find the last occurrence of '1' from the end of the string.
4. If there exists any '0' between the first block of '1's and the last '1', then the string contains more than one segment of '1's.
5. We compare the ending index of the first '1' block and the last '1' index to determine this.

Steps:
1. Get the length of the string `n`.
2. Start from index `0` and move forward while characters are `'1'`. Let the stopping index be `i0`.
3. If `i0 == n`, the string contains only `'1'`, so return `true`.
4. Start from the end of the string (`n-1`) and move backward while characters are `'0'`. Let the stopping index be `i1`.
5. Now `i1` represents the last occurrence of `'1'`.
6. If `i0 > i1`, it means there is no `'1'` after the first block, so there is only one segment of `'1'`.
7. Otherwise, there are multiple segments of `'1'`, so return `false`.

Time Complexity: O(n)  
- In the worst case we scan the string once from the beginning and once from the end.

Space Complexity: O(1)  
- No extra space is used apart from a few variables.
*/

class Solution {
public:
    bool checkOnesSegment(string& s) {
        const int n=s.size();
        
        int i0=0;
        while(s[i0]=='1') i0++;
        if (i0==n) return 1;

        int i1=n-1;
        while(s[i1]=='0') i1--;
        
        return i0>i1;
    }
};
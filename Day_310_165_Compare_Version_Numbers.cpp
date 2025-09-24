#include <bits/stdc++.h>
using namespace std;

// Steps:
// 1. Initialize the sizes of the version strings and variables to store numeric values of version segments (x1 and x2).
// 2. Use a loop to iterate through both version strings until all segments are processed.
// 3. Extract the numeric value of the current segment from v1 by iterating until a dot or the end of the string is encountered.
// 4. Similarly, extract the numeric value of the current segment from v2.
// 5. Compare the extracted numeric values (x1 and x2), returning -1 if x1 < x2, 1 if x1 > x2, and resetting both values to 0 if they are equal.
// 6. If all segments are equal, return 0 after the loop.

// Time Complexity: O(max(m, n)), where m and n are the lengths of the version strings v1 and v2 respectively.
// Space Complexity: O(1), as we are using a constant amount of extra space.

class Solution {
public:
    static int compareVersion(string& v1, string& v2) {
        const int n1=v1.size(), n2=v2.size();
        int x1=0, x2=0;
        for(int i=0, j=0; i<n1 || j<n2; i++, j++){
            while(i<n1 && v1[i]!='.'){
                x1=10*x1+(v1[i++]-'0');
            }
            while(j<n2 && v2[j]!='.'){
                x2=10*x2+(v2[j++]-'0');
            }
            if (x1<x2) return -1;
            else if (x1>x2) return 1;
            x1=0;
            x2=0;
        }
        return 0;
    }
};
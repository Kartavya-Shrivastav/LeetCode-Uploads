#include <bits/stdc++.h>
using namespace std;

// Problem: 11. Container With Most Water
// Approach: Two Pointers Technique to find the maximum area of water container formed by vertical lines 

// Steps:
// 1. Initialize two pointers, one at the start and one at the end of the height array.
// 2. Calculate the area formed between the two pointers and update the maximum area if the current area is larger.
// 3. Move the pointer pointing to the shorter line inward, as this might lead to a larger area.
// 4. Repeat steps 2 and 3 until the two pointers meet.
// 5. Return the maximum area found.

// Time Complexity: O(n), where n is the number of elements in the height array.
// Space Complexity: O(1), as we are using only a constant amount of extra space.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxcap = 0;
        int st=0 , ed = height.size()-1;
        while(ed>st){
            int temp = (ed-st)*(min(height[st] , height[ed]));
            maxcap = max(maxcap , temp);
            if(height[st]<height[ed]) st++;
            else ed--;
        }
        return maxcap;
    }
};
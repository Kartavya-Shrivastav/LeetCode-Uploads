#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an array nums containing n unique binary strings each of length n,
return a binary string of length n that does not appear in nums. If multiple answers
exist, return any of them.

Approach:
We use Cantor's Diagonalization technique.

Instead of searching through all possible binary strings, we construct a new string
by flipping the diagonal elements of the given strings.

For the i-th string:
- If nums[i][i] == '0', we place '1' in the result.
- If nums[i][i] == '1', we place '0' in the result.

This guarantees that the constructed string differs from every string in the list
at least at one position (its diagonal index), ensuring it cannot be equal to any
string in nums.

Steps:
1. Initialize an empty string ans.
2. Traverse the array from i = 0 to n-1.
3. Check the i-th character of the i-th string.
4. Flip the bit:
   - '0' → append '1'
   - '1' → append '0'
5. Append this flipped bit to ans.
6. After the loop, return ans.

Example:
nums = ["01","10"]

i = 0 → nums[0][0] = '0' → append '1'
i = 1 → nums[1][1] = '0' → append '1'

Result = "11"

This string differs from both "01" and "10".

Time Complexity: O(n)
- We iterate once through the array.

Space Complexity: O(n)
- The result string of length n is created.
*/



class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        for(int i=0; i<nums.size(); i++){
            if(nums[i][i] == '0') ans+= '1';
            else ans += '0';
        }

        return ans;
    }
};
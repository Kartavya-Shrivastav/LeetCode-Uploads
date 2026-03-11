#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given two integers n and k, return the k-th bit in the n-th binary string. The n-th binary string is defined as follows:
- S1 = "0"  
- Si = Si-1 + "1" + reverse(invert(Si-1)) for i > 1, where reverse(x) is the reversed string of x and invert(x) is the string obtained by inverting all bits in x (0 changes to 1 and 1 changes to 0).
Approach: We can use a recursive approach to find the k-th bit in the n-th  binary string. The length of the n-th binary string can be calculated as 2^n - 1. We can determine the position of k in relation to the middle of the string to decide whether to look in the left half, the middle bit, or the right half of the string.   
Steps:
1. Calculate the length of the n-th binary string as len = 2^n - 1.
2. Calculate the middle position as mid = (len + 1) / 2.    
3. If k is equal to mid, return '1' as the middle bit is always '1'.
4. If k is less than mid, recursively call the function to find the k-th bit in the (n-1)-th binary string.
5. If k is greater than mid, recursively call the function to find the (len - k + 1)-th bit in the (n-1)-th binary string.
6. In the case of the right half, we need to invert the bit found in the (n-1)-th binary string before returning it, as the right half is the inverted version of the left half.

Time Complexity: O(n) in the worst case, as we may need to make n recursive calls to find the k-th bit.
Space Complexity: O(n) due to the recursive call stack in the worst case.
*/

class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        
        int len = (1 << n) - 1;
        int mid = (len + 1) / 2;
        
        if (k == mid) return '1';
        if (k < mid) return findKthBit(n - 1, k);
        
        char c = findKthBit(n - 1, len - k + 1);
        return c == '0' ? '1' : '0';
    }
};
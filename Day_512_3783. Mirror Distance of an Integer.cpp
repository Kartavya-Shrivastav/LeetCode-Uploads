#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an integer n, find the mirror distance of n, which is defined as the absolute difference between n and its reverse.
Approach: We can reverse the integer n by repeatedly taking the last digit and building the reversed number. After obtaining the reversed number, we can calculate the mirror distance by taking the absolute difference between n and its reverse.

Steps:
1. Initialize a variable rev to store the reversed number, starting at 0.   
2. Use a loop to reverse the integer n:
   a. In each iteration, take the last digit of n (n % 10) and add it to rev after multiplying rev by 10 to shift the digits left.
   b. Remove the last digit from n by dividing it by 10 (n /= 10).
3. After the loop, calculate the mirror distance as the absolute difference between n and rev.
4. Return the mirror distance.

Time Complexity: O(k), where k is the number of digits in n, since we are reversing the integer by processing each digit once.
Space Complexity: O(1), as we are using only a constant amount of extra space for the variable to store the reversed number and the mirror distance.
*/

class Solution {
public:
    int mirrorDistance(int n) {
        long long rev=0;
        for(int x=n; x; x/=10){
            rev=10*rev+x%10;
        }
        rev-=n;
        return rev>=0?rev:-rev;
    }
};
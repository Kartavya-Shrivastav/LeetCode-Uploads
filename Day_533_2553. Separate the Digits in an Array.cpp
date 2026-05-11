#include <bits/stdc++.h>
using namespace std;

/*
Problem: You are given a 0-indexed integer array nums. Separate the digits of each integer in nums and return the new array. The digits are returned in the same order as they appear in nums.
Approach: We can solve this problem by iterating through each integer in the nums array, converting it to a string to access each digit, and then converting each character back to an integer before adding it to the result array.

Steps:
1. Initialize an empty vector result to store the separated digits.
2. Iterate through each integer num in the nums array.
3. Convert the integer num to a string s using the to_string function.
4. Iterate through each character ch in the string s.
5. Convert the character ch back to an integer by subtracting '0' from it and push it to the result vector.
6. Finally, return the result vector containing all the separated digits.

Time Complexity: O(n * m), where n is the number of integers in the nums array and m is the average number of digits in each integer, since we are iterating through each integer and then through each digit of that integer.
Space Complexity: O(n * m), since we are storing the separated digits in a new vector that can potentially contain all the digits of the integers in the nums array.
*/

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        for (int num : nums) {
            string s = to_string(num);
            for (char ch : s) {
                result.push_back(ch - '0');
            }
        }
        return result;
    }
};
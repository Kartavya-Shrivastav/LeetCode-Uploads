#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a special binary string s, a special binary string is a binary string with the following two properties:
         1. The number of 0's is equal to the number of 1's.
         2. Every prefix of the binary string has at least as many 1's as 0's.
You are allowed to swap two consecutive, non-empty, special binary substrings of s any number of times. Return the lexicographically largest 
resulting string possible.

Approach: We can use a recursive approach to solve this problem. We will first split the input string into its special binary substrings. For each 
special binary substring, we will recursively call the function to get the largest possible string for that substring. After we have processed all 
the special binary substrings, we will sort them in descending order and concatenate them to get the final result. 

Steps:
1. If the input string s is empty, return it.
2. Initialize an empty vector ans to store the special binary substrings and a counter cnt to keep track of the balance of 1's and 0's.
3. Iterate through the string s using a loop. For each character, update the counter cnt by incrementing it for '1' and decrementing it for '0'.
4. Whenever the counter cnt becomes zero, it means we have found a special binary substring. We will extract this substring and recursively call the
   function makeLargestSpecial on the inner part of the substring (excluding the first '1' and the last '0') to get the largest possible string for 
   that substring. We will then add "1" + result of recursive call + "0" to the ans vector.
5. After processing all characters, we will sort the ans vector in descending order to get the largest possible arrangement of the special binary 
   substrings.
6. Finally, we will concatenate all the strings in the ans vector and return the result.

Time Complexity: O(n log n) where n is the length of the input string s, due to the sorting step. The recursive calls will also contribute to the time 
                 complexity, but it will be less than O(n log n) in total.
Space Complexity: O(n) due to the recursive call stack and the space used for storing the special binary substrings in the ans vector.
*/

class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s == "") return s;
        vector<string> ans;
        int cnt = 0;
        for (int i = 0, j = 0; i < s.size(); ++i) {
            cnt += s[i] == '1' ? 1 : -1;
            if (cnt == 0) {
                ans.push_back("1" + makeLargestSpecial(s.substr(j + 1, i - j - 1)) + "0");
                j = i + 1;
            }
        }
        sort(ans.begin(), ans.end(), greater<string>{});
        return accumulate(ans.begin(), ans.end(), ""s);
    }
};
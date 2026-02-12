#include <bits/stdc++.h> 
using namespace std;

// Problem: Given a string s consisting of lowercase English letters, return the length of the longest balanced substring of s. A substring is balanced if each character that appears in the substring appears the same number of times as every other character that appears in the substring. // Example 1: // Input: s = "aabb" // Output: 4 // Explanation: The whole string is balanced since 'a' and 'b' both appear twice. // Example 2: // Input: s = "abcde" // Output: 1 // Explanation: Every substring of length 1 is balanced since each character appears once. // Example 3: // Input: s = "aaabbb" // Output: 6 // Explanation: The whole string is balanced since 'a' and 'b' both appear three times. // Constraints: // 1 <= s.length <= 10^5 // s consists of lowercase English letters.
// Approach: We can use a brute-force approach to check all possible substrings of the input string and determine if they are balanced. We can maintain a frequency array to count the occurrences of each character in the current substring. For each substring, we can check if all characters that appear have the same frequency. If they do, we update our maximum length of a balanced substring. This approach has a time complexity of O(n^2) due to the nested loops for generating substrings and checking their balance.

// Steps:
// 1. Initialize a frequency array to count occurrences of each character. 
// 2. Use two nested loops to generate all possible substrings of the input string.
// 3. For each substring, update the frequency array and check if it is balanced. 
// 4. If it is balanced, update the maximum length of a balanced substring found so far. 
// 5. Return the maximum length after checking all substrings.

// Time Complexity: O(n^2) due to the nested loops for generating substrings and checking their balance. 
// Space Complexity: O(1) since the frequency array has a fixed size of 26 for lowercase English letters.

int freq[26]={0};
class Solution {
public:
    static int longestBalanced(string& s) {
        int cnt=1, n=s.size();
        for(int l=0; l<n; l++){
            memset(freq, 0, sizeof(freq));
            int uniq=0, maxF=0, cntMax=0;
            for(int r=l; r<n; r++){
                int f=++freq[s[r]-'a'];
                uniq+=(f==1);
                if (f>maxF){ maxF=f; cntMax=1; }
                else if (f==maxF) cntMax++;
                if (uniq==cntMax) 
                    cnt=max(cnt, r-l+1);
            }
        }
        return cnt;
    }
};
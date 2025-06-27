#include <bits/stdc++.h>
using namespace std;

// Problem: Longest Subsequence Repeated k Times
// Approach: Use a queue to explore all possible subsequences and check if they can be formed k times in the original string.

// Steps:
// 1. Count the frequency of each character in the string.
// 2. Create a valid character set that can be used to form subsequences.
// 3. Use a queue to explore all possible subsequences starting from an empty string.
// 4. For each subsequence, check if it can be formed k times in the original string.
// 5. Keep track of the longest valid subsequence found.
// 6. Return the longest subsequence that can be formed k times.

// Time Complexity: O(n * 26^m), where n is the length of the string and m is the number of valid characters (at most 26).
// Space Complexity: O(n), for storing the queue and the longest subsequence.

class Solution {
public:
    // Helper function to check if string x repeated k times is a subsequence of s
    bool isKSubsequence(const string& s, const string& x, int k) {
        string t;
        // Build the string t by repeating x k times
        for (int i = 0; i < k; ++i) t += x;
        int j = 0;
        // Check if t is a subsequence of s
        for (char ch : s) {
            if (j < t.size() && ch == t[j]) j++;
        }
        return j == t.size();
    }

    // Main function to find the longest subsequence repeated k times
    string longestSubsequenceRepeatedK(string s, int k) {
        unordered_map<char, int> freq;
        // Count frequency of each character in s
        for (char ch : s) freq[ch]++;
        
        string valid;
        // Build a string of valid characters (those that appear at least k times)
        for (char ch = 'z'; ch >= 'a'; --ch) {
            if (freq[ch] >= k) valid += ch;
        }

        queue<string> q;
        q.push(""); // Start with an empty string
        string res = "";

        // BFS: Explore all possible subsequences using valid characters
        while (!q.empty()) {
            string curr = q.front(); q.pop();
            // Try appending each valid character to the current subsequence
            for (char ch : valid) {
                string next = curr + ch;
                // Check if next repeated k times is a subsequence of s
                if (isKSubsequence(s, next, k)) {
                    // Update result if next is longer or lexicographically greater
                    if (next.length() > res.length() || (next.length() == res.length() && next > res)) {
                        res = next;
                    }
                    // Push next to queue for further exploration
                    q.push(next);
                }
            }
        }

        return res;
    }
};
#include <bits/stdc++.h>
using namespace std;

// Problem: Given a string s consisting of lowercase English letters, return the length of the longest balanced substring of s. A substring is balanced if each character that appears in the substring appears the same number of times as every other character that appears in the substring. // Example 1: // Input: s = "aabb" // Output: 4 // Explanation: The whole string is balanced since 'a' and 'b' both appear twice. // Example 2: // Input: s = "abcde" // Output: 1 // Explanation: Every substring of length 1 is balanced since each character appears once. // Example 3: // Input: s = "aaabbb" // Output: 6 // Explanation: The whole string is balanced since 'a' and 'b' both appear three times. // Constraints: // 1 <= s.length <= 10^5 // s consists of lowercase English letters.
// Approach: We can solve this problem by considering three cases: substrings that contain only one character, substrings that contain exactly two characters, and substrings that contain exactly three characters. For the first case, we can simply count the longest run of each character. For the second case, we can use a two-pointer approach to find the longest substring where the counts of the two characters are equal. For the third case, we can use a similar approach but with a more complex state to track the counts of all three characters. This approach has a time complexity of O(n) for each case, resulting in an overall time complexity of O(n).

// Steps:   
// 1. Implement a function to find the longest run of a single character in the string.
// 2. Implement a function to find the longest balanced substring that contains exactly two characters using a two-pointer approach and a hash map to track the counts of the characters.
// 3. Implement a function to find the longest balanced substring that contains exactly three characters using a similar approach but with a more complex state to track the counts of all three characters.
// 4. Call these functions for all relevant character combinations and return the maximum length found.

// Time Complexity: O(n) for each case, resulting in an overall time complexity of O(n).
// Space Complexity: O(n) for the hash maps used in the two-character and three-character cases.

class Solution {
public:
    int longestBalanced(string s) {
        int results[7] = {
            solve1(s, 'a'),
            solve1(s, 'b'),
            solve1(s, 'c'),
            solve2(s, 'a', 'b'),
            solve2(s, 'a', 'c'),
            solve2(s, 'b', 'c'),
            solve3(s)
        };
        int ans = 0;
        for (int v : results) ans = max(ans, v);
        return ans;
    }

private:
    int solve1(const string& s, char t) {
        int result = 0;
        int count = 0;
        for (char c : s) {
            if (c == t) {
                count++;
                result = max(result, count);
            } else {
                count = 0;
            }
        }
        return result;
    }

    int solve2(const string& s, char t1, char t2) {
        int result = 0;
        int counts[2] = {0, 0};
        unordered_map<int, int> previousPositions;
        for (int i = 0; i < (int)s.size(); i++) {
            char c = s[i];
            if (c != t1 && c != t2) {
                previousPositions.clear();
                counts[0] = 0;
                counts[1] = 0;
            } else {
                if (c == t1) counts[0]++; else counts[1]++;
                if (counts[0] == counts[1]) {
                    result = max(result, counts[0] * 2);
                } else {
                    int diff = counts[0] - counts[1];
                    auto it = previousPositions.find(diff);
                    if (it != previousPositions.end()) {
                        result = max(result, i - it->second);
                    } else {
                        previousPositions[diff] = i;
                    }
                }
            }
        }
        return result;
    }

    int solve3(const string& s) {
        int result = 0;
        int counts[3] = {0, 0, 0};
        unordered_map<long long, int> previousPositions;
        for (int i = 0; i < (int)s.size(); i++) {
            counts[s[i] - 'a']++;
            if (counts[0] == counts[1] && counts[1] == counts[2]) {
                result = i + 1;
            } else {
                long long diff = (long long)(counts[0] - counts[1]) * 100001LL + (long long)(counts[1] - counts[2]);
                auto it = previousPositions.find(diff);
                if (it != previousPositions.end()) {
                    result = max(result, i - it->second);
                } else {
                    previousPositions[diff] = i;
                }
            }
        }
        return result;
    }
};
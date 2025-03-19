#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int start = 0;
        int maxLength = 0;

        for (int end = 0; end < s.size(); ++end) {
            while (charSet.count(s[end])) {
                charSet.erase(s[start]);
                start += 1;
            }
    
            charSet.insert(s[end]);
            maxLength = std::max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};
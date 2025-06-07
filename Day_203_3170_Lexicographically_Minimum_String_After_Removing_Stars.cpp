#include <bits/stdc++.h>
using namespace std;
// This code defines a function to clear stars from a string and return the lexicographically smallest string
// by replacing stars with the last character in the corresponding bucket of characters.

class Solution {
public:
    string clearStars(string s) {
         string ans = s;
        vector<vector<int>> buckets(26);

        for (int i = 0; i < s.length(); ++i)
        if (s[i] == '*') {
            ans[i] = ' ';
            int j = 0;
            while (buckets[j].empty())
            ++j;
            ans[buckets[j].back()] = ' ', buckets[j].pop_back();
        } else {
            buckets[s[i] - 'a'].push_back(i);
        }

        std::erase(ans, ' ');
        return ans;
    }
};
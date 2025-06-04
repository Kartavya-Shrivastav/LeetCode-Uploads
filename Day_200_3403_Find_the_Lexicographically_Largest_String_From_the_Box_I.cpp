#include <bits/stdc++.h>
using namespace std;
// This code defines a function to find the lexicographically largest substring of a given word
// that can be formed by removing a specified number of characters (numFriends - 1).

class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;
        string res = "";
        for (int i = 0 ; i < word.size() ; i++) 
            res = max(res, word.substr(i, word.length() - numFriends + 1));
        return res;
    }
};
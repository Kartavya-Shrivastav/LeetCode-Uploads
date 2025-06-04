#include <bits/stdc++.h>
using namespace std;
// This code defines a function to find the lexicographically largest substring of a given word
// that can be formed by removing a specified number of characters (numFriends - 1).

class Solution {
public:
    // Returns the lexicographically largest substring that can be formed
    // by removing (numFriends - 1) characters from the input string 'word'.
    string answerString(string word, int numFriends) {
        // If only one friend, return the whole word
        if (numFriends == 1) return word;
        string res = "";
        // Iterate through all possible starting positions
        for (int i = 0 ; i < word.size() ; i++) 
            // For each position, consider the substring of length (word.length() - numFriends + 1)
            // and update 'res' if this substring is lexicographically larger
            res = max(res, word.substr(i, word.length() - numFriends + 1));
        return res;
    }
};
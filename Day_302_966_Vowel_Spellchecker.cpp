#include <bits/stdc++.h>
using namespace std;

// Problem: Given a wordlist and a list of queries, implement a spellchecker that corrects the queries based on specific rules.
// Approach: Use hash sets and maps to store the original words, case-insensitive versions, and vowel-error versions of the words. For each query, check against these data structures in order of priority.

// Steps:
// 1. Store the original words in an unordered set for exact matches.
// 2. Create two unordered maps: one for case-insensitive matches and another for vowel-error matches.
// 3. For each query, first check for an exact match in the set.
// 4. If no exact match, check the case-insensitive map.
// 5. If still no match, check the vowel-error map.
// 6. If no matches are found, return an empty string for that query.

// Time Complexity: O(m + n) where m is the total length of words in wordlist and n is the total length of queries.
// Space Complexity: O(m) for storing the words in the set and maps.

class Solution {
public:
    static constexpr unsigned vowMask=(1<<('A'&31))+(1<<('E'&31))+(1<<('I'&31))+(1<<('O'&31))+(1<<('U'&31));
    static string tolow(string w) {
        for (char& c : w) c = tolower(c);
        return w;
    }

    static string toDeV(string w) {
        for (char& c : w)
            if((vowMask>>(c&31))&1) c = '$';
        return w;
    }

    static vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> W(wordlist.begin(), wordlist.end());
        unordered_map<string, string> Wlow, WdeV;

        for (const auto& w : wordlist) {
            string lw = tolow(w), dv = toDeV(lw);
            if (!Wlow.count(lw)) Wlow[lw] = w;
            if (!WdeV.count(dv)) WdeV[dv] = w;
        }

        for (auto& q : queries) {
            if (W.count(q)) continue;
            string low = tolow(q), deV = toDeV(low);
            if (Wlow.count(low)) q = Wlow[low];
            else if (WdeV.count(deV)) q = WdeV[deV];
            else q = "";
        }
        return queries;
    }
};

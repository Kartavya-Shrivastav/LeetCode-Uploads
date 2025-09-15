#include <bits/stdc++.h>
using namespace std;

// Problem: Count words in text that can be typed without using broken letters.
// Approach: Use a bitmask to represent broken letters and check each word against it.

// Steps:
// 1. Create a bitmask for broken letters.
// 2. Split the text into words and check if any letter in a word is in the broken letters bitmask.
// 3. Count the words that can be typed without using broken letters.
// 4. Return the count.

// Time Complexity: O(n + m) where n is the length of text and m is the length of brokenLetters.
// Space Complexity: O(1) since the bitmask uses a fixed amount of space.

class Solution {
public:
    int canBeTypedWords(string& text, string& brokenLetters) {
        unsigned mask=0;
        for(char c: brokenLetters)
            mask|=(1<<(c-'a'));
        int cnt=0;
        bool word=1;
        text.push_back(' ');
        for(char c: text){
            if (c==' '){
                cnt+=word;
                word=1;
            }
            else if (mask &(1<<(c-'a'))) word=0;  
        }
        return cnt;
    }
};
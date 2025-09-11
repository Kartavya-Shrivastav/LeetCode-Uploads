#include <bits/stdc++.h>
using namespace std;

// Problem: Given a string, sort only the vowels in ascending order while keeping the consonants in their original positions.
// Approach: Extract the vowels, sort them, and then reinsert them back into their original positions in the string.

// Steps:
// 1. Traverse the string and collect all vowels in a separate list.
// 2. Sort the list of vowels.
// 3. Traverse the string again, and whenever a vowel is encountered, replace it with the next vowel from the sorted list.
// 4. Return the modified string.

// Time Complexity: O(n log n) due to sorting the vowels, where n is the length of the string.
// Space Complexity: O(m) where m is the number of vowels in the string.

class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        for(char c: s){
            if(c=='a' || c=='e'|| c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
                vowels.push_back(c);
            }
        }
        sort(vowels.begin(), vowels.end());
        int i = 0, j= 0;
        while(i<s.size() && j<vowels.size()){
            if(s[i]=='a' || s[i]=='e'|| s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E'|| s[i]=='I' || s[i]=='O' || s[i]=='U'){
                s[i] = vowels[j];
                j++;
            }
            i++;
        }
        return s;
    }
};
#include<bits/stdc++.h>
using namespace std;

// Steps:
// 1. Initialize an empty vector `ans` to store the resultant array.
// 2. Push the first word from the input `words` array into `ans`.
// 3. Iterate through the `words` array starting from the second word.
// 4. For each word, create two copies: `a` (current word) and `b` (last word in `ans`).
// 5. Sort both `a` and `b` to check if they are anagrams.
// 6. If `a` is not equal to `b`, it means the current word is not an anagram of the last word in `ans`, so push it into `ans`.
// 7. After iterating through all words, return the `ans` vector containing the resultant array after removing anagrams.

// Time Complexity: O(n * m log m), where n is the number of words and m is the maximum length of a word. Sorting each word takes O(m log m).
// Space Complexity: O(n * m), where n is the number of words and m is the maximum length of a word, for storing the resultant array.

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
       vector<string>ans;
       ans.push_back(words[0]);
       for(int i=1;i<words.size();i++){
        string a=words[i];
        string b=ans.back();
        sort(a.begin(),a.end()),sort(b.begin(),b.end());
        if(a!=b)
        ans.push_back(words[i]);
       } 
       return ans;
    }
};
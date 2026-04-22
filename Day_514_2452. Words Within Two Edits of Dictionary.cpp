#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given two string arrays queries and dictionary, return a list of all strings in queries that are within two edits of any string in dictionary. A string s is within two edits of a string t if the Levenshtein distance between s and t is less than or equal to 2.
Approach: We can iterate through each string in the queries array and compare it with each string in the dictionary array. For each pair of strings, we can calculate the number of character differences between them. If the number of differences is less than or equal to 2, we can add the query string to our answer list.

Steps:
1. Initialize an empty vector ans to store the result.  
2. Iterate through each string it in the queries array:
   a. For each string i in the dictionary array, initialize a variable diff to count the number of character differences.
   b. Compare the characters of it and i at each index. If they are different, increment the diff counter.
   c. If at any point diff exceeds 2, break out of the inner loop since we only care about strings that are within two edits.
   d. If after comparing all characters, diff is less than or equal to 2, add it to the ans vector and break out of the inner loop to move on to the next query string.
3. Return the ans vector containing all query strings that are within two edits of any string in the dictionary.

Time Complexity: O(m * n * k), where m is the number of strings in queries, n is the number of strings in dictionary, and k is the length of the strings (assuming all strings have the same length). This is because we compare each query string with each dictionary string, and for each comparison, we check each character.
Space Complexity: O(m), where m is the number of strings in queries, since in the worst case, all query strings could be added to the answer list.
*/

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n=queries[0].size();
        vector<string> ans;
        for(auto &it:queries){
            for(auto &i:dictionary){
                int diff=0;
                for(int idx=0; idx<n; idx++){
                    if(it[idx]!=i[idx]){
                        diff++;
                    }
                    if(diff>2) break;
                }
                if(diff<=2){
                    ans.push_back(it);
                    break;
                }
            }
        }
        return ans;
    }
};
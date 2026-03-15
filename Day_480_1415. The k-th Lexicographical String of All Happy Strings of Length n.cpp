#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given two integers n and k, return the k-th lexicographical string of all happy strings of length n. A happy string is a string that consists only of letters 'a', 'b', and 'c', and no two adjacent characters are the same.
Approach: We can use backtracking to generate all happy strings of length n in lexicographical order. We will maintain a temporary string and a counter k to keep track of how many happy strings we have generated so far. When we generate a happy string of length n, we will decrement k. If k becomes 0, we have found our answer.

Steps:
1. Create a helper function generate that takes the current length of the temporary string, the counter k, the list of letters, the temporary string, and the answer string as parameters.
2. If the length of the temporary string is equal to n, decrement k. If k is 0, set the answer string to the temporary string and return.
3. Loop through the list of letters. If the temporary string is not empty and the last character is the same as the current letter, skip to avoid adjacent characters being the same.
4. Otherwise, append the current letter to the temporary string and recursively call the generate function.
5. After the recursive call, remove the last character from the temporary string to backtrack and continue generating other combinations.

Time Complexity: O(3^n) in the worst case, since we are generating all possible combinations of happy strings of length n.
Space Complexity: O(n) for the temporary string used in the backtracking process, and O(1) for the answer string since we are only storing one happy string at a time.  
*/

class Solution {
public:
    void generate(int n, int& k, vector<char>& letters, string& temp, string& ans) {
        if (temp.size() == n) {
            k--;
            if (k == 0) ans = temp;  // found the kth one
            return;
        }

        for (int i = 0; i < 3; i++) {
            if (!temp.empty() && temp.back() == letters[i]) continue;
            temp.push_back(letters[i]);
            generate(n, k, letters, temp, ans);
            temp.pop_back();
            if (!ans.empty()) return;  // found answer, stop early
        }
    }

    string getHappyString(int n, int k) {
        vector<char> letters = {'a', 'b', 'c'};
        string temp = "", ans = "";
        generate(n, k, letters, temp, ans);
        return ans;
    }
};
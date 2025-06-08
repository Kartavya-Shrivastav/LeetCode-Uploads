#include <bits/stdc++.h>
using namespace std;
// This code defines a function to generate numbers in lexicographical order from 1 to n
// by using a depth-first search (DFS) approach to traverse the number tree.

class Solution {
public:
    vector<int> lexicalOrder(int n) {
         vector<int> ans;
        int curr = 1;

        while (ans.size() < n) {
        ans.push_back(curr);
        if (curr * 10 <= n) {
            curr *= 10;
        } else {
            while (curr % 10 == 9 || curr == n)
            curr /= 10;
            ++curr;
        }
        }

        return ans;
    }
};
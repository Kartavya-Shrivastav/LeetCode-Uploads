#include <bits/stdc++.h>    
using namespace std;

// Problem Statement: Given a string s consisting of characters 'a' and 'b', find the minimum number of deletions required to make the string balanced. A string is considered balanced if there are no instances of 'b' followed by 'a' in the string.
// Approach: We can iterate through the string and count the number of 'b's encountered. Whenever we encounter an 'a' after counting some 'b's, it indicates that we have an instance of 'b' followed by 'a'. In such cases, we can either delete the 'a' or one of the previously counted 'b's to maintain the balance. We will keep track of the number of deletions required to achieve this balance.

// Steps:
// 1. Initialize a counter for 'b's and a result variable to count deletions.
// 2. Iterate through each character in the string:
//    - If the character is 'b', increment the 'b' counter.
//    - If the character is 'a' and there are counted 'b's, it indicates an imbalance. Increment the result for deletions and decrement the 'b' counter to maintain balance.
// 3. Return the total number of deletions required.

// Time Complexity: O(N), where N is the length of the string, as we need to iterate through the string once.
// Space Complexity: O(1), as we are using only a few variables to keep track of counts and results.

class Solution {
public:
    int minimumDeletions(string s) {
        int res = 0, b = 0;

        for (auto& c : s) {
            if (~c & 1) b++;
            else if (b) {
                res++;
                b--;
            }
        }

        return res;
    }
};
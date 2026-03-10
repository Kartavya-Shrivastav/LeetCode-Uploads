#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a binary string s and an integer k, return the minimum number of operations required to make all characters of s equal. In one operation, you can choose any index i and flip the character at that index (from '0' to '1' or from '1' to '0') and also flip the characters at indices i + k, i + 2k, and so on.
Approach: We can count the number of '0's in the string and determine how many operations are needed to flip them to '1's. We also need to consider the cases where we can flip '1's to '0's if it leads to fewer operations. We will calculate the number of operations needed for both scenarios (flipping '0's to '1's and flipping '1's to '0's) and return the minimum of the two.

Steps:
1. Count the number of '0's in the string.
2. If there are no '0's, return 0 as all characters are already equal.
3. If the length of the string is equal to k, check if all characters are '0's or all are '1's and return the appropriate number of operations.
4. Calculate the number of operations needed to flip '0's to '1's and '1's to '0's based on the counts and the value of k.
5. Return the minimum number of operations required.

Time Complexity: O(n), where n is the length of the string. We need to iterate through the string to count the number of '0's and calculate the operations.
Space Complexity: O(1) extra space, as we are using only a few variables to keep track of counts and operations.
*/

class Solution {
public:
    int minOperations(string s, int k) {
        int zero = 0;
        int len = s.length();

        for (int i = 0; i < len; i++)
            zero += ~s[i] & 1;

        if (!zero)
            return 0;

        if (len == k)
            return ((zero == len) << 1) - 1;

        int base = len - k;

        int odd = max(
            (zero + k - 1) / k,
            (len - zero + base - 1) / base
        );

        odd += ~odd & 1;

        int even = max(
            (zero + k - 1) / k,
            (zero + base - 1) / base
        );

        even += even & 1;

        int res = INT_MAX;

        if ((k & 1) == (zero & 1))
            res = min(res, odd);

        if (~zero & 1)
            res = min(res, even);

        return res == INT_MAX ? -1 : res;
    }
};
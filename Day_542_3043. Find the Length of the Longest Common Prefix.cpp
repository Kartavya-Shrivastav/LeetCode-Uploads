#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given two integer arrays arr1 and arr2, return the length of the longest common prefix of any number in arr1 and any number in arr2. A prefix of a number is defined as any leading contiguous sequence of digits in the number.
Approach: We can solve this problem by first storing all the prefixes of the numbers in arr1 in a hash set. Then, for each number in arr2, we can check its prefixes starting from the longest one to see if it exists in the hash set. If we find a match, we can update our answer with the length of that prefix and break out of the loop since we are checking from longest to shortest.

Steps:
1. Create an unordered set to store the prefixes of the numbers in arr1.
2. For each number in arr1, generate all its prefixes and insert them into the set.
3. Initialize a variable to keep track of the longest common prefix length.
4. For each number in arr2, generate its prefixes starting from the longest one and check if it exists in the set. If it does, update the longest common prefix length and break out of the loop for that number.
5. Return the longest common prefix length.

Time Complexity: O(n * m), where n is the length of arr1 and m is the average number of digits in the numbers. This is because we are generating prefixes for each number in arr1 and checking prefixes for each number in arr2.
Space Complexity: O(n * m) in the worst case, if all numbers in arr1 have unique prefixes. However, in practice, the number of unique prefixes may be much smaller than n * m, especially if there are common prefixes among the numbers in arr1.
*/

class Solution {
public:
    int digits(int x) {
        int cnt = 0;
        while(x > 0) {
            cnt++;
            x /= 10;
        }
        return cnt;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;

        // storing all prefixes of arr1
        for(int num : arr1) {
            int x = num;
            while(x > 0) {
                prefixes.insert(x);
                x /= 10;
            }
        }

        int ans = 0;

        // check prefixes of arr2 numbers
        for(int num : arr2) {
            int x = num;
            int len = digits(num);

            // checking from larger => smaller
            while(x > 0) {
                if(prefixes.count(x)) {
                    ans = max(ans, len);
                    break;// first match is the longest, so we stop
                }
                x /= 10;
                len--;
            }
        }

        return ans;
    }
};
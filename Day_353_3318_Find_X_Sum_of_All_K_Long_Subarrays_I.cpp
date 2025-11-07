#include <bits/stdc++.h>
using namespace std;

// Problem: Find X Sum of All K Long Subarrays I
// Approach: For each k-length subarray, count the frequency of each element (0 to 50) using a counting array. Then, calculate the sum of the largest x unique elements by iterating through the counting array in descending order. Repeat this for all k-length subarrays and store the results.

// Steps:
// 1. Initialize a frequency array to count occurrences of each element in the current k-length subarray.
// 2. For each k-length subarray, call the xsum function to get the sum of the largest x unique elements.
// 3. Store the result for each subarray in the answer vector.
// 4. Return the answer vector containing sums for all k-length subarrays.

// Time Complexity: O(n * (k + 51)) where n is the number of elements in nums, k is the length of each subarray, and 51 is the range of possible element values (0 to 50).
// Space Complexity: O(1) for the counting array since its size is fixed (51).

class Solution {
public:
    int xsum( int count[], int x)
    {
        int sum = 0;
        while( x > 0)
        {
            int maxc = 0;
            int temp ;
            for( int i = 0; i < 51; i++)
            {
                if( maxc <= count[i])
                {
                    maxc = count[i];
                    temp = i;
                }
            }
            if( maxc == 0)
            {
                break;
            }
            else
            {
                while( count[temp] != 0)
                {
                    sum = sum + temp;
                    count[temp]--;
                }
            }
            x--;
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int end = 0; 
        int start = k - 1;
        vector <int> ans;
        while( start < n)
        {
            int count[51] = {0};
            for( int i = end; i <= start; i++)
            {
                count[nums[i]]++;
            }
            int sum = xsum(count , x);
            ans.push_back(sum);
            start ++;
            end ++;
        }
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;

// Problem: Find the maximum frequency of an element after performing operations
// Approach: Two Pointers + Counting

// Steps:
// 1. Sort the input array to facilitate range queries.
// 2. Use two pointers to maintain a sliding window that captures elements within the range [num - k, num + k].
// 3. For each unique element in the sorted array, count its occurrences and calculate the total number of elements within the valid range.
// 4. Update the result with the maximum frequency achievable by adding the minimum of numOperations and the difference between total elements in range and current frequency.
// 5. Additionally, consider the case where we can form a frequency using elements within [num - 2*k, num].
// 6. Return the maximum frequency found.

// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(1)

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        
        sort(nums.begin(),nums.end());

        int size=nums.size();

        int left=0;
        int right=left;
        int sumCount=0;
        int result=0;
        int left2=0;
        int sumCount2=0;
        int count=0;
        int prev=-1;

        for(auto num : nums)
        {
            if(num==prev)
            {
                count++;
            }
            else
            {
                prev=num;
                count=1;
            }

            while(nums[left]<num-k)
            {
                sumCount--;
                left++;
            }

            while(right<size&&nums[right]<=num+k)
            {
                sumCount++;
                right++;
            }
            result=max(result,count+min(sumCount-count,numOperations));

            sumCount2++;
            while(nums[left2]<num-2*k)
            {
                sumCount2--;
                left2++;
            }
            result=max(result,min(sumCount2,numOperations));
        }

        return result;
    }
};